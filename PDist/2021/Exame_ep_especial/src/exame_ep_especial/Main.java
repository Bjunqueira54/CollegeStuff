package exame_ep_especial;

import java.io.*;
import java.net.*;

class Request
{
    private int udp_port;
    private String ip_address;
    
    public Request() {}
    
    public int getUdpPort() { return this.udp_port; }
    public String getIpAddress() { return this.ip_address; }
    public String getMsg() { return "N/A"; }
}

class Main
{
    void processRequest(Socket s) throws Exception
    {
        if(s == null)
            throw new NullPointerException("Null Socket Reference");
        
        DatagramSocket udp_socket = null;
        DatagramPacket udp_packet = null;
        ObjectInputStream ois = new ObjectInputStream(s.getInputStream());
        
        while (true)
        {
            try
            {
                /* Receive a serialized Request object */

                Request r = (Request) ois.readObject();

                /* Transmit the specified message to the specified IP address and UDP port. 
                The message is transmitted as a sequence of characters 
                (i.e., it is not transmitted as a serialized String object). */

                udp_socket = new DatagramSocket();
                udp_packet = new DatagramPacket(r.getMsg().getBytes(),
                                                r.getMsg().getBytes().length,
                                                InetAddress.getByName(r.getIpAddress()),
                                                r.getUdpPort());

                udp_socket.send(udp_packet);
            }
            catch(Exception e)
            {
                System.out.println(e.getMessage());
                throw e;
            }
            finally
            {
                try
                {
                        s.close();
                }
                catch(IOException e) {}
                
                if(udp_socket != null)
                    udp_socket.close();
            }
        }
    }

    public static void main(String[] args)
    {
        
    }
} 