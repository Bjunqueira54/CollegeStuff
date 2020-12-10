package tcpserver;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer
{
    public static final int MAX_SIZE = 256;
    public static final String TIME_REQUEST = "TIME";
    
    public static void main(String args[])
    {
        ServerSocket socket;
        int listeningPort;
        socket = null;
        Socket toClientSocket;
        String request;
        ObjectInputStream oin = null;
        ObjectOutputStream oout = null;
        
        try
        {
            listeningPort = Integer.parseInt("1337");
            socket = new ServerSocket(listeningPort);

            System.out.println("TCP Time Server iniciado no porto " + socket.getLocalPort() + " ...");

            while(true)
            {
                toClientSocket = socket.accept();        

                try
                {
                    oin = new ObjectInputStream(toClientSocket.getInputStream());
                    oout = new ObjectOutputStream(toClientSocket.getOutputStream());
                    
                    request = (String) oin.readObject();

                    if(request == null) //EOF
                        continue; //to next client request

                    System.out.println("Recebido \"" + request.trim() + "\" de " + 
                            toClientSocket.getInetAddress().getHostAddress() + ":" + 
                            toClientSocket.getPort());

                    if(!request.equalsIgnoreCase(TIME_REQUEST))
                    {
                        System.out.println("Unexpected request");
                        continue;
                    }

                    //Envia a resposta ao cliente
                    oout.writeObject(new Time(12, 15, 34));
                    oout.flush();

                }
                catch(IOException e)
                {
                    System.out.println("Erro na comunicacao com o cliente " + 
                            toClientSocket.getInetAddress().getHostAddress() + ":" + 
                                toClientSocket.getPort()+"\n\t" + e);
                }
                finally
                {
                    try
                    {
                        toClientSocket.close();
                    }
                    catch(IOException e){}
                }
            }
            
        }
        catch(NumberFormatException e)
        {
            System.out.println("O porto de escuta deve ser um inteiro positivo.");
        }
        catch(IOException e)
        {
            System.out.println("Ocorreu um erro ao nivel do socket de escuta:\n\t"+e);
        }
        catch(ClassNotFoundException e)
        {
            System.out.println("Ocorreu um erro ao fazer cast de classes");
        }
        finally
        {
            if(socket!=null)
            {
                try
                {
                    socket.close();
                }
                catch (IOException ex) {}
            }
        }
    }
}