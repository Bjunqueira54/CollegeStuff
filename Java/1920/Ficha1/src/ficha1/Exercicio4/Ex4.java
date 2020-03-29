package ficha1.Exercicio4;

public class Ex4
{
    public Ex4() {}
    
    public void play()
    {
        RandomIntArray array = new RandomIntArray();
        
        System.out.println("Array:");
        System.out.println(array.toString());
        
        System.out.println("Number of duplicated numbers: " + array.showDuped());
        System.out.println("Duped Numbers:");
        System.out.println(array.showDupedNumbers());
    }
}