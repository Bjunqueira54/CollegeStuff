package ficha2_ex2;

import java.util.Scanner;

public class Ficha2_Ex2
{
    String titulo;
    String autores[];
    String texto[];
    
    public Ficha2_Ex2(String titulo)
    {
	this.titulo = titulo;
	autores = new String[5];
	texto = new String[10];
	
	for (int i = 0; i < autores.length; i++)
	    autores[i] = null;
	
	for (int i = 0; i < texto.length; i++)
	    texto[i] = null;
    }
    
    public String getTitulo()
    { return titulo; }
    
    public String getAutores()
    {
	String au = "";
	
	for (String autore : autores)
	{
	    if (autore != null)
	    {
		au += autore + "\n";
	    }
	}
	
	return au;
    }
    
    public static void main(String[] args)
    {
	Scanner sc = new Scanner(System.in);
	Ficha2_Ex2 documento = new Ficha2_Ex2("Doc 1");
	documento.addAuthor("Jose Luis");
	documento.addAuthor("Ana");
	documento.addAuthor("Gomes");
	
	System.out.println(documento.getTitulo());
	System.out.println(documento.getAutores());
	
	documento.removeAuthor("Jose Luis");
	documento.removeAuthor(1);
	
	System.out.println(documento.getTitulo());
	System.out.println(documento.getAutores());
	
	documento.addText("mais uma linha.");
	/*documento.addText("mais 2 linhas. mais 3 linhas.");
	documento.removeText("mais 4 linhas");
	
	documento.countWords();
	documento.countWords("linha");
	documento.changeToSentenceCase();*/
    }
    
    public boolean ExisteEspaco()
    {
	for (String autore : autores)
	{
	    if (autore == null)
	    {
		return true;
	    }
	}
	
	return false;
    }
    
    public void addAuthor(String autor)
    {
	if(ExisteEspaco())
	{
	    for (int i = 0; i < autores.length; i++)
	    {
		if(autores[i] == null)
		{
		    autores[i] = autor;
		    return;
		}
	    }
	}
	else
	{
	    int len = autores.length;
	    String aux[] = new String[this.autores.length+1];
	    autores = aux;
	    autores[autores.length-1] = autor;
	}
    }
    
    public void removeAuthor(String autor)
    {
	for (int i = 0; i < autores.length; i++)
	{
	    if(autores[i].equals(autor))
	    {
		autores[i] = null;
		return;
	    }
	}
    }
    
    public void removeAuthor(int pos)
    {
	if(autores[pos] != null)
	    autores[pos] = null;
    }
    
    public void addText(String text)
    {
	
    }
    
    public void removeText(String text)
    {
	
    }
    
    public void countWords()
    {
	
    }
    
    public void countWords(String word)
    {
	
    }
    
    public void changeToSentenceCase()
    {
	
    }
}