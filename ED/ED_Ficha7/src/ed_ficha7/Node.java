package ed_ficha7;

class Node <T>
{
    private T data;
    private Node left, right;

    public Node(T data)
    {
        this.data = data;
        left = null;
        right = null;
    }
    
    public Node()
    {
        this.left = this.right = this;
    }

    public Node getLeft() { return left; }
    public Node getRight() { return right; }

    public T get() { return data; }

    public void setLeft(Node l) { this.left = l; }
    public void setRight(Node r) { this.right = r; }
}