package ficha1_ex6;

import java.util.Scanner;

public class Ficha1_Ex6
{
    int matriz[][];
    static Scanner scan = new Scanner(System.in);
    
    public Ficha1_Ex6(int nlinhas, int ncolunas)
    {
	matriz = new int[nlinhas][ncolunas];
    }
    
    public void preenche()
    {
	for (int[] matriz1 : matriz)
	{
	    for (int x = 0; x < matriz1.length; x++)
	    {
		matriz1[x] = scan.nextInt();
	    }
	}
    }
    
    public void mostra()
    {
	for (int[] matriz1 : matriz) {
	    for (int x = 0; x < matriz1.length; x++) {
		System.out.format("%3d", matriz1[x]);
	    }
	    System.out.println("");
	}
    }
    
    public boolean soma(Ficha1_Ex6 mat_b)
    {
	if(!verificaMatrizes(matriz, mat_b.matriz))
	    return false;
	
	for(int y = 0; y < matriz.length; y++)
	{
	    for(int x = 0; x < matriz[y].length; x++)
	    {
		matriz[y][x] = matriz[y][x] + mat_b.matriz[y][x];
	    }
	}
	
	return true;
    }
    
    public boolean verificaMatrizes(int mat_a[][], int mat_b[][])
    {
	if(mat_a.length != mat_b.length)
	    return false;
	
	for(int y = 0; y < mat_a.length; y++)
	    if(mat_a[y].length != mat_b[y].length)
		return false;
	
	for(int y = 0; y < mat_a.length; y++)
	    if(mat_a[y].length != mat_b[0].length)
		return false;
	
	return true;
    }
    
    public static void main(String[] args)
    {
	System.out.println("Dimensoes da Matriz A");
	System.out.print("Linhas: ");
	int nlinhas = scan.nextInt();
	System.out.print("Colunas: ");
	int ncolunas = scan.nextInt();
	Ficha1_Ex6 matriz_a = new Ficha1_Ex6(nlinhas, ncolunas);
	
	System.out.println("Dimensoes da Matriz B");
	System.out.print("Linhas: ");
	nlinhas = scan.nextInt();
	System.out.print("Colunas: ");
	ncolunas = scan.nextInt();
	Ficha1_Ex6 matriz_b = new Ficha1_Ex6(nlinhas, ncolunas);
	
	matriz_a.preenche();
	matriz_a.mostra();
	matriz_b.preenche();
	matriz_b.mostra();
	
	System.out.println("");
	
	if(!matriz_a.soma(matriz_b))
	{
	    System.out.println("Nao posso somar isso");
	}
	else
	    matriz_a.mostra();
    }
}
