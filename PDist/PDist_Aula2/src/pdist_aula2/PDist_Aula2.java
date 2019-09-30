package pdist_aula2;

import java.net.InetAddress;
import java.net.*;
import java.io.*;
import java.util.Scanner;

public class PDist_Aula2
{
    public static void main (String args[])
    {
        Scanner sc = new Scanner(System.in);
        String msg;
        
        try
        {
            DatagramSocket sock = new DatagramSocket();
            
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            PrintStream ps = new PrintStream(baos);
            
            System.out.println("Send a message: ");
            msg = sc.nextLine();
            
            ps.print(msg);
            
            byte[] barray = baos.toByteArray();
            
            DatagramPacket packet = new DatagramPacket(barray, barray.length);
            
            //InetAddress addr = InetAddress.getByName(hostname);
            InetAddress addr = InetAddress.getLocalHost();
            
            packet.setAddress(addr);
            packet.setPort(6001);
            
            sock.send(packet);
        }
        catch(UnknownHostException ex)
        {
            System.out.println("Error - Unknown Host");
        }
        catch(IOException ex)
        {
            System.out.println("Error - IO Error");
        }
    }
}