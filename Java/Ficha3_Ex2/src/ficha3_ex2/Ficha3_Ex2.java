package ficha3_ex2;

public class Ficha3_Ex2
{
    public static void main(String[] args)
    {
	String [] aut = {"Autor1", "Autor2"};
	Livro b = new Livro("Titulo Generico", aut);
	
	System.out.println(b);
	
	Biblioteca l1 = new Biblioteca("Lib1");
	Biblioteca l2 = new Biblioteca("Lib2");
	
	l1.addBook(b);
	l1.addBook("Liv2", aut);
	l1.addBook(b);
	
	l2.addBook(b);
	l1.removeBook(b.getCode());
	
	System.out.println(l1.equals(l2));
    }
}