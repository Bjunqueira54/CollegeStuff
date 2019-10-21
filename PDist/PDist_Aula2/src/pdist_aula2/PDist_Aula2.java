package pdist_aula2;

import java.net.*;
import java.io.*;
import java.util.*;
 
public class PDist_Aula2
{
 
    public static final int MAX_SIZE = 1000000;
    public static final String TIME_REQUEST = "TIME";
    public static final int TIMEOUT = 10; //segundos
 
    public static void main(String[] args) 
    {
         
        InetAddress serverAddr = null;
        int serverPort = -1;
        DatagramSocket socket = null;
        DatagramPacket packet = null;
        
        ByteArrayOutputStream bOut = null;
        ObjectOutputStream out = null;
        ObjectInputStream in = null;
        
        Calendar time = null;
         
        /*if(args.length != 2)
        {
            System.out.println("Sintaxe: java UdpTimeClient serverAddress serverUdpPort");
            return;
        }*/
 
        try
        {
            String server_ip;
            String server_port;
            Scanner sc = new Scanner(System.in);
            
            System.out.println("What's the IP?");
            server_ip = sc.next();
            
            System.out.println("And the Port?");
            server_port = sc.next();
            
            serverAddr = InetAddress.getByName(server_ip);
            serverPort = Integer.parseInt(server_port);   
            socket = new DatagramSocket();
            socket.setSoTimeout(TIMEOUT*1000);
             
            bOut = new ByteArrayOutputStream();
            out = new ObjectOutputStream(bOut);
            
            out.writeObject(TIME_REQUEST);
            out.flush();
            
            packet = new DatagramPacket(bOut.toByteArray(), bOut.size(), serverAddr, serverPort);
            socket.send(packet);
             
            packet = new DatagramPacket(new byte[MAX_SIZE], MAX_SIZE);
            socket.receive(packet);
             
            //System.out.println("Hora indicada pelo servidor: " + new String(packet.getData(), 0, packet.getLength()));
             
            in = new ObjectInputStream(new ByteArrayInputStream(packet.getData(), 0, packet.getLength()));
            time = (Calendar) in.readObject();
            
            System.out.println("Horas:" + time.get(GregorianCalendar.HOUR_OF_DAY) +
                                "\nMinutos: " + time.get(GregorianCalendar.MINUTE) +
                                "\nSegundos: " + time.get(GregorianCalendar.SECOND));
            
            //******************************************************************
            //Exemplo de como retirar os valores da mensagem
            try
            {
                StringTokenizer tokens = new StringTokenizer(new String(packet.getData(), 0, packet.getData().length)," :");
                         
                int hour = Integer.parseInt(tokens.nextToken().trim());
                int minute = Integer.parseInt(tokens.nextToken().trim());
                int second = Integer.parseInt(tokens.nextToken().trim());
             
                System.out.println("Horas: " + hour + " ; Minutos: " + minute + " ; Segundos: " + second);
            }
            catch(NumberFormatException e) {}
            
            //******************************************************************
        }
        catch(UnknownHostException e)
        {
             System.out.println("Destino desconhecido:\n\t"+e);
        }
        catch(NumberFormatException e)
        {
            System.out.println("O porto do servidor deve ser um inteiro positivo.");
        }
        catch(SocketTimeoutException e)
        {
            System.out.println("Nao foi recebida qualquer resposta:\n\t"+e);
        }
        catch(SocketException e)
        {
            System.out.println("Ocorreu um erro ao nivel do socket UDP:\n\t"+e);
        }
        catch(IOException e)
        {
            System.out.println("Ocorreu um erro no acesso ao socket:\n\t"+e);
        }
        catch(ClassNotFoundException ex) {}
        finally
        {
            if(socket != null)
            {
                socket.close();
            }
        }
    }
}