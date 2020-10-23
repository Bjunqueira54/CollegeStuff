package basic.udp.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;

//Use this with BasicUDPServer

public class BasicUDPClient
{
    public static void main(String[] args) throws IOException
    {
        DatagramSocket clientsocket = new DatagramSocket();
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Message for Server: ");
        String sentence = buffer.readLine();
        byte bytesToServer[] = sentence.getBytes();
        
        InetAddress address = InetAddress.getByName("localhost");
        
        DatagramPacket outToServer = new DatagramPacket(bytesToServer, bytesToServer.length, address, 1337);
        
        clientsocket.send(outToServer);
        
        clientsocket.close();
    }
}