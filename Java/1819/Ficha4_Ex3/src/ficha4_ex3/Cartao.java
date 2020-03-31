package ficha4_ex3;

import java.util.ArrayList;
import java.util.List;

public abstract class Cartao
{
    int numero;
    double saldo;
    
    List<Chamada> chamadas = new ArrayList<>();
    
    public Cartao(int numero)
    {
        this(numero, 0);
    }
    
    public Cartao(int numero, double saldo)
    {
        this.numero = numero;
        this.saldo = saldo;
    }
    
    public int getNumero() { return this.numero; }
    public double getSaldo() { return this.saldo; }
    public boolean temSaldo() { return (this.saldo > 0); }
    
    public void gastaSaldo(double custo)
    {
        if(custo < 0)
            return;
        if(temSaldo())
            this.saldo -= custo;
    }
    
    boolean RegistaChamada(Chamada chamada)
    {
        if(chamada == null) return false;
        if(!temSaldo()) return false;
        
        return chamadas.add(chamada);
    }
    
    public abstract boolean RegistaChamada(int NumeroDestino, int duracao);
    public abstract String getName();
    
    public void CarregaCartao(int saldo)
    {
        if(saldo < 0) return;
        
        this.saldo += saldo;
    }
    
    @Override
    public String toString()
    {
        return "Cartao numero=" + numero + ", saldo=" + saldo;
    }
    
    public String toStringDetalhado()
    {
        return "Cartao numero=" + this.numero + ", saldo=" + saldo + ", chamadas=" + this.chamadas;
    }
}