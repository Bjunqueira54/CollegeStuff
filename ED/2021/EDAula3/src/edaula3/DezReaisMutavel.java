package edaula3;

import java.util.Iterator;

public class DezReaisMutavel extends DezReais
{
    private int mod;
    
    public DezReaisMutavel()
    {
        super();
        mod = 0;
    }
    
    public void remove(int index)
    {
        for(int i = index; i < CAPACITY - 2; i++)
        {
            array[i] = array[i+1];
        }
        
        array[CAPACITY - 1] = 0.0;
        mod++;
    }

    @Override
    void add(Double n)
    {
        super.add(n);
        mod++;
    }
    
    public int getMod() { return mod; }
    
    @Override
    public Iterator<Double> iterator()
    {
        return new ItDezReaisMutavel(this);
    }
}