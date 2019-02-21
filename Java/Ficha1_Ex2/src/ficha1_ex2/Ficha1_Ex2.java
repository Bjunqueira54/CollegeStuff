package ficha1_ex2;

import java.util.Scanner;
import java.lang.Math;

public class Ficha1_Ex2
{
    int array[];
    
    public Ficha1_Ex2()
    {
	array = new int[100];
	
	for(int i=0; i<array.length; i++)
	    array[i] = i+1;
    }
    
    public void mostraArray()
    {
	for(int i = 0; i < array.length; i++)
	    System.out.print(array[i] + " ");
	System.out.println("");
    }
    
    public int getMenor()
    {
	return array[0];
    }
    
    public int getMaior()
    {
	int l = array.length;
	return array[l - 1];
    }
    
    public void Maior(int num)
    {
	int i;
	for(i = 0; i < array.length;i++)
	{
	    if(array[i] > num)
		break;
	}
	
	int aux[] = new int[array.length - i];
	
	for(int j = 0; i < array.length; i++, j++)
	    aux[j] = array[i];
	
	array = aux;
    }
    
    public void Menor(int num)
    {
	int i;
	
	for(i = 0; i < array.length; i++)
	{
	    if(array[i] == num)
		break;
	}
	
	i++;
	
	int aux[] = new int[i];
	
	for(int j = 0; j < i; j++)
	    aux[j] = array[j];
	
	array = aux;
    }
    
    public static void main(String[] args)
    {
	Ficha1_Ex2 adivinha = new Ficha1_Ex2();
	Scanner sc = new Scanner(System.in);
	
	int rand;
	char opt;
	
	while(adivinha.array.length > 1)
	{
	    adivinha.mostraArray();
	    System.out.println(adivinha.getMaior());
	    System.out.println(adivinha.getMenor());
	    System.out.println(adivinha.array.length);
	    rand = (int) (Math.random() * adivinha.array.length) + adivinha.getMenor();
	    
	    System.out.print("O teu numero e maior que " + rand + "?(s/n): ");

	    opt = sc.next().charAt(0);
	    
	    if(opt == 's')
		adivinha.Maior(rand);
	    else
		adivinha.Menor(rand);
	}
	
	System.out.println("O teu numero é o " + adivinha.array[0]);
    }
}
