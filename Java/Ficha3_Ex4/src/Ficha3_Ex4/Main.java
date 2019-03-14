package Ficha3_Ex4;

public class Main
{
    public static void main(String[] args)
    {
	Dicionario d = new Dicionario();
	
	d.add("ingles", "LIVRO", "Book");
	d.add("frances", "LIVRO", "livre");
	d.add("portugues", "LIVRO", "livro");
	d.add("ingles", "ANO", "year");
	d.add("frances", "ANO", "an");
	d.add("portugues", "ANO", "ano");
	
	d.defineLingua("ingles");
	System.out.println(d.get("ANO"));   //year
	d.defineLingua("portugues");
	System.out.println(d.get("ANO"));   //ano
	d.defineLingua("frances");
	System.out.println(d.get("LIVRO"));	//livre
    }
}