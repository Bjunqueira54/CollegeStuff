package edaula3;

import java.util.Iterator;

public class DezReais implements Iterable<Double>
{
    protected final int CAPACITY = 10;
    protected Double[] array;
    protected int last = 0;
    
    public DezReais()
    {
        array = new Double[CAPACITY];
    }
    
    void add(Double n)
    {
        if(size() >= CAPACITY)
            throw new RuntimeException();
        
        array[last++] = n;
    }
    
    public double get(int pos)
    {
        if(pos > array.length)
            throw new ArrayIndexOutOfBoundsException();
        else
            return array[pos];
    }
    
    public int size()
    {
        return last;
    }

    @Override
    public Iterator<Double> iterator()
    {
        return new ItDezReais(this);
    }
}