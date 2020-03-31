package ed_ficha6;

public class Trabalho
{
    private String nome;
    private int paginas;
    
    public Trabalho(String nome, int paginas)
    {
        this.nome = nome;
        this.paginas = paginas;
    }
    
    public void show()
    {
        System.out.println("Trabalho: "+this.nome+"\nPaginas: "+this.paginas);
    }
    
    public int getPaginas() { return this.paginas; }
    
    public String getNome() { return this.nome; }
}