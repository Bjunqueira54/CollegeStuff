package ficha4_ex3;

import java.util.HashMap;
import java.util.Map;

public class Operadora
{
    String nome;
    Map<Integer, Cartao> cartoes = new HashMap<>();
    
    public Operadora(String nome)
    {
        this.nome = nome;
    }
    
    public boolean AcrescentaCartao(Cartao cartao)
    {
        if(cartao == null) return false;
        if(cartoes.containsKey(cartao.getNumero())) return false;
        
        cartoes.put(cartao.getNumero(), cartao);
        return true;
    }
    
    public boolean fazChamada(int origem, int destino, int duracao) throws ExceptionNumeroInvalido
    {
        Cartao cartao = cartoes.get(origem);
        if(cartao == null) throw new ExceptionNumeroInvalido(origem);
        
        return cartao.RegistaChamada(destino, duracao);
    }
    
    public double getSaldo(int numero) throws ExceptionNumeroInvalido
    {
        Cartao cartao = cartoes.get(numero);
        if(cartao == null) throw new ExceptionNumeroInvalido(numero);
        
        return cartao.getSaldo();
    }
}