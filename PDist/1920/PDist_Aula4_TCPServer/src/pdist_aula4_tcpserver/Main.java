package pdist_aula4_tcpserver;

import java.io.*;
import java.net.*;
import java.util.Scanner;

class Main extends Thread
{
    public static final int MAX_SIZE = 4000;
    public static final int TIMEOUT = 5;
    
    private final Socket socketToClient;
    private final File localDirectory;
    
    public Main(Socket s, File f)
    {
        socketToClient = s;
        localDirectory = f;
    }
    
    @Override
    public void run()
    {   
        int listeningPort = 1337;
        ServerSocket socket;
        
        BufferedReader in;
        OutputStream out;
        String requestedFileName, requestedCanonicalFilePath = null;
        FileInputStream requestedFileInputStream = null;
        
        byte fileChunk[] = new byte[MAX_SIZE];
        int nBytes;
        
        try
        {
            socketToClient.setSoTimeout(TIMEOUT*1000);
            
            in = new BufferedReader(new InputStreamReader(socketToClient.getInputStream()));
            out = socketToClient.getOutputStream();
            
            requestedFileName = in.readLine();
            
            System.out.println(this.getName()+"Recebido pedido para "+requestedFileName+" de "+socketToClient.getPort());
            
            requestedCanonicalFilePath = new File(localDirectory+File.separator+requestedFileName).getCanonicalPath();
            
            if(!requestedCanonicalFilePath.startsWith(requestedFileName))
            
            
            
            
            
            
            
            
            //listeningPort = Integer.parseInt(args[0]);
            
            if(listeningPort <= 0)
                throw new NumberFormatException();
            
            socket = new ServerSocket(listeningPort);
            
            while(true)
            {
                socketToClient = socket.accept();
                new Main(socketToClient, localDirectory).start();
            }
        }
        catch(IOException ex) {}
        catch(NumberFormatException ex) {}
        finally
        {
            try
            {
                
            }
        }
    }
        
    public static void main(String argv[]) throws IOException
    {
        File localDirectory;
        int listeningPort;
        ServerSocket socket = null;
        String filename;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("What's the filename?");
        filename = sc.next();
        System.out.println("What port do you want to run this on?");
        listeningPort = sc.nextInt();
        
        try
        {
            localDirectory = new File(filename.trim());
        }

    }
}