/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pa_ficha1_ex5;

import java.util.Arrays;

/**
 *
 * @author gothicdread
 */
public class PA_Ficha1_Ex5 {

    public static int MAXLEN = 6;
    public static int NUM_MIN = 1;
    public static int NUM_MAX = 49;
    
    private int array[];
    private int nelementos = 0;
    
    public static void main(String[] args)
    {
	PA_Ficha1_Ex5 f = new PA_Ficha1_Ex5();
	PA_Ficha1_Ex5 g = new PA_Ficha1_Ex5();
	
	f.apostaAutomatica();
	g.apostaAutomatica();
	
	f.mostra();
	f.mostraOrdenado();
	
	g.mostraOrdenado();
	
	if(f.eIgual(g))
	    System.out.println("Ganhei");
    }
    
    public PA_Ficha1_Ex5()
    {
	array = new int[MAXLEN];
    }
    
    public boolean isCompleted()
    {
	return (nelementos == MAXLEN);
    }
    
    boolean isNumValido(int num)
    {
	return (num >= NUM_MIN && num <= NUM_MAX);
    }
    
    public boolean numExiste(int num)
    {
	for(int i=0; i<array.length; i++)
	{
	    if(num == array[i])
		return true;
	}
	
	return false;
    }
    
    public void addElemento(int numero)
    {
	if(isNumValido(numero) && !numExiste(numero) && !isCompleted())
	{
	    adicionaAoArray(numero);
	}
    }
    
    public void adicionaAoArray(int num)
    {
	array[nelementos++] = num;
    }
    
    public void apostaAutomatica()
    {
	while(!isCompleted())
	{
	    int n = getNumAleatorio();
	    addElemento(n);
	}
    }

    private int getNumAleatorio()
    {
	return NUM_MIN + (int) (Math.random() * NUM_MAX);
    }
    
    public boolean eIgual(PA_Ficha1_Ex5 aposta1)
    {
	if(getNelementos() != aposta1.getNelementos())
	    return false;
	    
	for (int i : array)
	{
	    if(!aposta1.numExiste(i))
		return false;
	}
	
	return true;
    }
    
    public int getNelementos()
    {
	return nelementos;
    }

    public void mostra()
    {
	for (int i : array)
	{
	    System.out.print(i);
	    System.out.print(" ");
	}
	System.out.println("");
    }
    
    public void mostraOrdenado()
    {
	int aux[] = new int[6];
	int count = 0;
	int big;
	
	System.arraycopy(array, 0, aux, 0, MAXLEN);
	
	Arrays.sort(aux);
	
	for (int i : aux)
	{
	    System.out.print(i);
	    System.out.print(" ");
	}
	System.out.println("");
    }
}
