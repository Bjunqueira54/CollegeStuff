package basic.tcp.server;

import java.io.*;
import java.net.*;

//Use this with BasicTCPClient

public class BasicTCPServer
{
    public static void main(String argv[]) throws IOException
    {
        String message;
        
        ServerSocket welcomeSocket = new ServerSocket(1337);
        
        BufferedReader inFromClient;
        DataOutputStream outToClient;

        while (true)
        {
            Socket clientSocket = welcomeSocket.accept();
            System.out.println("All gud");
            
            inFromClient = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            outToClient = new DataOutputStream(clientSocket.getOutputStream());
            
            System.out.println("Reading Message\n");
            message = inFromClient.readLine();
            System.out.println("Message from Client: " + message);
            
            outToClient.writeBytes("OK!" + '\n');
            
            clientSocket.close();
        }
    }
}