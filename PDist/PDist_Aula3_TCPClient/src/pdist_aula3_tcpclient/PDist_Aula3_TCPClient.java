package pdist_aula3_tcpclient;

import java.net.*;
import java.io.*;
import java.util.*;
 
public class PDist_Aula3_TCPClient
{
 
    public static final int MAX_SIZE = 8096*8;
    public static final String TIME_REQUEST = "TIME";
    public static final int TIMEOUT = 10; //segundos
 
    public static void main(String[] args) throws IOException
    {
        InetAddress serverAddr = null;
        int serverPort = -1;
        Socket socket = null;
        ObjectInputStream in = null;
        ObjectOutputStream out = null;
        Calendar response;
        
        ByteArrayOutputStream bOut = null;
        
        /*if(args.length != 2)
        {
            System.out.println("Sintaxe: java TcpTimeClient serverAddress serverUdpPort");
            return;
        }*/
        
        String server_ip, server_port;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("What's the server IP?");
        server_ip = sc.next();
        
        System.out.println("And the Port?");
        server_port = sc.next();

        try
        {
            serverAddr = InetAddress.getByName(server_ip);
            serverPort = Integer.parseInt(server_port);
            socket = new Socket(serverAddr, serverPort);
            socket.setSoTimeout(TIMEOUT*1000);
             
            in = new ObjectInputStream(socket.getInputStream());
            out = new ObjectOutputStream(socket.getOutputStream());
            
            out.writeObject(TIME_REQUEST);
            out.flush();
            
            //A resposta deve terminar com uma mundanca de linha.
            //Os caracteres de mudanca de linha nao sao copiados para "response"
            response = (Calendar) in.readObject();
             
            if(response == null)
            {
                System.out.println("O servidor nao enviou qualquer resposta antes de fechar a ligacao TCP!");   
            }
            else
            {
                System.out.println("Hora indicada pelo servidor: " +
                        response.get(GregorianCalendar.HOUR_OF_DAY)+":"+
                        response.get(GregorianCalendar.MINUTE)+":"+
                        response.get(GregorianCalendar.SECOND));
 
                //******************************************************************
                //Exemplo de como retirar os valores da mensagem
                /*try
                {
                    StringTokenizer tokens = new StringTokenizer(response," :");
 
                    int hour = Integer.parseInt(tokens.nextToken().trim());
                    int minute = Integer.parseInt(tokens.nextToken().trim());
                    int second = Integer.parseInt(tokens.nextToken().trim());
 
                    System.out.println("Horas: " + hour + " ; Minutos: " + minute + " ; Segundos: " + second);
                }
                catch(NumberFormatException e) {}*/
                //******************************************************************
            }
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
            System.out.println("Não foi recebida qualquer resposta:\n\t"+e);
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