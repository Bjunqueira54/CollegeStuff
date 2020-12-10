import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;

public class Main
{
    public static void main(String[] args)
    {
        try
        {
            Remote remoteService = Naming.lookup("rmi://localhost/timeserver");
            
            RemoteTimeInterface rti = (RemoteTimeInterface) remoteService;
            
            Hora h;
            
            h = rti.getHora();
            
            System.out.println(h.getHora() + ":" + h.getMinutos() + ":" + h.getSegundos());
        }
        catch (MalformedURLException e) {}
        catch (NotBoundException e) {}
        catch (RemoteException e) {}
    }
}