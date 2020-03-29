package ficha3_ex2;

import java.util.List;
import java.util.Objects;

public class Biblioteca
{
    String name;
    List<Livro> books;
    
    public Biblioteca(String n)
    {
	name = n;
    }
    
    public boolean addBook(Livro book)
    {
	if(SearchBook(book.getTitle()) != null)
	    return false;
	else
	    return books.add(book);
    }
    
    public boolean addBook(String title, List<String> authors)
    {
	return addBook(new Livro(title, authors));
    }
    
    public boolean addBook(String title, String[] authors)
    {
	return addBook(new Livro(title, authors));
    }
    
    public boolean removeBook(String title)
    {
	return books.remove(SearchBook(title));
    }
    
    public boolean removeBook(int code)
    {
	for(Livro book: books)
	    if(book.getCode() == code)
		return removeBook(book.getTitle());
	
	return false;
    }
    
    public Livro SearchBook(String title)
    {
	for(Livro book: books)
	{
	    if(book.getTitle().equalsIgnoreCase(title))
	    {
		return book;
	    }
	}
	
	return null;
    }
    
    public int getNBooks() { return books.size(); }
    
    @Override
    public String toString()
    {
	StringBuilder sb = new StringBuilder();
	sb.append("Library: ").append(name);
	
	return sb.toString();
    }

    @Override
    public boolean equals(Object obj)
    {
	if (this == obj) return true;
	if (obj == null) return false;
	if (getClass() != obj.getClass()) return false;
	final Biblioteca other = (Biblioteca) obj;
	if(this.getNBooks() != other.getNBooks()) return false;
	for(Livro book: this.books)
	    if(!other.contains(book)) return false;
	return true;
    }
    
    public boolean contains(Livro book)
    {
	return this.books.contains(book);
    }
}