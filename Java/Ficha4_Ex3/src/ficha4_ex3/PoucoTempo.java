package ficha4_ex3;

public class PoucoTempo extends Cartao
{
    static double CUSTO_MIN = 0.2;
    
    public PoucoTempo(int numero, double saldo)
    {
        super(numero, saldo);
    }
    
    @Override
    public boolean RegistaChamada(int numeroDestino, int duracao)
    {
        if(duracao < 0) return false;
        
        double custo = CUSTO_MIN * numMinutos(duracao);
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
