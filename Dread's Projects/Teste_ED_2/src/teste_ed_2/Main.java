package teste_ed_2;

public class Main
{
    public static void main(String[] args)
    {
        Turismo t = new Turismo();
        
        t.defineRota("Cruzeiro Douro", "Porto");
        t.defineRota("Santiago", "Ponte de Lima");
        t.defineRota("Date Day", "Aveiro");
        
        t.acrescentaPonto("Date Day", "Canoa");
        t.acrescentaPonto("Date Day", "Sugar Daddy");
        t.acrescentaPonto("Date Day", "Car");
        
        System.out.println(t.getRota("Date Day"));
    }
}