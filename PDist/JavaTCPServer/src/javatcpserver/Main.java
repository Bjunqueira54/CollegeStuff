package javatcpserver;

import java.io.*;
import java.net.*;
import java.util.Scanner;

class Main
{
    public static void main(String argv[]) throws IOException
    {
        String message;
        Scanner sc = new Scanner(System.in);
        
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
            
            System.out.println("Send a message back to the client: ");
            message = sc.next();
            
            outToClient.writeBytes(message + '\n');
            
            clientSocket.close();
        }
    }
}