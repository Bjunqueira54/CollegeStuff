package ed_ficha5;

import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class MyCollection
{
    public static <T> void fill(List<? super T> list, T a)
    {
        ListIterator it = list.listIterator();
        
        while(it.hasNext())
        {
            it.next();
            it.set(a);
        }
    }
    
    /*public static <T> List showReverse(List<? super T> list)
    {
        ListIterator it = list.listIterator(list.size());
        List<? super T> aux;
    }*/
    
    public static <T> void reverse(List<? super T> list)
    {
        T aux;
        ListIterator it_end = list.listIterator(list.size());
        ListIterator it_begin = list.listIterator();
        
        while(it_begin.nextIndex() < it_end.previousIndex())
        {
            aux = (T) it_begin.next();
            it_begin.set(it_end.previous());
            it_end.set(aux);
        }
    }
}