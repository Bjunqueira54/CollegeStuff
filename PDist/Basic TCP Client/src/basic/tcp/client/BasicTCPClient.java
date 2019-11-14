package basic.tcp.client;

import java.io.*;
import java.net.*;

//Use this with BasicTCPServer

public class BasicTCPClient
{
    public static void main(String argv[]) throws IOException
    {
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        String message;
        
        Socket socket = new Socket("localhost", 1337);
        
        if(socket.isConnected())
            System.out.println("all gud!");
        
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        DataOutputStream outToServer = new DataOutputStream(socket.getOutputStream());
        
        System.out.println("What's your message?");
        message = inFromUser.readLine();
        
        System.out.println("Sending message!\n");
        
        outToServer.writeBytes(message + '\n'); //Always send the '\n' or else server won't read it.
        outToServer.flush();
        
        message = inFromServer.readLine();
        
        System.out.println("The server message is: " + message);
        
        socket.close();
    }
}