package pa.edficha5;

import java.util.List;
import java.util.ListIterator;

public class myStack <T>
{
    private final List<? super T> innerStack;
    
    public myStack(List<? super T> l) {
        innerStack = l;
        innerStack.clear();
    }
    
    public void push(T v) { innerStack.add(v); }
    public T pop() { return (T) innerStack.remove(innerStack.size() - 1); }
    public T peek() {
        ListIterator it = innerStack.listIterator(innerStack.size());
        return (T) it.previous();
    }
    public boolean empty() { return innerStack.isEmpty(); }
    public void show() {
        ListIterator <? super T> it = innerStack.listIterator();
        while(it.hasNext()) System.out.println(it.next());
    }
}
