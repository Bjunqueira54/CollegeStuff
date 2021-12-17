package pa.edficha5;

import java.util.List;
import java.util.ListIterator;

public class myQueue <T>
{
    List<? super T> innerQueue;
    
    public myQueue(List<? super T> l) {
        innerQueue = l;
        innerQueue.clear();
    }
    
    public void add(T v) { innerQueue.add(v); }
    public T remove() { return (T) innerQueue.remove(0); }
    public T element() {
        ListIterator it = innerQueue.listIterator();
        return (T) it.next();
    }
    public boolean empty() { return innerQueue.isEmpty(); }
}