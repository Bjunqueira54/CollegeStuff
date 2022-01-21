package pa.edficha7;

public class Node<T>
{
    private final T data;
    private Node<T> left, right;
    
    public Node(T data) { this.data = data; }
    
    public Node getLeft() { return left; }
    public Node getRight() { return right; }
    
    public T get() { return data; }
    public T peekLeft() { return left != null ? left.data : null; }
    public T peekRight() { return right != null ? right.data : null; }
    
    public void setLeft(Node t) { this.left = t; }
    public void setRight(Node t) { this.right = t; }
}