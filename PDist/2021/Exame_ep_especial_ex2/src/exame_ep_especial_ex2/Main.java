package exame_ep_especial_ex2;

import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.List;

interface MRClientInterface
{
    public void postMessage(String str) throws RemoteException;
}

interface MRInterface extends Remote
{
    public boolean registerClient (MRClientInterface cliRef) throws RemoteException;
    public boolean unregisterClient (MRClientInterface cliRef) throws RemoteException;
    public void broadcastMessage(String msg) throws RemoteException;
    public int getNumRegisteredClients() throws RemoteException;
}

class MessageReflector extends UnicastRemoteObject implements MRInterface
{
    List<MRClientInterface> clientList = new ArrayList<>();
    
    public MessageReflector() throws RemoteException
    {
        
    }
    
    @Override
    public synchronized boolean registerClient(MRClientInterface cliRef) throws RemoteException
    {
        if(clientList.contains(cliRef))
            return false;
        
        return clientList.add(cliRef);
    }
    
    @Override
    public synchronized boolean unregisterClient(MRClientInterface cliRef) throws RemoteException { return clientList.remove(cliRef); }

    @Override
    public void broadcastMessage(String msg) throws RemoteException
    {
        for(int i = 0; i < clientList.size(); i++)
        {
            try
            {
                clientList.get(i).postMessage(msg);
            }
            catch(RemoteException e)
            {
                clientList.remove(i--);
            }
        }
    }
    
    @Override
    public int getNumRegisteredClients() throws RemoteException { return clientList.size(); }
}

public class Main
{
    public static void main(String[] args)
    {
        
    }
}