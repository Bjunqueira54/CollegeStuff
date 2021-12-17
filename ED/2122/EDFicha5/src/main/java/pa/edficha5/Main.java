package pa.edficha5;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Main <T>
{
    public static void main(String[] args)
    {
        List<Integer> int_list = new ArrayList<>();
        
        for(int i = 1; i <= 10; i++)
            int_list.add(i);
        
        System.out.println(int_list);
        
        myReversePrinter(int_list);
        
        Collections.fill(int_list, 2);
        
        System.out.println(int_list);
        
        myFill(int_list, 5);
        
        System.out.println(int_list);
        System.out.println("");
        /*
        System.out.println("/////////////////////");
        System.out.println("///Stack Benchmark///");
        System.out.println("/////////////////////");
        
        myStack al_stack = new myStack(new ArrayList<>());
        myStack ll_stack = new myStack(new LinkedList<>());
        
        {
            long n, sz = 50000, nRuns = 20;
            double timeTaken;

            System.out.println("");
            System.out.println("Avg. Time taken for " + nRuns + " runs (ms).");
            System.out.println("N | ArrayList | LinkedList");

            for(int i = 1; i <= 30; i++)
            {
                n = sz * i;
                timeTaken = 0;

                for(int j = 0; j < nRuns; j++)
                    timeTaken += stackTester(al_stack, n);
                System.out.printf("%d | %9.2f | ", i, (float) (timeTaken / nRuns));

                timeTaken = 0;

                for(int j = 0; j < nRuns; j++)
                    timeTaken += stackTester(ll_stack, n);
                System.out.printf("%.2f\n", (float)(timeTaken / nRuns));
            }
            System.out.println("");
        }
        
        //FOR THE LOVE OF GOD DO NOT RUN THIS NEXT PIECE OF CODE
        System.out.println("/////////////////////");
        System.out.println("///Queue Benchmark///");
        System.out.println("/////////////////////");
        
        myQueue al_queue = new myQueue(new ArrayList<>());
        myQueue ll_queue = new myQueue(new LinkedList<>());
        
        long n, sz = 50000, nRuns = 20;
        double timeTaken;
        
        System.out.println("");
        System.out.println("Avg. Time taken for " + nRuns + " runs (ms).");
        System.out.println("N | ArrayList | LinkedList");
        
        for(int i = 1; i <= 30; i++)
        {
            n = sz * i;
            timeTaken = 0;
            
            for(int j = 0; j < nRuns; j++)
                timeTaken += queueTester(al_queue, n);
            System.out.printf("%d | %9.2f | ", i, (float) (timeTaken / nRuns));
            
            timeTaken = 0;
            
            for(int j = 0; j < nRuns; j++)
                timeTaken += queueTester(ll_queue, n);
            System.out.printf("%.2f\n", (float)(timeTaken / nRuns));
        }
        System.out.println("");*/
        
        List<String> string_list = new ArrayList<>();
        
        string_list.add("Bruno");
        string_list.add("Beatriz");
        string_list.add("Gonçalo");
        string_list.add("Anabela");
        string_list.add("Julio");
        string_list.add("Bernardo");
        
        System.out.println(string_list);
        
        myReverse(string_list);
        
        System.out.println(string_list);
        
        collectionReversePrinter(string_list);
        
        //removeEvenPos(string_list);
        removeEvenPosLimitedSpace(string_list);
        
        System.out.println(string_list);
    }
    
    private static <T> void myFill(List<? super T> l, T key) {
        ListIterator it = l.listIterator();
        
        while(it.hasNext())
        {
            it.next();
            it.set(key);
        }
    }
    private static <T> void myReverse(List<? super T> l) {
        ListIterator it_start = l.listIterator();
        ListIterator it_end = l.listIterator(l.size());
        T temp;
        
        while(it_start.nextIndex() < it_end.previousIndex())
        {
            temp = (T) it_start.next();
            it_start.set(it_end.previous());
            it_end.set(temp);
        }
    }
    private static <T> void collectionReversePrinter(Collection<? super T> c) {
        myStack stack = new myStack(new ArrayList<>());
        Iterator it = c.iterator();
        
        while(it.hasNext())
            stack.push(it.next());
        
        System.out.print("{");
        while(!stack.empty())
        {
            System.out.print(stack.pop());
            if(!stack.empty()) System.out.print(", ");
        }
        System.out.println("]");
    }
    private static <T> void myReversePrinter(List<? super T> l) {
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
    private static double stackTester(myStack s, long sz) {
        long startTime = System.nanoTime();
        for(int j = 0; j < sz; j++) s.push(j);
        for(int j = 0; j < sz; j++) s.pop();
        return (System.nanoTime() - startTime) / 1000000.0;
    }
    private static double queueTester(myQueue q, long sz) {
        long startTime = System.nanoTime();
        for(int j = 0; j < sz; j++) q.add(j);
        for(int j = 0; j < sz; j++) q.remove();
        return ((System.nanoTime() - startTime) / 1000000.0);
    }
    private static <T> void removeEvenPos(List<T> l) {
        ArrayList<T> aux = new ArrayList<>((l.size() / 2) + 1);
        
        ListIterator it = l.listIterator();
        
        while(it.hasNext())
        {
            if(it.nextIndex() % 2 != 0)
                aux.add((T) it.next());
            else
                it.next();
        }
        l.clear();
        l.addAll(aux);
    }
    private static <T> void removeEvenPosLimitedSpace(List<T> l) {
        ListIterator it = l.listIterator(l.size());
        
        while(it.hasPrevious())
        {
            if(it.previousIndex() % 2 == 0)
            {
                it.previous();
                it.remove();
            }
            else
                it.previous();
        }
    }
}