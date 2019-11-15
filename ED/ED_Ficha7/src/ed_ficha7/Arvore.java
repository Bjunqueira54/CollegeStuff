package ed_ficha7;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class Arvore<T extends Comparable<? super T>>
{
    private class Node <T>
    {
        private T data;
        private Node left, right;
        
        public Node(T data)
        {
            this.data = data;
            left = null;
            right = null;
        }
        
        public Node getLeft() { return left; }
        public Node getRight() { return right; }
        
        public T get() { return data; }
        
        public void setLeft(Node l) { this.left = l; }
        public void setRight(Node r) { this.right = r; }
    }
    
    private Node root;
    private int size;
    private Comparator<T> comp;
    
    public Arvore(Comparator<T> cmp)
    {
        this.comp = cmp;
    }
    
    public Arvore()
    {
        comp = new Comparator<T>()
        {
            @Override
            public int compare(T o1, T o2)
            {
                return o1.compareTo(o2);
            }
        };
        
        this.root = null;
        this.size = 0;
    }
    
    public void insere(T object)
    {
        Node n = new Node(object);
        root = insere(root, n);
        size++;
    }
    
    private Node insere(Node<T> root, Node<T> n)
    {
        if(root == null)
        {
            return n;
        }
        
        int cmp =  comp.compare(root.get(), n.get());
        
        if(cmp == 0)
            throw new RuntimeException();
        
        if(cmp < 0)
            root.setLeft(insere(root.getLeft(), n));
        else
            root.setRight(insere(root.getRight(), n));
        
        return root;
    }
    
    public boolean contem(T data)
    {
        return ContemData(root, data);
    }
    
    private boolean ContemData(Node<T> root, T data)
    {
        if(root == null)
            return false;
        
        int c = comp.compare(data, root.get());
        
        if(c == 0)
            return true;
        
        if(c < 0)
            return ContemData(root.getLeft(), data);
        else
            return ContemData(root.getRight(), data);
    }
    
    public int profundidadeDe(T d) { return profundidadeDe(root, d); }
    
    private int profundidadeDe(Node<T> root, T data)
    {
        int dl = 0, dr = 0;
        
        if(root == null)
            return 0;
        
        if(data.compareTo(root.get()) == 0)
            return 1;
        
        dl = profundidadeDe(root.getLeft(), data);
        dr = profundidadeDe(root.getRight(), data);
        
        if(dl > 0)
            return dl + 1;
        if(dr > 0)
            return dr + 1;
        
        return 0;
    }
    
    public void imprimeOrdem()
    {
        List<T> lista = new ArrayList<>();
        ordem(root, lista);
        mostraLista(lista);
    }
    
    private void ordem(Node<T> root, List<T> list)
    {
        int j;
        
        if(root == null)
            return;
        
        ordem(root.getLeft(), list);
        list.add(root.get());
        ordem(root.getRight(), list);
    }
    
    private void mostraLista(List<T> list)
    {
        for (T it : list)
        {
            System.out.println(it);
        }
    }
    
    public int Profundidade() { return 0; }
    
    public int Tamanho() { return size; }
    
    public void ImprimeNiveis()
    {
        List<Node<T>> list = new LinkedList<>();
        
        list.add(this.root);
        
        System.out.println("====Conteudo da arvore====");
        
        while(!list.isEmpty())
        {
            Node<T> n = list.remove(0);
            
            System.out.println(n.get() + " ");
            
            if(n.getLeft() != null)
                list.add(n.getLeft());
            if(n.getRight() != null)
                list.add(n.getRight());
        }
    }
}