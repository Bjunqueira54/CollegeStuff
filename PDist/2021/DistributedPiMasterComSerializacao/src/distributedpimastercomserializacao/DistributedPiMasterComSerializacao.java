package distributedpimastercomserializacao;

import java.io.*;
import java.net.*;
import java.util.*;

public class DistributedPiMasterComSerializacao
{
    static final int TIMEOUT = 10000;
    static final int REGISTER_TIMEOUT = 1000;
    static final int UDP_PORT = 5001;
   
    private static int getWorkers(List<Socket> workers)
    {

        ServerSocket ss = null;
        DatagramSocket ds = null;
        Socket toClientSocket;
        
        DatagramPacket dpkt;
        ByteArrayOutputStream bout;
        ObjectOutputStream oout;        

        workers.clear();
        
        try
        {
            /* Cria um server socket num porto aleatorio */
            ss = new ServerSocket();
            ss.setSoTimeout(REGISTER_TIMEOUT);
            
            /**
             * Transmite esse porto sob a forma de um objecto serializado do tipo Integer
             * por difus�o (endereco 255.255.255.255) para o porto definido por UDP_PORT. 
             */
             
            bout = new ByteArrayOutputStream();
            oout = new ObjectOutputStream(bout);
            oout.writeObject(ss.getLocalPort());
            
            dpkt = new DatagramPacket(bout.toByteArray(), bout.size(), InetAddress.getByName("255.255.255.255"), UDP_PORT);
            ds = new DatagramSocket();            
            /*...*/
            
            System.out.println("> A aguardar pedidos de ligacao no porto TCP " + ss.getLocalPort());                            
                
            try
            {
                while(true)
                {
                    /**
                     * Aguarda pelo estabelecimento de ligacoes e acrescenta-as 'a lista workers.
                     */
                    
                    toClientSocket = ss.accept();
                    workers.add(toClientSocket);

                    System.out.print("> Estabelecida ligacao com o worker " + workers.size());
                    System.out.print(" [" + toClientSocket.getInetAddress().getHostName() + ":");
                    System.out.println(toClientSocket.getPort()+"]");    
                }
            }
            catch(SocketTimeoutException e){}
        }
        catch(IOException e)
        {
            System.err.println(); System.err.println(e);
            try
            {
                /**
                 * Caso ocorra um excepcao, fecha todos os sockets em workers e 
                 * esvazia a lista.
                 */
                
                for(Socket sit: workers)
                    sit.close();
            }
            catch(IOException ee){}
        }
        finally
        {
            try
            {
                if(ss!=null) ss.close();
                if(ds!=null) ds.close();
            }
            catch(IOException e){}
        }
        return workers.size();
    }
    
    public static void main(String[] args) throws InterruptedException
    {
        long nIntervals;
               
        List<Socket> workers  = new ArrayList<Socket>();
        ObjectOutputStream output;
        ObjectInputStream input;
        
        int i, nWorkers = 0;
        double workerResult;
        double pi = 0;
        
        Calendar t1, t2;
        
        System.out.println();
        			
        if(args.length != 1)
        {
            System.out.println("Sintaxe: java ParallelPi <numero de intervalos>");
            return;
        }
        
        nIntervals = Long.parseLong(args[0]);
        
        t1 = GregorianCalendar.getInstance();                
        nWorkers = getWorkers(workers);
        
        System.out.println("Numero de workers: " + nWorkers);
        
        if(nWorkers <= 0)
            return;
        
        try
        {
            for(i=0; i<nWorkers; i++)
            {
                output = new ObjectOutputStream(workers.get(i).getOutputStream());
                output.writeObject(new RequestToWorker(i+1, nWorkers, nIntervals));
                output.flush();               
            }

            System.out.println();
			
            for(i=0; i<nWorkers; i++)
            {
                input = new ObjectInputStream(workers.get(i).getInputStream());
                workerResult = ((Double)input.readObject()).doubleValue();
                System.out.println("> Worker " + (i+1) + ": " + workerResult);
                pi += workerResult;
            }
            
        }
        catch(IOException e)
        {
            System.err.println("Erro ao aceder ao socket\n\t" + e);            
        }
        catch(ClassNotFoundException e)
        {
            System.err.println("Recebido objecto de tipo inesperado\n\t" + e);
        }
        finally
        {
            for(i=0; i<nWorkers; i++)
            {
                try
                {
                    workers.get(i).close();
                }
                catch(IOException e){}
            }
        }

        t2 = GregorianCalendar.getInstance();

        System.out.println();
        System.out.println(">> Valor aproximado do pi: " + pi + " (calculado em " + 
                (t2.getTimeInMillis() - t1.getTimeInMillis()) + " msec.)");
    }
}