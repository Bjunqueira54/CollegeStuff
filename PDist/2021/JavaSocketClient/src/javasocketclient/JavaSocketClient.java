package javasocketclient;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Scanner;

public class JavaSocketClient
{
    static final int TAM_BUFFER = 10000;
    static final int TIMEOUT = 10;  //seconds
    
    public static void main(String[] args)
    {
        DatagramSocket s = null;
        DatagramPacket pkt;
        
        FileOutputStream fout;
        
        String filename;
        String ip;
        int port;
        
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Filename?");
        filename = sc.next();
        
        System.out.println("IP?");
        ip = sc.next();
        
        System.out.println("Port?");
        port = sc.nextInt();
        
        try
        {
            fout = new FileOutputStream("copia-"+filename.trim());
            s = new DatagramSocket();
            s.setSoTimeout(TIMEOUT * 1000);
            pkt = new DatagramPacket(filename.getBytes(), filename.length(), InetAddress.getByName(ip), port);
            
            s.send(pkt);
            
            do
            {
                pkt = new DatagramPacket(new byte[TAM_BUFFER], TAM_BUFFER);
                s.receive(pkt);
                fout.write(pkt.getData(), 0, pkt.getLength());
            }
            while(pkt.getLength() > 0);
        }
        catch(SocketException e) {}
        catch(FileNotFoundException e) {}
        catch(IOException e) {}
        
    }
}