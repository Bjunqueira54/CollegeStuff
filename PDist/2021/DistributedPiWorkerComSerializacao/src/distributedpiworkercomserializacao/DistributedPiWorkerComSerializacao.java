package distributedpiworkercomserializacao;

import java.io.*;
import java.net.*;

public class DistributedPiWorkerComSerializacao implements Runnable
{
    static final int TIMEOUT = 60000;
    static final int UDP_PORT = 5001;
    static final int BUFFER_SIZE = 500;
        
    protected Socket s;
    protected ObjectInputStream in;
    protected ObjectOutputStream out;
    
    public DistributedPiWorkerComSerializacao(Socket s)
    {
        this.s= s;
        in = null;
        out = null;
    }
    
    public double getMyResult(int myId, int nWorkers, long nIntervals)
    {
        long i;
        double dX, xi, myResult;
        
        if(nIntervals < 1 || nWorkers < 1 || myId <1 || myId > nWorkers)
            return 0.0;
        
        
        dX = 1.0/nIntervals;
        myResult = 0;
        
        for (i = myId-1 ; i < nIntervals; i += nWorkers)
        {
            xi = dX*(i + 0.5);
            myResult += (4.0/(1.0 + xi*xi));               
        }
        
        myResult *= dX;
        
        return myResult;
    }
    
    @Override
    public void run()
    {
        int myId;
        int nWorkers;
        long nIntervals;
        double myResult;
        CommonPackage.RequestToWorker req;
        
        try
        {
            s.setSoTimeout(TIMEOUT);
            in = new ObjectInputStream(s.getInputStream());
            out = new ObjectOutputStream(s.getOutputStream());
                        
            try
            {
                req = (RequestToWorker)in.readObject();
                
                myId = req.getId();
                nWorkers = req.getnWorkers();
                nIntervals = req.getnIntervals();
                
                System.out.println("<" + Thread.currentThread().getName() + 
                    "> New request received - myId: " + myId + " nWorkers: " + nWorkers + " nIntervals: " + nIntervals);
             }
            catch(ClassNotFoundException e)
             {
                System.err.println("<" + Thread.currentThread().getName() + 
                    ">: " + e);             
                return;
            }
            
            myResult = getMyResult(myId, nWorkers, nIntervals);
            
            out.writeObject(myResult);
            out.flush();
            
            System.out.format("<%s> %.10f\n", Thread.currentThread().getName(), myResult);
            
        }
        catch(IOException e)
        {
            System.out.println("<" + Thread.currentThread().getName() + 
                    "> Erro ao aceder ao socket:\n\t" + e);
        }
        finally
        {
            try
            {
                if(s != null) s.close();
            }
            catch(IOException e){}            
        }
    }

    public static void main(String[] args)
    {
        DatagramSocket ds = null;
        Socket toMaster = null;
        
        DatagramPacket dpkt;
        ObjectInputStream oin;
        
        int tcpPortNumber;
                
        Thread t;
        int nCreatedThreads = 0;       
        
        try
        {
            /**
             * Cria um socket UDP associado ao porto UDP_PORT
             */
            
            ds = new DatagramSocket(UDP_PORT);
            
            while(true)
            {
                try
                {
                    /**
                     * Aguarda pela recepcao de um datagrama.
                     */
                    
                    dpkt = new DatagramPacket(new byte[BUFFER_SIZE], BUFFER_SIZE);
                    ds.receive(dpkt);
                }
                catch (IOException e)
                {
                    System.out.println("<DistributedPiWorker> " + e);
                    return;
                }
                
                try
                {
                    System.out.println("<DistributedPiWorker>: received packet from " + dpkt.getAddress().getHostAddress() + ":" + dpkt.getPort());

                    /**
                     * "Deserealiza" o objecto recebido assumindo que é um Integer serializado.
                     */
                    oin = new ObjectInputStream(new ByteArrayInputStream(dpkt.getData(), 0, dpkt.getLength()));
                    tcpPortNumber = (Integer) oin.readObject();

                    System.out.println("<DistributedPiWorker>: TCP port number is " + tcpPortNumber);

                    /**
                     * Estabelece uma ligacao TCP no porto indicado no endereco de onde vem 
                     * o datagrama UDP recebido.
                     */
                    toMaster = new Socket(ds.getInetAddress(), ds.getPort());

                    nCreatedThreads++;
                    t = new Thread(new DistributedPiWorkerComSerializacao(toMaster), "Thread "+nCreatedThreads);
                    t.start(); 
                    
                }
                catch(IOException | ClassNotFoundException e)
                {
                    System.out.println("<DistributedPiWorker> " + e);
                }  
            }
                    
        }
        catch (SocketException e)
        {
            System.out.println("<DistributedPiWorker> " + e);
        }
        finally
        {
            if(ds != null)
                ds.close();
        }
    }
}