package getfiletcpserverconcurrent;

import static getfiletcpserverconcurrent.GetFileTcpServerConcurrent.MAX_SIZE;
import static getfiletcpserverconcurrent.GetFileTcpServerConcurrent.TIMEOUT;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;
import java.net.SocketException;

public class ProcessClientThread implements Runnable
{
    //public static final int MAX_SIZE = 4000;
    
    private final Socket socketToClient;
    private BufferedReader in;
    private OutputStream out;        
    private String requestedFileName, requestedCanonicalFilePath = null;
    private FileInputStream requestedFileInputStream;
    private final File localDirectory;

    private final byte []fileChunk = new byte[MAX_SIZE];
    private int nbytes;
    
    public ProcessClientThread(Socket s, File ld)
    {
        this.socketToClient = s;
        this.localDirectory = ld;
    }
    
    @Override
    public void run()
    {
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
                return;
            }

            requestedFileInputStream = new FileInputStream(requestedCanonicalFilePath);                

            System.out.println("Ficheiro " + requestedCanonicalFilePath + " aberto para leitura.");

            while((nbytes = requestedFileInputStream.read(fileChunk)) > 0)
            {
                out.write(fileChunk, 0, nbytes);                       
            }     

            System.out.println("Transferencia concluida");

        }
        catch(SocketException e)
        {
            System.out.println("Ocorreu uma excepcao ao nivel do socket TCP de ligacao ao cliente:\n\t"+e);
        }
        catch(FileNotFoundException e)
        {
            System.out.println("Ocorreu a excepcao {" + e + "} ao tentar abrir o ficheiro " + requestedCanonicalFilePath + "!");              
        }
        catch(IOException e)
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