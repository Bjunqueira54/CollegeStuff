package ficha1;

import java.util.Scanner;

public class Ex1
{
    final int MIN = 0;
    final int MAX = 100;
    
    public Ex1() {}
    
    public void play()
    {
        Scanner sc = new Scanner(System.in);
        
        int randomNumber;
        int answer = 0;
        
        randomNumber = (int) (Math.random() * 100 ) + 1;
        
        while(true)
        {
            answer = sc.nextInt();
            
            if(answer != randomNumber)
                System.out.println("Wrong answer!");
            else
                break;
        }
        
        System.out.println("You are correct! The number was " + randomNumber + ".");
    }
}