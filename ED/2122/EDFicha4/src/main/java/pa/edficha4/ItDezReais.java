package pa.edficha4;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReais implements Iterator<Double>
{
    private final DezReais classRef;
    private int posLast = -1;
    
    public ItDezReais(DezReais dr) { classRef = dr; }

    @Override
    public Double next() {
        if(!hasNext())
            throw new NoSuchElementException();
        
        return classRef.get(++posLast);
    }
    @Override
    public boolean hasNext() {
        return ((posLast + 1) < classRef.size());
    }
    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        
        if(hasNext())
            str.append(classRef.get(posLast));
        
        return str.toString();
    }
}
