package test_java_monster_slayer;

import java.util.Scanner;

public class Test_Java_Monster_Slayer
{
    private int getOpt()
    {
	int opt;
	boolean KeyPressed = false;
	
	while(!KeyPressed)
	{
	    try
	    {
		opt = System.in.read();

		return opt;
	    }
	    catch(java.io.IOException ioex)
	    {
		System.out.println("Exception Caught. getOpt() - System.in.read()");
	    }
	    
	    try
	    {
		Thread.sleep(50);
		
	    }
	    catch(InterruptedException ex)
	    {
		System.out.println("Interrupted Exception (getOpt() - Thread.sleep())\n");
	    }
	}
    }

    public Test_Java_Monster_Slayer(){}
    
    public static void main(String[] args)
    {
	System.out.println("Testing this shit Language\n");
	
	System.out.println("1 - New Game");
	System.out.println("2 - Exit Game");
	
	Test_Java_Monster_Slayer game = new Test_Java_Monster_Slayer();
	
	if(game.getOpt() == 1)
	{
	    System.out.println("\nToo Bad");
	}
    }
}
