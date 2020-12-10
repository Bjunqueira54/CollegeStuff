import java.io.Serializable;

public class Hora implements Serializable
{
    static final long serialVersionUID = 1L;
    
    protected int horas = 0;
    protected int minutos = 0;
    protected int segundos = 0;
    
    public Hora(int h, int m, int s)
    {
        this.horas = h;
        this.minutos = m;
        this.segundos = s;
    }
    
    public int getHora() { return this.horas; }
    public int getMinutos() { return this.minutos; }
    public int getSegundos() { return this.segundos; }

    @Override
    public String toString()
    {
        return "Hora{hours:" + this.horas + ", minutes:" + this.minutos + ", seconds:" + this.segundos + "}";
    }
}