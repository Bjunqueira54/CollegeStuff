package edaula3;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReais implements Iterator<Double>
{
    protected final DezReais obj; 
    protected int index;
    
    public ItDezReais(DezReais cl)
    {
        this.obj = cl;
        this.index = -1;
    }

    @Override
    public Double next()
    {
        if(hasNext())
            return obj.get(++index);
        
        throw new NoSuchElementException();
    }

    @Override
    public boolean hasNext()
    {
        return ((index+1) < obj.size());
    }
    
    public static <T extends Comparable<? super T>> void f(ArrayList<T> list, T v1, T v2)
    {
        if(v1.compareTo(v2) > 0)
            list.add(v1);
        else
            list.add(v2);
    }
}