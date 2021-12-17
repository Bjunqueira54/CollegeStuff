package pa.edficha5;

import java.util.ArrayList;

public class ExtraStack <T extends Comparable<? super T>>
{
    private final myStack<T> s1;
    private final myStack<T> s2;
    
    public ExtraStack() {
        s1 = new myStack(new ArrayList<T>());
        s2 = new myStack(new ArrayList<T>());
    }
    
    public void push(T v) {
        s1.push(v);
        
        if(s2.empty() || s2.peek().compareTo(v) >= 0)
            s2.push(v);
    }
    
    public T pop() {
        T s1_pop = (T) s1.pop();
        
        if(s2.peek().compareTo(s1_pop) == 0)
            s2.pop();
        
        return s1_pop;
    }
    
    public T findMin() {
        return (T) s2.peek();
    }
}
