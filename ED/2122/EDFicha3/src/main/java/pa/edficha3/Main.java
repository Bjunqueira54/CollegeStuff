package pa.edficha3;

public class Main
{
    public static void main(String[] args)
    {
        String[] string_array = { "Ana", "Joao", "Manel", "Manel", "Ze" };
        String string_key = "Manel";
        
        Double[] double_array = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
        Double double_key = 3.3;
        
        Integer[] integer_array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        Integer integer_key = 0;
        
        System.out.println("Ex1----------------");
        System.out.println("They key " + string_key + " is " + (searchKeyRepeated(string_array, string_key) ? "present multiple times in the array." : "not present multiple times in the array."));
        System.out.println("They key " + double_key + " is " + (searchKeyRepeated(double_array, double_key) ? "present multiple times in the array." : "not present multiple times in the array."));
        System.out.println("They key " + integer_key + " is " + (searchKeyRepeated(integer_array, integer_key) ? "present multiple times in the array." : "not present multiple times in the array."));
    
        System.out.println("Ex2----------------");
        
        System.out.println("They key " + string_key + " is " + (searchKeyRepeatedComparable(string_array, string_key) ? "present multiple times in the array." : "not present multiple times in the array."));
        System.out.println("They key " + double_key + " is " + (searchKeyRepeatedComparable(double_array, double_key) ? "present multiple times in the array." : "not present multiple times in the array."));
        System.out.println("They key " + integer_key + " is " + (searchKeyRepeatedComparable(integer_array, integer_key) ? "present multiple times in the array." : "not present multiple times in the array."));
    
        System.out.println("Ex3----------------");
        
        Rectangle r1 = new Rectangle(4, 5);
        Rectangle r2 = new Rectangle(5, 4);
        Circle c1 = new Circle(4);
        Square s1 = new Square(2, 10);
        Triangle t1 = new Triangle(5, 8);
        
        System.out.println("The figures are " + (compareFigures(r1, r2) ? "the same." : "not the same."));
        System.out.println("The figures are " + (compareRectangleToX(r1, r2) ? "the same." : "not the same."));
        System.out.println("The figures are " + (compareRectangleToX(r1, s1) ? "the same." : "not the same."));
        System.out.println("The figures are " + (compareRectangleToX(r1, c1) ? "the same." : "not the same."));
        System.out.println("The figures are " + (compareRectangleToX(r1, t1) ? "the same." : "not the same."));
        System.out.println("The figures are " + (compareAnyToX(r1, t1) ? "the same." : "not the same."));
        
        System.out.println("Ex4----------------");
        
        Integer m[]={3,2,6,3};
        String n[]={"Ada", "Albino"};
        System.out.println(compareArrayBiggerThanKey(m, 2));
        System.out.println(compareArrayBiggerThanKey(n, "Francisco"));
        
        String[] tab1 = { "Ana", "Joao", "Manel", "Manel", "Ze" };
        String chave1 = "Anab";
        Double [] tab2 = { 1.1, 2.2, 3.3, 2.2 };
        Double chave2 = 200.25;
        Integer [] tab3 = { 2, 6, 7, 8 };
        Integer chave3 = 70;
        System.out.println(chave1 +" encontra-se na tabela " + compareArrayBiggerThanKey(tab1,chave1));
        System.out.println(chave2 +" encontra-se na tabela " + compareArrayBiggerThanKey(tab2,chave2));
        System.out.println(chave3 +" encontra-se na tabela: " + compareArrayBiggerThanKey(tab3, chave3));
        
        System.out.println("Ex5----------------");
        
        Point<Integer, Integer> p1 = new Point<>(3, 4);
        Point<Number, Number> p2 = new Point<>(0, 0);
        
        p2.copy(p1);
        
        System.out.println(p2);
    }
    
    private static <T> boolean searchKeyRepeated(T[] a, T v) {
        int count = 0;
        
        for(T i: a)
            if(i == v) count++;
        
        return count > 1;
    }
    private static <T extends Comparable<T>> boolean searchKeyRepeatedComparable(T[] a, T v) {
        int count = 0;
        
        for(T i: a)
            if(i.compareTo(v) == 0) count++;
        
        return count > 1;
    }
    private static boolean compareFigures(Figure f1, Figure f2) { return (f2.compareTo(f1) == 0); }
    private static boolean compareRectangleToX(Rectangle r, Comparable<? super Rectangle> t) { return (t.compareTo(r) == 0); }
    private static <T> boolean compareAnyToX(T t, Comparable<? super T> o) { return o.compareTo(t) == 0; }
    private static <T> boolean compareArrayBiggerThanKey(T[] a, Comparable<? super T> v) {
        for(T i: a)
            if(v.compareTo(i) < 0)
                return true;
        
        return false;
    }
}