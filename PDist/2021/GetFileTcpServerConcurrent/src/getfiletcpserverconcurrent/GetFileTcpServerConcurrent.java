package getfiletcpserverconcurrent;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class GetFileTcpServerConcurrent
{
    public static final int TIMEOUT = 5; //segundos
    public static final int MAX_SIZE = 4000;
    
    public static void main(String[] args)
    {
        File localDirectory;
        
        int listeningPort;
        ServerSocket socket = null;
        
        Socket socketToClient;
        FileInputStream requestedFileInputStream;
        
        if(args.length != 2)
        {
            System.out.println("Sintaxe: java GetFileUdpServer listeningPort localRootDirectory");
            return;
        }        
        
        try
        {
            localDirectory = new File(args[1].trim());

            if(!localDirectory.exists())
            {
               System.out.println("A directoria " + localDirectory + " nao existe!");
               return;
            }

            if(!localDirectory.isDirectory())
            {
                System.out.println("O caminho " + localDirectory + " nao se refere a uma directoria!");
                return;
            }

            if(!localDirectory.canRead())
            {
                System.out.println("Sem permissoes de leitura na directoria " + localDirectory + "!");
                return;
            }

            listeningPort = Integer.parseInt(args[0]);
            if(listeningPort <= 0) throw new NumberFormatException("Porto UDP de escuta indicado <= 0 (" + listeningPort + ")");

            socket = new ServerSocket(listeningPort);

            while(true)
            {
                requestedFileInputStream=null;

                socketToClient = socket.accept();
                
                Thread t = new Thread(new ProcessClientThread(socketToClient, localDirectory));
                
                t.setDaemon(true);
                t.start();
            }
        }
        catch(NumberFormatException e)
        {
            System.out.println("O porto de escuta deve ser um inteiro positivo:\n\t"+e);
        }
        catch(SocketException e)
        {
            System.out.println("Ocorreu uma excepcao ao nivel do socket TCP de escuta:\n\t"+e);
        }
        catch(IOException e)
        {
            System.out.println("Ocorreu uma excepcao de E/S: \n\t" + e);
        }
        finally
        {
            if(socket != null)
            {
                try
                {
                    socket.close();
                }
                catch(IOException e){}
            }
        }
    }
}