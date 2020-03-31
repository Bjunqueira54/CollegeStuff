package ficha4_ex5;

import java.util.ArrayList;
import java.util.List;

public class Restaurante
{
    List<String> menu_vegetariano;
    List<String> menu_geral;
    List<String> menu_fastfood;
    List<String> menu_italiano;
    List<String> menu_dieta;
    
    PublicidadeGastronomica agencia;
    
    public Restaurante(Object agencia_publicitaria)
    {
        if(agencia_publicitaria == null) return;
        
        PublicidadeGastronomica aux = (PublicidadeGastronomica) agencia_publicitaria;
        aux.addRestaurante(this);
        
        menu_dieta = new ArrayList<>();
        menu_fastfood = new ArrayList<>();
        menu_vegetariano = new ArrayList<>();
        menu_geral = new ArrayList<>();
        menu_italiano = new ArrayList<>();
    }
    
    public boolean addMenuVegetariano(String nome)
    {
        if(nome == null) return false;
        if(menu_vegetariano.contains(nome)) return true;
        
        return menu_vegetariano.add(nome);
    }
    
    public boolean addMenuFastFood(String nome)
    {
        if(nome == null) return false;
        if(menu_fastfood.contains(nome)) return true;
        
        return menu_fastfood.add(nome);
    }
    
    public boolean addMenuGeral(String nome)
    {
        if(nome == null) return false;
        if(menu_geral.contains(nome)) return true;
        
        return menu_geral.add(nome);
    }
    
    public boolean addMenuDieta(String nome)
    {
        if(nome == null) return false;
        if(menu_dieta.contains(nome)) return true;
        
        return menu_dieta.add(nome);
    }
    
    public boolean addMenuItaliano(String nome)
    {
        if(nome == null) return false;
        if(menu_italiano.contains(nome)) return true;
        
        return menu_italiano.add(nome);
    }
    
    public String MenuVegetariano()
    {
        return menu_vegetariano.toString();
    }
    
    public String MenuFastFood()
    {
        return menu_fastfood.toString();
    }
    
    public String MenuGeral()
    {
        return menu_geral.toString();
    }
    
    public String MenuItaliano()
    {
        return menu_italiano.toString();
    }
    
    public String MenuDieta()
    {
        return menu_dieta.toString();
    }
}
