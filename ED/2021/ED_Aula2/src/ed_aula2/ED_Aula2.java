package ed_aula2;

public class ED_Aula2
{
    public static <GenericType> void printArray(GenericType[] arr)
    {
        for(GenericType iterator : arr) System.out.println(iterator);
    }
    
    public static <GenericType extends Comparable<GenericType>> GenericType max(GenericType var1, GenericType var2, GenericType var3)
    {
        GenericType max = var1;
        
        if(var2.compareTo(max) > 0) max = var2;
        if(var3.compareTo(max) > 0) max = var3;
        
        return max;
    }
    
    public static void printObject(Object var)
    {
        System.out.println(var);
    }
    
    public static <GenericType> boolean isDuplicated(GenericType[] array, GenericType key)
    {
        int count = 0;
        
        for(GenericType iterator : array)
        {
            if(iterator == key)
                count++;
            
            if(count > 1)
                return true;
        }
        
        return false;
    }
    
    public static <GenericType extends Comparable<GenericType>> boolean isDuplicated2(GenericType[] array, GenericType key)
    {
        int count = 0;
        
        for(GenericType iterator : array)
        {
            if(iterator.compareTo(key) == 0)
                count++;
            
            if(count > 1)
                return true;
        }
        
        return false;
    }
    
    public static <GenericType extends Comparable<GenericType>> boolean existsHigher(GenericType[] array, GenericType key)
    {
        for(GenericType iterator : array)
            if(iterator.compareTo(key) > 0)
                return true;
        
        return false;
    }
    
    public static void main(String[] args)
    {
        Integer[] mat1 = {1, 2, 3, 4, 5};
        Double[] mat2 = {1.1, 2.2, 3.3, 4.4, 5.5};
        String[] mat3 = {"Bruno", "Maria", "Viktor", "Bruno", "Carlos"};
        
        printArray(mat1);
        printArray(mat2);
        
        printObject(1);
        
        System.out.println(max(2,3,10));
        System.out.println(max(1.5, 2.3, 0.8));
        System.out.println(max("Bruno", "Gonçalo", "Julio"));
        
        System.out.println(isDuplicated(mat3, "Bruno"));
        System.out.println(isDuplicated2(mat3, "Bruno"));
        
        Square s1 = new Square(5);
        Rectangle r1 = new Rectangle(10);
        Triangle t1 = new Triangle(7);
        
        System.out.println(max(r1, s1, t1));
        
        System.out.println(existsHigher(mat1, 6));
        
        Point<Integer, Integer> p1 = new Point(3, 4);
        Point<Number, Number> p2 = new Point(0, 0);
        
        System.out.println(p1);
        System.out.println(p2);
        
        p2.copy(p1);
        
        System.out.println(p2);
    }
}