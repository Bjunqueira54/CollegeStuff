package ed_aula6;

import java.util.List;
import java.util.ListIterator;

public class Pilha<T>
{
    private List<? super T> list;
    
    public Pilha(List<? super T> l)
    {
        list = l;
        list.clear();
    }
    
    public boolean empty() { return list.isEmpty();}
    public T pop() { return (T) list.remove(list.size() - 1); }
    public void push(T obj) { list.add(obj); }
    
    public T peek()
    {
        ListIterator<? super T> li_it = list.listIterator(list.size());
        
        return (T) li_it.previous();
    }
}