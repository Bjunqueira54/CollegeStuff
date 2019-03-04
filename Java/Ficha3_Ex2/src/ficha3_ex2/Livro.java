package ficha3_ex2;

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Livro
{
    static int lastcode = 0;
    int code;
    String title;
    ArrayList<String> authors;
    
    public Livro(String tit, List<String> aut)
    {
	this.code = lastcode++;
	this.title = tit;
	this.authors = new ArrayList<>();
	this.authors.addAll(aut);
    }
    
    public Livro(String tit, String[] aut)
    {
	this(tit, Arrays.asList(aut));
    }
    
    public int getCode() { return this.code; }
    public String getTitle() { return this.title; }
    
    @Override
    public int hashCode()
    {
	int hash = 7;
	hash = 41 * hash * this.code;
	return hash;
    }
    
    @Override
    public boolean equals(Object obj)
    {
	if(this == obj)
	    return true;
	
	if (obj == null)
	    return false;
	
	if(this.getClass() != obj.getClass())
	    return false;
	
	final Livro other = (Livro) obj;
	
	if(this.getCode() != other.getCode())
	    return false;
	else
	    return true;
    }
    
    @Override
    public String toString()
    {
	return "Book {" + 
		"\n\tCode: " + this.getCode() +
		"\n\tTitle: " + this.getTitle() +
		"\n\tAuthors: " + this.authors +
		"\n";
    }
    
    public void setAuthors(ArrayList<String> auth)
    {
	this.authors.clear();
	this.authors.addAll(auth);
    }
}
