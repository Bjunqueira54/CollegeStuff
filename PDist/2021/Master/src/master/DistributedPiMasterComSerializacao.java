package master;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.List;
import java.util.Scanner;

public class DistributedPiMasterComSerializacao
{
    /*
     * Le linhas do ficheiro fileName.
     * Em cada uma, a primeira palavra corresponde ao endereco de um worker e a segunda ao seu porto de escuta.
     * Se existir algum problema com a formatacao da linha, ignora-a.
     * Estabelece um ligacao TCP com o worker, colocando o respectivo socket em workers.
     * Se existir alguma problema na lingacao ao worker, ignora-o.
    */
    private static int getWorkers(String fileName, List<Socket> workers)
    {
        BufferedReader inFile = null;
        String workerCoord;
        String workerName;
        int workerPort;

        workers.clear();
        
        try
        {
            //Objecto para obter informacao sobre os workers a partir do ficheiro de texto com nome fileName 
            inFile = new BufferedReader(new FileReader(fileName));

            //Processa cada uma das linhas de texto do ficheiro
            while((workerCoord = inFile.readLine()) != null)
            {
                workerCoord = workerCoord.trim();
                if(workerCoord.length() == 0)
                    continue;
                
                try
                {
                    //Extrai as duas primeiras palavras da String workerCoord usando uma instancia de Scanner
                    Scanner sc = new Scanner(workerCoord);
                    workerName = sc.next();
                    workerPort = sc.nextInt();
                            
                }
                catch(Exception e)
                {
                    System.err.print("> Entrada incorrecta no ficheiro ");
                    System.err.println(fileName + ": \"" + workerCoord + "\"");
                    
                    //Omite as restantes instrucoes da iteraccao actual do ciclo while
                    return -1;
                }        
                
                System.out.print("> Estabelecendo ligacao com o worker " + (workers.size()+1));
                System.out.println(" [" + workerName + ":" + workerPort+"]... ");

                try
                {
                   /* Estabelece uma ligacao TCP como o worker e acrescenta o socket 'a lista de workers*/
                   workers.add(new Socket(InetAddress.getByName(workerName), workerPort));
                    
                    System.out.println("... ligacao estabelecida!");                    
                }
                catch(UnknownHostException e)
                {
                    System.err.println();
                    System.err.println("> Destino " + workerName + " desconhecido!");
                    System.err.println(); System.err.println(e); System.err.println();
                }
                catch(IOException e)
                {
                    System.out.println("> Impossibilidade de estabelecer ligacao!");
                    System.err.println(); System.err.println(e); System.err.println(); 
                }
            } //while
            
        }
        catch(FileNotFoundException e)
        {
            System.err.println();
            System.err.println("Impossibilidade de abrir o ficheiro: " + fileName + "\n\t" + e);
        }
        catch(IOException e)
        {
            System.err.println(); System.err.println(e);
        }
        finally
        {
            try
            {
                if(inFile != null)
                {
                    inFile.close();
                }                                       
            }
            catch(IOException e) {}
        }
        return workers.size();
    }
    
    public static void main(String[] args) throws InterruptedException
    {
        long nIntervals;
               
        List<Socket> workers  = new ArrayList<>();
        ObjectOutputStream output;
        ObjectInputStream input;
        
        int i, nWorkers = 0;
        double workerResult;
        double pi = 0;
        
        Calendar t1, t2;
        
        System.out.println();
        			
        if(args.length != 2)
        {
            System.out.println("Sintaxe: java ParallelPi <numero de intervalos> <ficheiro com os ip dos workers>");
            return;
        }
        
        nIntervals = Integer.parseInt(args[0]);
        
        t1 = GregorianCalendar.getInstance();     
        
        nWorkers = getWorkers(args[1], workers);
        
        if(nWorkers <= 0) return;
        
        try
        {
            for(i=0; i<nWorkers; i++)
            {
                output = new ObjectOutputStream(workers.get(i).getOutputStream()); //Cria um ObjectOutputStream associado ao socket relativo ao worker com indice i
                
                //Envia-lhe o pedido
                output.writeObject(new worker.RequestToWorker(i, nWorkers, nIntervals));
                output.flush();
            }

            System.out.println();
			
            for(i=0; i<nWorkers; i++)
            {
                input = new ObjectInputStream(workers.get(i).getInputStream()); //Cria um ObjectInputStream associado ao socket relativo ao worker com indice i
                
                //Obtem o valor retornado sob a forma de um Double serializado
                workerResult = (Double) input.readUnshared();
                
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
                    //Fecha o socket associado ao worker com indice i
                    workers.get(i).close();
                }
                catch(IOException e) {}
            }
        }

        t2 = GregorianCalendar.getInstance();

        System.out.println();
        System.out.println(">> Valor aproximado do pi: " + pi + " (calculado em " + 
                (t2.getTimeInMillis() - t1.getTimeInMillis()) + " msec.)");
        
    }
}