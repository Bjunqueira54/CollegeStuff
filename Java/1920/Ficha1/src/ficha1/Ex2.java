package ficha1;

import java.util.Scanner;

public class Ex2
{
    private int MIN = 1;
    private int MAX = 1000000;
    
    public Ex2() {}
    
    public void play()
    {
        Scanner sc = new Scanner(System.in);
        int buffer;
        char confirmation;
        
        System.out.println("Think of a number between " + MIN + " and " + MAX + ".");
        
        do
        {
            buffer = (MIN + MAX) / 2;
            
            System.out.println("Is your number greater than " + buffer + "?(Y/y to Confirm)");
            
            confirmation = sc.next().charAt(0);
            
            if(Character.toLowerCase(confirmation) == 'y')
                MIN = buffer + 1;
            else
                MAX = buffer;
        }
        while(MIN != MAX);
        
        System.out.println("Your number is: " + MAX);
    }
}