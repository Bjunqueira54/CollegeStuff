package ed_ficha3;

public class Main
{
    static class Ponto <A extends Number, B extends Number>
    {
        private A x;
        private B y;
        
        public Ponto(A x, B y) { this.x = x; this.y = y; }

        public void copy(Ponto<? extends A, ? extends B> p)
        {
            this.x = p.x;
            this.y = p.y;
        }
        
        @Override
        public String toString()
        {
            return "(" + this.x + ", " + this.y + ")\n";
        }
        
        
    }
    
    public static void main(String[] args)
    {
        System.out.printf("Max de %d, %d, %d: %d\n", 3, 4, 5, maxim(3, 4, 5));
        System.out.printf("Max de %.1f, %.1f, %.1f: %.1f\n", 6.6, 8.8, 7.7, maxim(6.6, 8.8, 7.7));
        System.out.printf("Max de %s, %s, %s: %s\n", "Joana", "Ze", "Joao", maxim("Joana", "Ze", "Joao"));
        
        Integer tab[] = {1, 1, 1, 2, 3, 4, 5, 6};
        
        if(existsMultiple(tab, 1))
            System.out.println("Version 1: Exists Multiple\n");
        else
            System.out.println("Version 1: Doesn't exist multiple times");
        
        if(existsMultipleVersion2(tab, 1))
            System.out.println("Version 2: Exists Multiple\n");
        else
            System.out.println("Version 2: Doesn't exist multiple times");
        
        Integer m[] = {3, 2, 6, 3};
        String n[] = {"Ana", "Albino"};
        
        System.out.println(existLarger(m, 2));
        System.out.println(existLarger(n, "Francisco"));
        
        System.out.println("\n");
        
        Ponto<Integer, Integer> p=new Ponto< >(3,4);
        Ponto<Number, Number> x=new Ponto<>(0,0);
        System.out.println(p);  // imprime (3,4)
        System.out.println(x); // imprime (0,0)
        x.copy(p);
        System.out.println(x); // imprime (3,4)
    }
    
    public static <T> void printArray(T[] tab)
    {
        for(T element : tab)
            System.out.printf("%s", element);
    }
    
    public static <T extends Comparable<T>> boolean existLarger(T tab[], T element)
    {
        for(T it : tab)
            if(it.compareTo(element) > 0)
                return true;
        
        return false;
    }
    
    public static <T> boolean existsMultiple(T tab[], T element)
    {
        int counter = 0;
        
        for(T ele: tab)
            if(ele.equals(element))
                counter++;
        
        return counter > 1 ? true : false;
    }
    
    public static <T extends Comparable<T>> boolean existsMultipleVersion2(T tab[], T element)
    {
        int counter = 0;
        
        for(T ele: tab)
            if(ele.compareTo(element) == 0)
                counter++;
        
        return counter > 1 ? true : false;
    }
    
    public static <T extends Comparable<T>> T maxim(T x, T y, T z)
    {
        T max = x;
        
        if(y.compareTo(max) > 0)
            max = y;
        if(z.compareTo(max) > 0)
            max = z;
        
        return max;
    }
}