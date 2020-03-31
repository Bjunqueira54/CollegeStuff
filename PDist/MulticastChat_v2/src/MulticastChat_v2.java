/*Neste exemplo, a informacao e' trocada via um objecto
serializado que encapsula o "nickname" e a mensagem.*/
 
/*
   Multicast IPv4 em Mac OS
   Na lina de comando: -Djava.net.preferIPv4Stack=true
   No código: System.setProperty("java.net.preferIPv4Stack", "true");
*/


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
    public static final long serialVersionUID = 1010L;
    protected String nickname;
    protected String msg;
     
    public Msg(String nickname, String msg)
    {
        /*...*/
        
        this.msg = msg;
        this.nickname = nickname;
    }
     
    //public String getNickname(){ /*...*/ }
    public String getNickname() { return this.nickname; }
    
    //public String getMsg(){ /*...*/ }
    public String getMsg() { return this.msg; }
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
        DatagramPacket pkt;
        Msg msg;
        /*...*/
        ObjectInputStream objIn;
        /*...*/
         
        if(s == null || !running)
        {
            return;
        }
         
        try
        {
            while(running)
            {
                pkt = new DatagramPacket(new byte[MAX_SIZE], MAX_SIZE);
                s.receive(pkt);
                 
                try
                {
                    // "Deserializa" o objecto transportado no datagrama acabado de ser recebido
                    objIn = new ObjectInputStream(new ByteArrayInputStream(pkt.getData(), 0, pkt.getLength()));
                    Object o = objIn.readObject();
                    /*...*/
                     
                    System.out.println();
                    System.out.print("(" + pkt.getAddress().getHostAddress() + ":" + pkt.getPort() + ") ");
                     
                    //Caso o objecto recebido seja uma instancia de Msg...
                    if(o instanceof Msg)
                    {
                        msg = /*...*/ (Msg) o; /*...*/
                         
                        if(msg.getMsg().toUpperCase().contains(LIST))
                        {
                            //Envia o username 'a origem sob a forma de um objecto do tipo String
                            /*...*/
                            ByteArrayOutputStream baOut = new ByteArrayOutputStream();
                            ObjectOutputStream objOut = new ObjectOutputStream(baOut);
                            
                            objOut.writeObject(username);
                            objOut.flush();
                            //pkt = new DatagramPacket(baOut.toByteArray(), baOut.size());
                            pkt.setData(baOut.toByteArray());
                            pkt.setLength(baOut.toByteArray().length);
                            /*...*/
                             
                            s.send(pkt);
                            continue;
                        }
                        
                        //Mostra a mensagem recebida bem como a identificacao do emissor
                        System.out.println("Recebido \"" + /*...*/msg.getMsg()/*...*/ + "\" de " + /*...*/msg.getNickname()/*...*/);
                        
                    //Caso o objecto recebido seja uma instancia de String...
                    }
                    else if(/*...*/o instanceof String/*...*/)
                    {
                        //Mostra a String
                        System.out.println(/*...*/(String)o/*...*/);
                    }
                    System.out.println(); System.out.print("> ");
                }
                catch(ClassNotFoundException e)
                {
                    System.out.println();
                    System.out.println("Mensagem recebida de tipo inesperado!");
                    //continue;
                }
                catch(IOException e)
                {
                    System.out.println();
                    System.out.println("Impossibilidade de aceder ao conteudo da mensagem recebida!");
                    //continue;
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
        
        /*...*/ 
        ObjectOutputStream objOut;
        ByteArrayOutputStream baOut;
        /*...*/
         
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
                
                //Envia para o grupo de multicast e porto escolhidos uma instancia de Msg
                /*...*/
                baOut = new ByteArrayOutputStream();
                objOut = new ObjectOutputStream(baOut);
                
                objOut.writeObject(new Msg(args[0], msg));
                
                objOut.flush();
                dgram = new DatagramPacket(baOut.toByteArray(), baOut.toByteArray().length, group, port);
                /*...*/
                
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