package ed_ficha4;

import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        DezReais dr = new DezReais();
        
        try
        {
            while(true)
            {
                System.out.println("Input a number (decimal is fine):");
                dr.add(sc.nextDouble());
            }
        }
        catch(DezReaisFullCapacityException ex)
        {
            System.out.println("Cannot add any more numbers to that object");
        }
    }
}