package javatcpclient;

import java.io.*;
import java.net.*;

class Main
{
    public static void main(String argv[]) throws Exception
    {
        String sentence;
        String modifiedSentence;
        
        DataInputStream inFromUser = new DataInputStream(System.in);
        Socket clientSocket = new Socket("127.0.0.1", 1337);
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        //BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        DataInputStream inFromServer = new DataInputStream(clientSocket.getInputStream());
        
        sentence = inFromUser.readUTF();
        outToServer.writeBytes(sentence + 'n');
        outToServer.flush();
        
        modifiedSentence = inFromServer.readUTF();
        System.out.println("FROM SERVER: " + modifiedSentence);
        
        clientSocket.close();
    }
}