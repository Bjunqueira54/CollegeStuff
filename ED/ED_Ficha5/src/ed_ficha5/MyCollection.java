package ed_ficha5;

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
    
    public static <T> void showReverse(List<? super T> list)
    {
        ListIterator it = list.listIterator(list.size());
        
        while(it.hasPrevious())
        {
            System.out.println(it);
            it.previous();
        }
    }
}