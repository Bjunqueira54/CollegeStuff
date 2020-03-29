package ficha5_ex1;

public class Piso1 implements Estado
{
    public Piso1() {}

    @Override
    public Estado goUp() { return new Piso2(); }

    @Override
    public Estado goDown() { return new RC(); }

    @Override
    public boolean canGoUp() { return true; }

    @Override
    public boolean canGoDown() { return false; }
}