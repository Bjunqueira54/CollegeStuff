package ed_aula6;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

public class Main
{
    public static void main(String[] args)
    {
        //ex5();
        //ex6();
        //ex7();
        ex8();
    }
    
    private static void ex5()
    {
        List list = new ArrayList();
        
        list.add("AA");
        list.add("BB");
        list.add("CC");
        list.add("DD");
        list.add("EE");
        list.add("FF");
        
        reverse(list);
        
        Iterator it = list.iterator();
        
        while(it.hasNext())
        {
            Object temp = it.next();
            System.out.println(temp);
        }
    }
    
    private static void ex6()
    {
        List list = new ArrayList();
        
        list.add("AA");
        list.add("BB");
        list.add("CC");
        list.add("DD");
        list.add("EE");
        list.add("FF");
        
        collectionReverse(list);
    }
    
    private static void ex7()
    {
        List<Integer> list = new ArrayList<Integer>();
        
        list.add(0);
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        list.add(6);
        list.add(7);
        list.add(8);
        list.add(9);
        list.add(10);
        list.add(11);
        
        removeEvenIndexesNoSpace(list);
        
        for(Integer it: list)
            System.out.println(it);
    }
    
    public static void ex8()
    {
        
    }
    
    private static<T> void reverse(List<? super T> list)
    {
        ListIterator begin = list.listIterator();
        ListIterator end = list.listIterator(list.size());
        T temp;
        
        while(begin.nextIndex() < end.nextIndex())
        {
            temp = (T) begin.next();
            begin.set(end.previous());
            end.set(temp);
        }
    }
    
    private static <T> void collectionReverse(Collection<T> collection)
    {
        Pilha<T> l = new Pilha<>(new ArrayList<T>());
        
        for(T it: collection)
        {
            l.push(it);
        }
        
        while(!l.empty())
            System.out.println(l.pop());
    }
    
    private static <T> void removeEvenIndexes(List<T> list)
    {
        List<T> temp = new ArrayList<T>();
        
        for(int i = 0; i < list.size(); i++)
            if(i % 2 != 0)
                temp.add(list.get(i));
        
        list.clear();
        list.addAll(temp);
    }
    
    private static <T> void removeEvenIndexesNoSpace(List<T> list)
    {
        int init_size = list.size();
        
        for(int i = init_size - 1; i >= 0; i--)
        {
            if(i % 2 == 0)
                list.remove(i);
        }
    }
}