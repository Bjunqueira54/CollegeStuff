package pa.edficha4;

import java.util.Iterator;

public class DezReais implements Iterable<Double>
{
    private final int CAPACITY = 10;
    private final Double[] table;
    private int last = 0;
    private int modCounter = 0;
    
    public DezReais() { table = new Double[CAPACITY]; }
    
    public void addDouble(Double d) {
        if(size() >= 10) throw new RuntimeException();
        table[last++] = d;
        modCounter++;
    }
    
    public int getMods() { return modCounter; }
    
    public int size() { return last; }
    public Double get(int pos) { return table[pos]; }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        
        str.append("[");
        
        for(int i = 0; i < size() - 1; i++)
            str.append(table[i]).append(", ");
        
        str.append(table[size() - 1]).append("]");
        
        return str.toString();
    }
    
    @Override
    public Iterator<Double> iterator() {
        return new ItDezReais(this);
    }
}