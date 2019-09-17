package test_exame;

import java.util.List;
import java.util.ArrayList;

class Test_Exame
{

    static private double somaRaizesQuadradas = 0;
    private double n;

    public Test_Exame(String  n) throws Exception
    {
        try
        {
            try
            {
                this.n = Double.parseDouble(n);
            }
            catch(NumberFormatException e)
            {
                return;
            }

            if(this.n < 0)
            {
                throw new Exception();
            }

            somaRaizesQuadradas += Math.sqrt(this.n);
        }
        finally
        {
            System.out.println("f1");
        }
    }
    
    public static void main(String[] args)
    {
        System.out.println("m1");
        
        try
        {
            new Test_Exame("4.0");
            new Test_Exame("A.0");
            new Test_Exame("9.0");
            new Test_Exame("-4.0");
            new Test_Exame("9");
        }
        catch(Exception e)
        {
            System.out.println("e1");
            return;
        }
        finally
        {
            System.out.println("f2: " + somaRaizesQuadradas);
        }
    }
} 