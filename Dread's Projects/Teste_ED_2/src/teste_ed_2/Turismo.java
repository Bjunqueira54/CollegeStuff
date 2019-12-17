package teste_ed_2;

import java.util.Iterator;
import java.util.LinkedList;

public class Turismo
{
    private LinkedList<Rota> rotas;
    
    public Turismo()
    {
        rotas = new LinkedList<>();
    }
    
    public void defineRota(String nomeDaRota, String origem)
    {
        Rota r = new Rota(nomeDaRota, origem);
        
        rotas.add(r);
    }
    
    public void acrescentaPonto(String nomeDaRota, String ponto)
    {
        for(int i = 0; i < rotas.size(); i++)
        {
            Rota aux = rotas.get(i);
            
            if(aux.getName() == nomeDaRota)
            {
                aux.addPoint(ponto);
                return;
            }
        }
    }
    
    public String getRota(String nome)
    {
        for(int i = 0; i < rotas.size(); i++)
        {
            Rota aux = rotas.get(i);
            
            if(aux.getName() == nome)
            {
                return aux.toString();
            }
        }
        
        return "";
    }
}