package pa.edficha7;

import java.util.Comparator;

public class BinaryTree<T extends Comparable<? super T>>
{
    private Node root;
    private final Comparator<T> comparator;
    
    public BinaryTree() {
        this.comparator = new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return o1.compareTo(o2);
            }
        };
    }
    public BinaryTree(Comparator<T> c) {
        this.comparator = c;
    }
    
    public void insert(T data) {
        Node n = new Node(data);
        root = insert(root, n);
    }
    private Node<T> insert(Node<T> r, Node<T> n) {
        if(r == null) return n;
        
        int cmp = comparator.compare(r.get(), n.get());
        
        if(cmp == 0) throw new RuntimeException();  //can't have duplicates
        else if(cmp > 0) r.setLeft(insert(r.getLeft(), n)); // if r > n
        else r.setRight(insert(r.getRight(), n));           //if r < n
        
        return r;
    }
    
    public boolean contains(T data) {
        return contains(root, data);
    }
    private boolean contains(Node<T> r, T data) {
        if(r == null) return false;
        
        int cmp = comparator.compare(r.get(), data);
        
        if(cmp == 0) return true;
        if(cmp > 0) return contains(r.getLeft(), data); //if r.get() > data
        else return contains(r.getRight(), data);   //if r.get() < data
    }
    
    public void printLessThan(T data) {
        printLessThan(root, data);
    }
    private void printLessThan(Node<T> r, T data) {
        if(r == null) return;
        
        int cmp = comparator.compare(r.get(), data);
        
        if(cmp < 0)
            System.out.println(r.get());
        
        if(cmp > 0) printLessThan(r.getLeft(), data); //if r.get() > data
        else printLessThan(r.getRight(), data); //if r.get() < data
    }
    
    public BinaryTree clone(T data) {
        BinaryTree<T> nt = new BinaryTree<>();
        
        clone(nt, root, data);
        
        return nt;
    }
    private void clone(BinaryTree<T> nt, Node<T> r, T data) {
        if(r == null) return;
        
        int cmp = comparator.compare(r.get(), data);
        
        if(cmp < 0)
            nt.insert(r.get());
        
        if(r.peekLeft() != null && comparator.compare(r.peekLeft(), data) < 0)
            clone(nt, r.getLeft(), data);   //if r.get() < data
        else
            clone(nt, r.getRight(), data);  //if r.get() > data
    }
}