import java.rmi.Remote;
import java.rmi.RemoteException;

public interface RemoteTimeInterface extends Remote
{
    abstract public Hora getHora() throws RemoteException;
}
