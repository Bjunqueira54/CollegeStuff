package ficha5_ex1;

public class RC implements Estado
{
    public RC() {}
    
    @Override
    public Estado goUp() { return new Piso1(); }
    
    @Override
    public Estado goDown() { return this; }
    
    @Override
    public boolean canGoUp() { return true; }

    @Override
    public boolean canGoDown() { return false; }    
}