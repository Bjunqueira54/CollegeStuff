package ficha1_ex4;

import java.util.Scanner;
import java.lang.Math;

public class Ficha1_Ex4
{
    int array[];
    int gerados = 0;
    
    public Ficha1_Ex4()
    {
	array = new int[20];
    }
    
    public void preencheArray()
    {
	int rand;
	
	for(int i = 0; i < array.length; i++)
	{
	    do
	    {
		rand = (int) ( Math.random() * 100 ) + 1;
		gerados++;
	    }
	    while(!VerificaNum(rand));
	    
	    array[i] = rand;
	}
    }
    
    public boolean VerificaNum(int num)
    {
	for(int i = 0; i < array.length; i++)
	{
	    if(array[i] == num)
		return false;
	}
	
	return true;
    }
    
    public int getGerados()
    {
	return gerados;
    }
    
    public int getDuplicados()
    {
	return (gerados - 20);
    }
    
    public void MostraArray()
    {
	for(int i = 0; i < array.length; i++)
	    System.out.print(array[i] + " ");
    }
    
    public static void main(String[] args)
    {
	Ficha1_Ex4 ex = new Ficha1_Ex4();
	
	ex.preencheArray();
	
	ex.MostraArray();
	
	System.out.println("\nGerados: " + ex.getGerados());
	System.out.println("Duplicados: " + ex.getDuplicados());
    }
    
}
