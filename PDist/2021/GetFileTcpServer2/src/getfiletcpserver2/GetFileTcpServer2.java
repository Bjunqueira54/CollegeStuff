import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

/**
 * @author Jose' Marinho
 */
public class GetFileTcpServer2
{

    public static final int MAX_SIZE = 4000;
    public static final int TIMEOUT = 5; //segundos
    
    public static void main(String[] args)
    {
        File localDirectory;
        
        int listeningPort;
        ServerSocket socket = null;
        
        Socket socketToClient;
        BufferedReader in;
        OutputStream out;        
        String requestedFileName, requestedCanonicalFilePath = null;
        FileInputStream requestedFileInputStream;
                
        byte []fileChunk = new byte[MAX_SIZE];
        int nbytes;
        
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

                try
                {
                    socketToClient.setSoTimeout(TIMEOUT*1000);

                    in = new BufferedReader(new InputStreamReader(socketToClient.getInputStream()));
                    out = socketToClient.getOutputStream();

                    requestedFileName = in.readLine();

                    System.out.println("Recebido pedido para \"" + requestedFileName + "\" de " + socketToClient.getInetAddress().getHostName() + ":" + socketToClient.getPort());

                    requestedCanonicalFilePath = new File(localDirectory+File.separator+requestedFileName).getCanonicalPath();

                    if(!requestedCanonicalFilePath.startsWith(localDirectory.getCanonicalPath()+File.separator))
                    {
                        System.out.println("Nao e' permitido aceder ao ficheiro " + requestedCanonicalFilePath + "!");
                        System.out.println("A directoria de base nao corresponde a " + localDirectory.getCanonicalPath()+"!");
                        continue;
                    }

                    requestedFileInputStream = new FileInputStream(requestedCanonicalFilePath);                

                    System.out.println("Ficheiro " + requestedCanonicalFilePath + " aberto para leitura.");

                    while((nbytes = requestedFileInputStream.read(fileChunk)) > 0)
                    {
                        out.write(fileChunk, 0, nbytes);                       
                    }     

                    System.out.println("Transferencia concluida");

                }catch(SocketException e)
                {
                    System.out.println("Ocorreu uma excepcao ao nivel do socket TCP de ligacao ao cliente:\n\t"+e);
                }catch(FileNotFoundException e)
                {
                    System.out.println("Ocorreu a excepcao {" + e + "} ao tentar abrir o ficheiro " + requestedCanonicalFilePath + "!");              
                }catch(IOException e)
                {
                    System.out.println("Ocorreu uma excepcao de E/S durante o atendimento ao cliente actual: \n\t" + e);
                }
                finally
                {
                    try
                    {
                        if(requestedFileInputStream!=null)
                        {
                            requestedFileInputStream.close();
                        }
                        socketToClient.close();                
                    }
                    catch(IOException e){}
                }                        
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