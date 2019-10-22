package ed_ficha5;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Main
{
    public static void main(String[] args)
    {
        ArrayList<Integer> list = new ArrayList<>();
        
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        
        //MyCollection.fill(list, 10);
        
        System.out.println(list);
        
        //MyCollection.showReverse(list);
        
        Stack stack = new Stack(list);
        
        stack.push((Integer) 5);
        
        try
        {
            System.out.println(stack.peek());
            System.out.println(stack.pop());
            //System.out.println(stack.peek());
        }
        catch(EmptyStackException ex) {}
        
        System.out.println(String.format("%5.2f ms", testStack(stack, 5000)));
        
        List aList = new ArrayList<>();
        List lList = new LinkedList<>();
        
        long n, sz = 5000, nRuns = 20;
        double tm;
        
        Stack aStack = new Stack(aList);
        Stack lStack = new Stack(lList);
        
        System.out.println("Average Execution Time of "+nRuns+" executions(ms)");
        System.out.println("N|ArrayList|LinkedList");
        
        for(int i = 0; i <= 7; i++)
        {
            n = sz * i;
            tm = 0;
            
            for (int j = 0; j < nRuns; j++)
            {
                tm += testStack(aStack, n);
            }
            System.out.printf("%d|%9.2f|", i, (float)(tm/nRuns));
            
            tm = 0;
            for (int j = 0; j < nRuns; j++)
            {
                tm += testStack(lStack, n);
            }
            System.out.printf("%.2f\n", (float)(tm/nRuns));
        }
        
        /*sz = 10000;
        System.out.println("\n\n");
        
        for(int i = 0; i <= 7; i++)
        {
            n = sz * i;
            tm = 0;
            
            for (int j = 0; j < nRuns; j++)
            {
                tm += testStack2(aStack, n);
            }
            System.out.printf("%d|%9.2f|", i, (float)(tm/nRuns));
            
            tm = 0;
            for (int j = 0; j < nRuns; j++)
            {
                tm += testStack2(lStack, n);
            }
            System.out.printf("%.2f\n", (float)(tm/nRuns));
        }*/
        
        System.out.println("\n");
        
        ArrayList<Integer> iList = new ArrayList<>();
        
        iList.add(1);
        iList.add(2);
        iList.add(3);
        iList.add(4);
        iList.add(5);
        
        System.out.println(iList);
        
        MyCollection.reverse(iList);
        
        System.out.println(iList);
    }
    
    public static double testStack(Stack stack, long num)
    {
        long startTime = System.nanoTime();
        
        for(int i = 0; i < num; i++)
            stack.push(i);
        try
        {
            for(int i = 0; i < num; i++)
                stack.pop();
        }
        catch(EmptyStackException ex) {}
        
        return (System.nanoTime() - startTime)/1000000.0;
    }
    
    public static double testStack2(Stack stack, long num)
    {
        long startTime = System.nanoTime();
        
        for(int i = 0; i < num; i++) stack.push(i);
        for (int i = 0; i < num; i++) stack.removeStart();
        
        return (System.nanoTime() - startTime)/1000000.0;
    }
}