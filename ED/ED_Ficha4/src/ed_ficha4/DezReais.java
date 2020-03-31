package ed_ficha4;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.function.Consumer;

public class DezReais implements Iterable<Double>
{
    private ArrayList<Double> vector;
    
    public DezReais()
    {
        vector = new ArrayList<>();
    }
    
    public void add(Double num) throws DezReaisFullCapacityException
    {
        if(vector.size() < 10)
            vector.add(num);
        else
            throw new DezReaisFullCapacityException();
    }

    @Override
    public Iterator<Double> iterator()
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}