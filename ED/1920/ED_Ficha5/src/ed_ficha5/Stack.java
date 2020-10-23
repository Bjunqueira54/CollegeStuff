package ed_ficha5;

import java.util.List;
import java.util.ListIterator;

public class Stack<T>
{
    List<? super T> list;
    
    public Stack(List<? super T> l)
    {
        list = l;
        list.clear();
    }
    
    public boolean empty() { return (list.size() == 0); }
    
    public void push(T obj) { list.add(obj); }
    
    public Object peek() throws EmptyStackException
    {
        if(empty())
            throw new EmptyStackException();
        
        ListIterator it = list.listIterator(list.size());
        
        
        return (T) it.previous();
    }
    
    public void remove()
    {
        list.remove(list.size() - 1);
    }
    
    public Object pop() throws EmptyStackException
    {
        if(empty())
            throw new EmptyStackException();
        
        Object aux;
        aux = peek();
        
        remove();
        
        return aux;
    }
    
    public void removeStart() { list.remove(0); }
}