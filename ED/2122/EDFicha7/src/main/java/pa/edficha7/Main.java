package pa.edficha7;

public class Main
{
    public static void main(String[] args)
    {
        BinaryTree<Integer> tree = new BinaryTree<>();
        
        tree.insert(1);
        tree.insert(10);
        tree.insert(4);
        tree.insert(15);
        tree.insert(2);
        tree.insert(7);
        tree.insert(5);
        
        tree.printLessThan(6);
        
        BinaryTree<Integer> nt = tree.clone(6);
    }
}