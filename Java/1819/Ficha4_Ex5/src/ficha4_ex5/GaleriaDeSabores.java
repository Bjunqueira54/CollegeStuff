package ficha4_ex5;

public class GaleriaDeSabores extends Restaurante
{
    public GaleriaDeSabores(Object obj)
    {
        super(obj);
    }
    
    @Override
    public String MenuVegetariano()
    {
        if(menu_vegetariano.size() == 0)
            return "";
        
        return "Galeria De Sabores - Menu Vegetariano:\n\t" + super.MenuVegetariano();
    }
    
    @Override
    public String MenuFastFood()
    {
        if(menu_fastfood.size() == 0)
            return "";
        
        return "Galeria De Sabores - Menu Fast Food:\n\t" + super.MenuFastFood();
    }
    
    @Override
    public String MenuGeral()
    {
        if(menu_geral.size() == 0)
            return "";
        
        return "Galeria De Sabores - Menu Geral:\n\t" + super.MenuGeral();
    }
    
    @Override
    public String MenuDieta()
    {
        if(menu_dieta.size() == 0)
            return "";
        
        return "Galeria De Sabores - Menu Dieta:\n\t" + super.MenuDieta();
    }
    
    @Override
    public String MenuItaliano()
    {
        if(menu_italiano.size() == 0)
            return "";
        
        return "Galeria De Sabores - Menu Italiano:\n\t" + super.MenuItaliano();
    }
}
