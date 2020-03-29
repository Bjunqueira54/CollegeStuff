package ficha1_ex5;

import java.lang.Math;
import java.util.Scanner;

public class Ficha1_Ex5
{
    int aposta[];
    static Scanner sc = new Scanner(System.in);

    public Ficha1_Ex5()
    {
	aposta = new int[6];
    }
    
    public static void main(String[] args)
    {
	Ficha1_Ex5 aposta_jogador = new Ficha1_Ex5();
	Ficha1_Ex5 aposta_caixa = new Ficha1_Ex5();
	
	aposta_jogador.aposta_manual();
	aposta_caixa.aposta_automatica();
	
	aposta_jogador.MostraAposta();
	aposta_caixa.MostraAposta();
	
	System.out.println("\n");
	
	aposta_caixa.SortAposta();
	aposta_jogador.SortAposta();
	
	aposta_jogador.MostraAposta();
	aposta_caixa.MostraAposta();
	
	if(aposta_caixa.ComparaApostas(aposta_jogador))
	    System.out.println("Holy Shit acertas-te!");
	else
	    System.out.println("Better Luck Next Time!");
    }
    
    public void aposta_manual()
    {
	int num;
	
	for(int i = 0; i < 6; i++)
	{
	    do
	    {
		num = sc.nextInt();
	    }
	    while(!InsereNum(num));
	}
    }
    
    public void aposta_automatica()
    {
	int rand;
	
	for(int i = 0; i < 6; i++)
	{
	    do
	    {
		rand = (int) (Math.random() * 49) + 1;
	    }
	    while(!VerificaNum(rand) || NumExiste(rand));
	    
	    aposta[i] = rand;
	}
    }
    
    public boolean InsereNum(int num)
    {
	if(!VerificaNum(num) || NumExiste(num))
	    return false;
	else
	{
	    for(int i = 0; i < 6; i++)
	    {
		if(!VerificaNum(aposta[i]))
		{
		    aposta[i] = num;
		    return true;
		}
	    }
	}
	
	return false;
    }
    
    public boolean VerificaNum(int num)
    {
	return (num >= 1 && num <= 49);
    }
    
    public boolean NumExiste(int num)
    {
	for(int i = 0; i < 6; i++)
	{
	    if( num == aposta[i])
		return true;
	}
	
	return false;
    }
    
    public void MostraAposta()
    {
	for(int i = 0; i < 6; i++)
	{
	    System.out.print(aposta[i] + " ");
	}
	System.out.println("");
    }
    
    public boolean ComparaApostas(Ficha1_Ex5 joga)
    {
	for(int i = 0; i < 6; i++)
	{
	    if(aposta[i] != joga.aposta[i])
	    {
		return false;
	    }
	}
	return true;
    }
    
    public void SortAposta()
    {
	int i;
	for(i = 1; i <= 5; i++)
	{
	    if(aposta[i] < aposta[i-1])
	    {
		break;
	    }
	}
	
	if(i > 5) i = 5;
	
	if(i == 5 && (aposta[5] > aposta[4]))
	    return;
	else
	{
	    int aux = aposta[i-1];
	    aposta[i-1] = aposta[i];
	    aposta[i] = aux;
	    
	    SortAposta();
	}
    }
}