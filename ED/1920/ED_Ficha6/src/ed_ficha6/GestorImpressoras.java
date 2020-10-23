package ed_ficha6;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Set;

public class GestorImpressoras
{
    private HashMap<String, Impressora> hm = new HashMap<>();
    private PriorityQueue<Impressora> impressoras = new PriorityQueue<>(
            new Comparator<Impressora>()
            {
                @Override
                public int compare(Impressora o1, Impressora o2)
                {
                    return (o1.getNumeroTrabalhos() - o2.getNumeroTrabalhos());
                }
            });
    
    public GestorImpressoras() {}
    
    public Impressora getPrinter(String nome)
    {
        return (Impressora) hm.get(nome);
    }
    
    public Set<String> getNomes() { return hm.keySet(); }
    
    public void adicionaImpressora(Impressora impressora)
    {
        hm.put(impressora.getNome(), impressora);
        impressoras.add(impressora);
    }
    
    public void removeImpressora(String nome) { hm.remove(nome); }
    
    public boolean existeImpressora(String nome)
    {
        if(hm.get(nome) != null)
            return true;
        else
            return false;
    }
    
    public void mostraFila()
    {
        Iterator it = impressoras.iterator();
        Impressora aux;
        
        while(it.hasNext())
        {
            aux = (Impressora) it.next();
            aux.show();
        }
    }
    
    public void imprime(Trabalho trabalho)
    {
        Impressora aux = impressoras.remove();
        
        aux.enviaTrabalho(trabalho);
        
        impressoras.add(aux);
    }
}