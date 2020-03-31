package teste_ed_2;

import java.util.LinkedList;

public class Rota
{
    private final String name;
    private final String origin;
    
    private LinkedList<String> points;
    
    public Rota(String name, String origin)
    {
        this.name = name;
        this.origin = origin;
        
        points = new LinkedList<>();
    }
    
    public String getName() { return this.name; }
    public String getOrigin() { return this.origin; }
    
    public void addPoint(String point) { points.add(point); }
    
    @Override
    public String toString()
    {
        String str = "";
        
        str += "Nome: " + this.name + "\n";
        str += "Origem: " + this.origin + "\n";
        str += "Pontos: \n";
        
        for(int i = 0; i < points.size(); i++)
        {
            str += "\t"+points.get(i)+"\n";
        }
        
        return str;
    }
}