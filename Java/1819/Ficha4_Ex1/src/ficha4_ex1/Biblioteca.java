package ficha4_ex1;

import java.util.List;

public class Biblioteca
{
    private List livros;
    private String nome;
    
    public Biblioteca(String nome)
    {
	this.nome = nome;
    }
    
    public String getNome() { return this.nome; }
    
    public boolean acrescentaLivro(Livro liv)
    {
	if(livros == null)
	{
	    livros.add(0, liv);
	    return true;
	}
	
	return livros.add(liv);
    }
    
    public boolean eliminaLivro(int cod)
    {
	Livro aux = pesquisaLivro(cod);
	
	if(aux == null)
	    return false;
	else
	    return livros.remove(aux);
    }
    
    public Livro pesquisaLivro(int cod)
    {
	for (Object livro : livros)
	{
	    Livro aux = (Livro) livro;
	    if(aux.getCodigo() == cod)
		return ((Livro) livro);
	}
	
	return null;
    }
    
    @Override
    public String toString()
    {
	String liv_aux = "";
	
	for (Object livro : livros)
	{
	    liv_aux = livro.toString() + "\n";
	}
	
	return ("Nome: " + this.nome + "\n" + liv_aux);
    }
}