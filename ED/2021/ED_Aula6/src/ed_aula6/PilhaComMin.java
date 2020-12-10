package ed_aula6;

import java.util.ArrayList;

public class PilhaComMin<T extends Comparable<? super T>>
{
    private final Pilha p1;
    private final Pilha p2;
    
    public PilhaComMin()
    {
        p1 = new Pilha<>(new ArrayList<>());
        p2 = new Pilha<>(new ArrayList<>());
    }
    
    public boolean empty() { return p1.empty();}
    public T pop() { return (T) p1.pop(); }
    public T peek() { return (T) p1.peek(); }
    public void push(T obj)
    {
        p1.push(obj);
        if(obj.compareTo((T) p2.peek()) < 0)
        {
            p2.pop();
            p2.push(obj);
        }
    }
    
    public T getMin() { return (T) p2.pop(); }
}
