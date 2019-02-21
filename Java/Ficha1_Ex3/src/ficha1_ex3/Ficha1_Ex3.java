package ficha1_ex3;

import java.util.Scanner;

public class Ficha1_Ex3
{
    int array[];
    
    static Scanner sc = new Scanner(System.in);
    
    public Ficha1_Ex3(int limite)
    {
	array = new int[limite];
    }
    
    public void preencheArray()
    {
	for(int i = 0; i < array.length; i++)
	{
	    System.out.print("Num " + (i+1) + ": ");
	    array[i] = sc.nextInt();
	}
    }
    
    public int encontraMaior()
    {
	int maior = 0;
	
	for(int i = 0; i < array.length; i++)
	{
	    if(array[i] > maior)
		maior = array[i];
	}
	
	return maior;
    }
    
    public static void main(String[] args)
    {
	System.out.print("Quantos elementos: ");
	int limite = sc.nextInt();
	
	Ficha1_Ex3 new_array = new Ficha1_Ex3(limite);
	
	new_array.preencheArray();
	
	int maior = new_array.encontraMaior();
	
	System.out.println("O maior numero do vector e: " + maior);
    }
}