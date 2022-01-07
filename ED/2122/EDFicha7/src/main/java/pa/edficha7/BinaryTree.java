package pa.edficha7;

import java.util.Comparator;

public class BinaryTree<T extends Comparable<? super T>>
{
    private Node root;
    private final Comparator<T> comparator;
    
    public BinaryTree() {
        this.comparator = (T o1, T o2) -> o1.compareTo(o2);
    }
    public BinaryTree(Comparator<T> c) {
        this.comparator = c;
    }
    
    public void insert(T data) {
        Node n = new Node(data);
        root = insert(root, n);
    }
    private Node<T> insert(Node<T> r, Node<T> n) {
        if(root == null) return n;
        
        int cmp = comparator.compare(r.get(), n.get());
        
        if(cmp == 0) throw new RuntimeException();  //can't have duplicates
        else if(cmp < 0) r.setLeft(insert(r.getLeft(), n));
        else r.setRight(insert(r.getRight(), n));
        
        return r;
    }
    
    public boolean contains(T data) {
        return contains(root, data);
    }
    private boolean contains(Node<T> r, T data) {
        if(r == null) return false;
        
        int cmp = comparator.compare(data, r.get());
        
        if(cmp == 0) return true;
        if(cmp < 0) return contains(r.getLeft(), data);
        else return contains(r.getRight(), data);
    }
}