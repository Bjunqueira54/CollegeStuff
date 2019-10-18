package javatcpclient;

import java.io.*;
import java.net.*;
import java.util.Scanner;

class Main
{
    public static void main(String argv[]) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        String message;
        
        String server_ip;
        int server_port;
        
        System.out.println("What's the server IP?");
        server_ip = sc.next();
        
        System.out.println("And the port?");
        server_port = sc.nextInt();
        
        Socket socket = new Socket(server_ip, server_port);
        
        if(socket.isConnected())
            System.out.println("all gud!");
        
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        DataOutputStream outToServer = new DataOutputStream(socket.getOutputStream());
        
        System.out.println("What's your message?");
        message = sc.next();
        
        System.out.println("Sending message!\n");
        
        outToServer.writeBytes(message + '\n');
        outToServer.flush();
        
        message = inFromServer.readLine();
        
        System.out.println("The server message is: " + message);
        
        socket.close();
    }
}