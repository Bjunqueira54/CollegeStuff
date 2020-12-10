package multicastchat_v2;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.net.UnknownHostException;

class Msg implements Serializable
{
    /* Definir o identificador de versao de uma classe serializavel evita problemas de 
     * incompatibilidade que podem surgir quando se obtem instancias serializadas
     * dessa classe. O numero, do tipo long, e' arbitrario */
    static final long serialVersionUID = 1010L;

    protected String nickname;
    protected String msg;

    public Msg(String nickname, String msg)
    {
            this.nickname = nickname;
            this.msg = msg;
    }

    public String getNickname(){ return nickname;}

    public String getMsg(){ return msg;}	
        
}

public class MulticastChat_v2 extends Thread
{
    public static final String LIST = "LIST";
    public static String EXIT = "EXIT";
    public static int MAX_SIZE = 1000;
    
    protected String username;
    protected MulticastSocket s;
    protected boolean running;

    public MulticastChat_v2(String username, MulticastSocket s) 
    {
        this.username = username;
        this.s = s;
        running = true;
    }
    
    public void terminate()
    {                
        running = false;
    }
            
    @Override
    public void run()
    {
        ObjectInputStream in;
        Object obj;
        DatagramPacket pkt;
        Msg msg;
        ByteArrayOutputStream buff;
        ObjectOutputStream out;   
        
        if(s == null || !running)
        {
            return;
        }
        
        try{
            
            while(running)
            {
                pkt = new DatagramPacket(new byte[MAX_SIZE], MAX_SIZE);
                s.receive(pkt);
                
                try
                {
                    in = new ObjectInputStream(new ByteArrayInputStream(pkt.getData(), 0, pkt.getLength()));
                               
                    obj = in.readObject();
                    in.close(); 
                                       
                    if(obj instanceof Msg)
                    {
                        msg = (Msg)obj;
                        
                        if(msg.getMsg().toUpperCase().contains(LIST.toUpperCase()))
                        {
                            buff = new ByteArrayOutputStream();
                            out = new ObjectOutputStream(buff);                
                            out.writeObject(username);
                            out.flush(); out.close();

                            pkt.setData(buff.toByteArray());
                            pkt.setLength(buff.size());
                            s.send(pkt); 
                            //System.out.println("Sent: " + pkt.getAddress().getHostAddress() + ":" + pkt.getPort());
                            continue;
                        }
                        
                        System.out.println();
                        System.out.print("(" + pkt.getAddress().getHostAddress() + ":" + pkt.getPort() + ") ");
                        System.out.println(msg.getNickname() + ": " + msg.getMsg() + " ("+msg.getClass()+")");
                         
                    }
                    else if(obj instanceof String)
                    {
                        
                        System.out.println((String)obj + " ("+obj.getClass()+")");
                    }
                    
                    System.out.println(); System.out.print("> ");
                                          
                }
                catch(ClassNotFoundException e)
                {
                    
                    System.out.println();
                    System.out.println("Mensagem recebida de tipo inesperado! " + e);
                    //continue;
                    
                }
                catch(IOException e)
                {
                    
                    System.out.println();
                    System.out.println("Impossibilidade de aceder ao conteudo da mensagem recebida! " + e);
                    //continue;
                    
                }
                catch(Exception e)
                {
                    System.out.println();
                    System.out.println("Excepcao: " + e);
                }
                
            }
            
        }
        catch(IOException e)
        {
            if(running)
            {
                System.out.println(e);
            }
            
            if(!s.isClosed())
            {
                s.close();
            }
        }
    }
    
    public static void main(String[] args) throws UnknownHostException, IOException
    {
        InetAddress group;
        int port;
        MulticastSocket socket = null;
        DatagramPacket dgram;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String msg;
        ByteArrayOutputStream buff;
        ObjectOutputStream out;
        
        MulticastChat_v2 t = null;
        
        if(args.length != 4)
        {
            System.out.println("Sintaxe: java MulticastChat <nickname> <groupo multicast> <porto> <NIC multicast>");
            return;
        }
        
        try
        {
            group = InetAddress.getByName(args[1]);
            port = Integer.parseInt(args[2]);

            socket = new MulticastSocket(port);
            
            try
            {
                socket.setNetworkInterface(NetworkInterface.getByInetAddress(InetAddress.getByName(args[3])));
            }
            catch (SocketException | NullPointerException | UnknownHostException | SecurityException ex)
            {
                socket.setNetworkInterface(NetworkInterface.getByName(args[3])); //e.g., eth0, wlan0, en0
            }

            socket.joinGroup(group);
            
            t = new MulticastChat_v2(args[0], socket);
            //t.setDaemon(true);
            t.start();
            
            System.out.print("> ");
            
            while(true)
            {
                
                msg = in.readLine();
                
                if(msg.equalsIgnoreCase(EXIT))
                {
                    break;
                }
                
                buff = new ByteArrayOutputStream();
                out = new ObjectOutputStream(buff);                
                out.writeObject(new Msg(args[0], msg));
                out.flush(); out.close();
                                                    
                dgram = new DatagramPacket(buff.toByteArray(), buff.size(), group, port);
                socket.send(dgram);   
                
            }
            
        }
        finally
        {
            if(t != null)
            {
                t.terminate();
            }
            
            if(socket != null)
            {
                socket.close();
            }

            //t.join(); //Para esperar que a thread termine caso esteja em modo daemon
        }
    }
}