package ficha4_ex1;

import java.util.List;

public class main
{
    public main() {}
    
    public static void main(String[] args)
    {
	String aut[] = {"Bruno", "Miguel"};
	Livro liv1 = new Livro("Teste1", aut);
	Livro liv2 = new Livro("Eragon", aut);
	
	Biblioteca bib1 = new Biblioteca("ISEC");
	
	bib1.acrescentaLivro(liv1);
	bib1.acrescentaLivro(liv2);
	
	System.out.println(bib1.toString());
    }
}