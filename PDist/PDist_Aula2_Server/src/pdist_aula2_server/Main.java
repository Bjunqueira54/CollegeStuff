package pdist_aula2_server;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class Main
{
    public static void main(String[] args)
    {
        try
        {
            DatagramSocket sock = new DatagramSocket(6001);
            DatagramPacket pack = new DatagramPacket(new byte[256], 256);
            
            sock.receive(pack);
            
            InetAddress addr = pack.getAddress();
            System.out.println("Sent by: " + addr.getHostAddress());
            System.out.println("Sent from Port: "+ pack.getPort());
            
            ByteArrayInputStream bin = new ByteArrayInputStream(pack.getData());
            int data;
            
            while(((data = bin.read()) != 1) && data != 0)
                System.out.print((char) data);
            
            sock.close();
        }
        catch(SocketException ex)
        {
            System.out.println("Error - Socket Error");
        }
        catch(IOException ex)
        {
            System.out.println("Error - IO Error");
        }
    }
}