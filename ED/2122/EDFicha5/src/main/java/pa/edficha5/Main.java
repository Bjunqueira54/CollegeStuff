package pa.edficha5;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Main <T>
{
    public static void main(String[] args)
    {
        /*List<Integer> l = new ArrayList<>();
        
        l.add(1);
        l.add(2);
        l.add(3);
        
        System.out.println("Orig: " + l);
        System.out.print("Reverse Orig: ");
        reversePrint(l);
        
        fill(l, 5);
        
        System.out.println("Fill: " + l);*/
        
        List<Integer> al = new ArrayList<>();
        List<Integer> ll = new LinkedList<>();
        
        myStack alStack = new myStack(al);
        myStack llStack = new myStack(ll);
        
        System.out.println("Avg. run time for 20 runs (ms)");
        System.out.println("N | ArrayList | LinkedList");
        
        long n, runs = 50000, nruns = 30;
        double tm;
        
        for(int i = 1; i <= 30; i++)
        {
            n = runs * i;
            tm = 0;
            
            for(int j = 0; j < nruns; j++)
                tm += testStack(alStack, n);
            System.out.printf("%d | %9.2f | ", i, (float)(tm/nruns));
            
            tm = 0;
            
            for(int j = 0; j < nruns; j++) tm += testStack(llStack, n);
            System.out.printf("%.2f\n", (float)(tm/nruns));
        }
    }
    
    private static <T> void fill(List<? super T> l, T v)
    {
        ListIterator it = l.listIterator();
        
        while(it.hasNext())
        {
            it.next();
            it.set(v);
        }
    }
    
    private static void reversePrint(List<?> l)
    {
        ListIterator it = l.listIterator(l.size());
        
        System.out.print("[");
        while(it.hasPrevious())
        {
            System.out.print(it.previous());
            
            if(it.hasPrevious())
                System.out.print(", ");
        }
        System.out.println("]");
    }
    
    public static double testStack(myStack s, long RUNS)
    {
        long startTime = System.nanoTime();
        
        for(int j = 0; j < RUNS; j++)
            s.push(j);
        for(int j = 0; j < RUNS; j++)
            s.pop();
        
        return (System.nanoTime() - startTime) / 1000000.0;
    }
}