package pa.edficha4;

import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ItDezReaisMutavel implements Iterator<Double>
{
    protected final DezReaisMutavel classRef;
    protected int lastPos = -1;
    protected boolean canRemove = false;
    protected int modCounter;
    
    public ItDezReaisMutavel(DezReaisMutavel dr) {
        this.classRef = dr;
        modCounter = classRef.getMods();
    }

    @Override
    public boolean hasNext() {
        checkMod();
        return ((lastPos + 1) < classRef.size());
    }
    
    @Override
    public Double next() {
        checkMod();
        if(!hasNext())  throw new NoSuchElementException();
        canRemove = true;
        return classRef.get(++lastPos);
    }
    
    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        
        if(hasNext())
            str.append(classRef.get(lastPos));
        
        return str.toString();
    }

    @Override
    public void remove() {
        if(!canRemove) throw new IllegalStateException();
        canRemove = false;
        classRef.remove(lastPos--);
        modCounter++;
    }
    
    protected void checkMod() { if(modCounter != classRef.getMods()) throw new ConcurrentModificationException(); }
}
