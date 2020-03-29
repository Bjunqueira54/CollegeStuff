package ficha1_ex1;

import java.lang.Math;
import java.util.Scanner;

public class Ficha1_Ex1
{
    int rand;
    public Ficha1_Ex1()
    {
	rand = (int) (Math.random() * 100)+1;
    }
    
    public boolean verificaNum(int num)
    {
	return (num == rand);
    }
    
    public static void main(String[] args)
    {
	Ficha1_Ex1 new_rand = new Ficha1_Ex1();
	Scanner sc = new Scanner(System.in);
	
	System.out.print("Adivinha o numero:");
	int num = sc.nextInt();
	
	System.out.println("Escolhes-te: " + num);
	System.out.println("O numero e: " + new_rand.rand);
	
	if(new_rand.verificaNum(num))
	    System.out.println("Acertas-te!");
	else
	    System.out.println("Erras-te!");
    }
}
