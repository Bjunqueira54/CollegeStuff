package pa.edficha4;

import java.util.Iterator;

public class DezReaisMutavel extends DezReais
{
    private final int CAPACITY = 10;
    private final Double[] table = new Double[CAPACITY];
    private int last = 0;
    private int modCounter = 0;

    public DezReaisMutavel() {}
    
    @Override
    public int size() { return last; }
    @Override
    public Double get(int pos) { return table[pos]; }
    @Override
    public void addDouble(Double d) {
        if(last >= CAPACITY)
            throw new RuntimeException();
        
        table[last++] = d;
        
        modCounter++;
    }
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
        return new ItDezReaisPositive(this);
    }
    
    public void remove(int pos) {
        if(pos > last)
            throw new IllegalStateException();
        
        for(int i = pos; i < table.length - 1; i++)
            table[i] = table[i + 1];
        
        last--;
        modCounter++;
    }
    
    public int getMods() { return modCounter; }
}