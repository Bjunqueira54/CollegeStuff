package ficha4_ex3;

public class Tagarela extends Cartao
{
    static double CUSTO_MIN_PRIM = 0.5;
    static double CUSTO_MIN_REST = 0.02;
    
    public Tagarela(int numero)
    {
        this(numero, 0.0);
    }
    
    private Tagarela(int numero, double saldo)
    {
        super(numero, saldo);
    }
    
    @Override
    public boolean RegistaChamada(int numeroDestino, int duracao)
    {
        if(duracao < 0) return false;
        double custo;
        
        custo = CUSTO_MIN_PRIM;
        
        if(duracao > 60)
        {
            custo += numMinutos(duracao-60) * 0.02;
        }
        
        Chamada chamada = new Chamada(numeroDestino, duracao, custo);
        
        return RegistaChamada(chamada);
    }
    
    double numMinutos(int duracao)
    {
        int n = duracao / 60;
        if((duracao % 60) > 0) n++;
        return n;
    }
    
    @Override
    public String getName() { return "Pouco Tempo"; }
}
