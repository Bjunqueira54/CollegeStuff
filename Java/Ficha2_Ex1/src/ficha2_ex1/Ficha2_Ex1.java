package ficha2_ex1;

import java.util.Arrays;
import java.util.Scanner;

public class Ficha2_Ex1
{
    static Scanner sc = new Scanner(System.in);
    
    static char HIDDEN_CHAR = '#';
    static int MAX_STRIKES = 7;
    
    String frase;
    char letras[];
    int strikes;
    StringBuffer palavraDesc;
    
    public Ficha2_Ex1()
    {
	IniciaJogo("Espanha");
	letras = new char[0];
    }
    
    public void IniciaJogo(String fr)
    {
	this.frase = fr.toUpperCase();
	this.strikes = 0;
	this.palavraDesc = new StringBuffer();
	
	for (int i = 0; i < this.frase.length(); i++)
	{
	    palavraDesc.append(HIDDEN_CHAR);
	}
    }
    
    public static void main(String[] args)
    {
	String frase;
	
	Ficha2_Ex1 game = new Ficha2_Ex1();
	
	while(!game.acabou() && game.getStrikes() < 7)
	{
	    System.out.println("Tentativas: " + game.getStrikes());
	    System.out.println("Palavra Desc: " + game.getPalavraDesc());
	    System.out.println("Letras Usadas: " + game.getLetras());
	    System.out.print("Letra: ");
	    
	    frase = sc.next();
	    
	    game.testa(frase);
	    System.out.println("\n" + game.getPalavraDesc());
	}
	
	if(game.acabou())
	    System.out.println("Ganhas-te!");
	else if(game.getStrikes() >= 7)
	    System.out.println("Perdes-te!");
    }
    
    boolean acabou()
    {
	if(strikes == MAX_STRIKES)
	    return true;
	if(acertou())
	    return true;
	return false;
    }
    
    int getStrikes()
    {
	return strikes;
    }
    
    String getPalavraDesc()
    {
	return palavraDesc.toString();
    }
    
    private boolean acertou()
    {
	return frase.equalsIgnoreCase(palavraDesc.toString());
    }
    
   public String getLetras()
    {
	return new String(letras);
    }
    
    void testa(String opcao)
    {
	if(acabou())
	    return;
	
	opcao = opcao.trim().toUpperCase();
	
	if(opcao.length() > 1)
	{
	    if(opcao.equals(frase))
		palavraDesc = new StringBuffer(frase);
	}
	else
	{
	    char c = opcao.charAt(0);
	    testa(c);
	}
    }
    
    void testa(char c)
    {
	if(acabou())
	    return;
	
	c = Character.toUpperCase(c);
	
	for(int i = 0; i < letras.length; i++)
	{
	    if(c == letras[i])
		return;
	}
	
	int pos = frase.indexOf(c);
	
	if(pos >= 0)
	{
	    for (int i = pos; i < frase.length(); i++)
	    {
		if(frase.charAt(i) == c)
		    palavraDesc.setCharAt(i, c);
	    }
	}
	else
	{
	    letras[strikes++] = c;
	}
    }
}