package ficha4_ex5;

import java.util.ArrayList;
import java.util.List;

public class PublicidadeGastronomica
{
    List<Restaurante> restaurantes;
    
    public PublicidadeGastronomica()
    {
        restaurantes = new ArrayList<>();
    }
    
    public boolean addRestaurante(Restaurante restaurante)
    {
        if(restaurante == null) return false;
        
        return restaurantes.add(restaurante);
    }

    public boolean addVegetariano(Restaurante restaurante, String nome)
    {
        if(restaurante == null) return false;
        if(nome == null) return false;
        
        for (Restaurante rest : restaurantes)
        {
            if(rest == restaurante)
                return rest.addMenuVegetariano(nome);
        }
        
        return false;
    }
    
    public String divulgaVegetariano()
    {
        String todosVegetariano = new String();
        
        for (Restaurante rest : restaurantes)
        {
            if(!"".equals(rest.MenuVegetariano()))
                todosVegetariano += rest.MenuVegetariano() + "\n";
        }
        
        return todosVegetariano;
    }
    
    public boolean addFastFood(Restaurante restaurante, String nome)
    {
        if(restaurante == null) return false;
        if(nome == null) return false;
        
        for (Restaurante rest : restaurantes)
        {
            if(rest == restaurante)
                return rest.addMenuFastFood(nome);
        }
        
        return false;
    }
    
    public String divulgaFastFood()
    {
        String todosFastFood = new String();
        
        for (Restaurante rest : restaurantes)
        {
            if(!"".equals(rest.MenuFastFood()))
                todosFastFood += rest.MenuFastFood() + "\n";
        }
        
        return todosFastFood;
    }
    
    public boolean addDieta(Restaurante restaurante, String nome)
    {
        if(restaurante == null) return false;
        if(nome == null) return false;
        
        for (Restaurante rest : restaurantes)
        {
            if(rest == restaurante)
                return rest.addMenuDieta(nome);
        }
        
        return false;
    }
    
    public String divulgaDieta()
    {
        String todosDieta = new String();
        
        for (Restaurante rest : restaurantes)
        {
            if(!"".equals(rest.MenuDieta()))
                todosDieta += rest.MenuDieta() + "\n";
        }
        
        return todosDieta;
    }
    
    public boolean addItaliano(Restaurante restaurante, String nome)
    {
        if(restaurante == null) return false;
        if(nome == null) return false;
        
        for (Restaurante rest : restaurantes)
        {
            if(rest == restaurante)
                return rest.addMenuItaliano(nome);
        }
        
        return false;
    }
    
    public String divulgaItaliano()
    {
        String todosItaliano = new String();
        
        for (Restaurante rest : restaurantes)
        {
            if(!"".equals(rest.MenuItaliano()))
                todosItaliano += rest.MenuItaliano()+ "\n";
        }
        
        return todosItaliano;
    }
    
    public boolean addGeral(Restaurante restaurante, String nome)
    {
        if(restaurante == null) return false;
        if(nome == null) return false;
        
        for (Restaurante rest : restaurantes)
        {
            if(rest == restaurante)
                return rest.addMenuGeral(nome);
        }
        
        return false;
    }
    
    public String divulgaGeral()
    {
        String todosgeral = new String();
        
        for (Restaurante rest : restaurantes)
        {
            if(!"".equals(rest.MenuGeral()))
                todosgeral += rest.MenuGeral()+ "\n";
        }
        
        return todosgeral;
    }
}
