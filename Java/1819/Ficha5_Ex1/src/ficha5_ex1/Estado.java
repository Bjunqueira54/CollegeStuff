package ficha5_ex1;

public interface Estado
{
    public Estado goUp();
    public Estado goDown();
    
    public boolean canGoUp();
    public boolean canGoDown();
}