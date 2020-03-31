package ficha4_ex5;

public class Italia extends Restaurante
{
    public Italia(Object obj)
    {
        super(obj);
    }
    
    @Override
    public String MenuVegetariano()
    {
        if(menu_vegetariano.size() == 0)
            return "";
        
        return "Italia - Menu Vegetariano:\n\t" + super.MenuVegetariano();
    }
    
    @Override
    public String MenuFastFood()
    {
        if(menu_fastfood.size() == 0)
            return "";
        
        return "Italia - Menu Fast Food:\n\t" + super.MenuFastFood();
    }
    
    @Override
    public String MenuGeral()
    {
        if(menu_geral.size() == 0)
            return "";
        
        return "Italia - Menu Geral:\n\t" + super.MenuGeral();
    }
    
    @Override
    public String MenuDieta()
    {
        if(menu_dieta.size() == 0)
            return "";
        
        return "Italia - Menu Dieta:\n\t" + super.MenuDieta();
    }
    
    @Override
    public String MenuItaliano()
    {
        if(menu_italiano.size() == 0)
            return "";
        
        return "Italia - Menu Italiano:\n\t" + super.MenuItaliano();
    }
}
