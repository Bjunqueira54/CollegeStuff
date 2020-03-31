package basic.udp.server;

import java.io.IOException;
import java.net.*;

//Use this with BasicUDPClient

public class BasicUDPServer
{
    public static void main(String[] args) throws SocketException, IOException
    {
        DatagramSocket serversocket = new DatagramSocket(1337);
        byte recieveData[] = new byte[1024];
        DatagramPacket inFromClient = new DatagramPacket(recieveData, recieveData.length);
        
        serversocket.receive(inFromClient);
        
        String sentence = new String(inFromClient.getData());
        String clientAddr = inFromClient.getAddress().getCanonicalHostName();
        int clientPort = inFromClient.getPort();
        
        System.out.println("Client: " + clientAddr + "\nPort: " + clientPort + "\nMessage: " + sentence);
    }
}