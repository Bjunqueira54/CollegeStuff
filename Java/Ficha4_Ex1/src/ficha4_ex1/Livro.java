package ficha4_ex1;

public class Livro
{
    private final String titulo;
    private final String autores[];
    private static int codigo = 0;
    
    public Livro(String tit, String aut[])
    {
	autores = aut;
	titulo = tit;
	codigo++;
    }
    
    public int getCodigo() { return codigo; }
    public final String getTitulo() { return titulo; }
    public final String getAutores() { return autores.toString(); }
    
    @Override
    public String toString()
    {
	String aux_aut = "";
	
	for (Object autore : autores)
	{
	    aux_aut = autore + "\n";
	}
	
	return ("Titulo: " + titulo + "\nAutores: " + aux_aut + "\nCodigo: " + codigo);
    }
    
    @Override
    public boolean equals(Object obj)
    {
	if(obj == null)
	    return false;
	if(obj != this)
	    return false;
	
	final Livro aux = (Livro) obj;
	
	if(this.getCodigo() != aux.getCodigo())
	    return false;
	
	return true;
    }

    @Override
    public int hashCode()
    {
	return super.hashCode();
    }
}