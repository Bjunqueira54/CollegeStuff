package ficha4_ex3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
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
    
    public void CarregaCartao(int numero, int saldo) throws ExceptionNumeroInvalido
    {
        Cartao cartao = cartoes.get(numero);
        
        if(cartao == null) throw new ExceptionNumeroInvalido(numero);
        
        cartao.CarregaCartao(saldo);
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
    
    class OrdenaPorNumero implements Comparator<Cartao>
    {
        @Override
        public int compare(Cartao o1, Cartao o2)
        {
            if(o1.getNumero() < o2.getNumero()) return -1;
            if(o1.getNumero() > o2.getNumero()) return 1;
            
            return 0;
        }
    }
    
    public List<Cartao> getCartoesOrderByNumero()
    {
        List<Cartao> lista = new ArrayList(cartoes.values());
        Collections.sort(lista, new OrdenaPorNumero());
        
        return lista;
    }
}