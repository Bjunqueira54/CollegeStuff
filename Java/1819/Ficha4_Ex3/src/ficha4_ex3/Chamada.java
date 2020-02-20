package ficha4_ex3;

public class Chamada
{
    int numero;
    int duracao;
    double custo;
    
    public Chamada(int numero, int duracao, double custo)
    {
        this.numero = numero;
        this.duracao = duracao;
        this.custo = custo;
    }
    
    public int getNumeroDestino() { return this.numero; }
    public int getDuracao() { return this.duracao; }
    public double getCusto() { return this.custo; }

    @Override
    public String toString()
    {
        return "Chamada{" + "destino=" + numero + ", duracao=" + duracao + ", custo=" + custo + '}';
    }
    
    
}