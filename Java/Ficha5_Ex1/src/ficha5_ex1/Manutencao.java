package ficha5_ex1;

public class Manutencao implements Estado
{
    Estado oldEstado;
    
    public Manutencao(Estado estado)
    {
        oldEstado = estado;
    }

    @Override
    public Estado goUp() { return this; }

    @Override
    public Estado goDown() { return this; }

    @Override
    public boolean canGoUp() { return false; }

    @Override
    public boolean canGoDown() { return false; }
    
    public Estado insereCodigo() { return oldEstado; }
}
