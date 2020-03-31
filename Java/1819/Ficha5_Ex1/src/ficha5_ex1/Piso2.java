package ficha5_ex1;

public class Piso2 implements Estado
{
    public Piso2() {}

    @Override
    public Estado goUp() { return this; }

    @Override
    public Estado goDown() { return new Piso1(); }

    @Override
    public boolean canGoUp() { return false; }

    @Override
    public boolean canGoDown() { return false; }
}