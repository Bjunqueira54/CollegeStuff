package ficha5_ex1;

public class Elevador
{
    Estado estado;
    
    public Elevador()
    {
        estado = new RC();
    }
    
    public Estado getEstado() { return estado; }
    
    public boolean goUp()
    {
        if(estado.canGoUp())
        {
            estado = estado.goUp();
            return true;
        }
        
        return false;
    }
    
    public boolean goDown()
    {
        if(estado.canGoDown())
        {
            estado = estado.goDown();
            return true;
        }
        
        return false;
    }
}