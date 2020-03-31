package ficha1_ex7;

import java.util.Scanner;

public class Ficha1_Ex7
{
    int matriz[][];
    
static Scanner sc = new Scanner(System.in);
    
    public Ficha1_Ex7(int nlinhas, int ncolunas)
    {
	matriz = new int[nlinhas][ncolunas];
    }
    
    public static void main(String[] args)
    {
	System.out.print("Numero de linhas: ");
	int nlinhas = sc.nextInt();
	System.out.print("Numero de colunas: ");
	int ncolunas = sc.nextInt();
	Ficha1_Ex7 mat = new Ficha1_Ex7(nlinhas, ncolunas);
	
	System.out.println("Insere " + (nlinhas*ncolunas) + " valores da tua matriz");
	
	mat.PreencheMatriz();
	mat.MostraMatriz();
	
	mat.MudaValor(2, 2, 10);
	mat.MostraMatriz();
	
	int aux[] = mat.SomaLinhas();
	System.out.println("Soma das Linhas: ");
	for (int i = 0; i < aux.length; i++)
	{
	    System.out.println(aux[i]);
	}
	
	System.out.println("Total: " + mat.CalculaTotal());
    }
    
    public void PreencheMatriz()
    {
	for (int[] is : matriz)
	{
	    for (int i = 0; i < is.length; i++)
	    {
		is[i] = sc.nextInt();
	    }
	}
    }
    
    public void MostraMatriz()
    {
	for (int[] matriz1 : matriz)
	{
	    for (int j = 0; j < matriz1.length; j++)
	    {
		System.out.print(matriz1[j] + " ");
	    }
	    System.out.println("");
	}
    }
    
    public int[] SomaLinhas()
    {
	int aux[] = new int[matriz.length];
	
	for(int i = 0; i < aux.length; i++)
	    aux[i] = 0;
	
	for(int i = 0; i < matriz.length; i++)
	{
	    for(int j = 0; j < matriz[i].length; j++)
	    {
		aux[i] += matriz[i][j];
	    }
	}
	
	return aux;
    }
    
    public int CalculaTotal()
    {
	int aux[] = SomaLinhas();
	int resultado = 0;
	
	for (int i = 0; i < aux.length; i++)
	{
	    resultado += aux[i];
	}
	
	return resultado;
    }
    
    public void MudaValor(int linha, int coluna, int valor)
    {
	matriz[linha - 1][coluna - 1] = valor;
    }
}
