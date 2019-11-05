package testeed;

import java.util.ArrayList;

public class Main
{
    public static int maiores(int mat[], int valor)
    {
        int valores_maiores;
        int pos = pesquisa(mat, valor);

        if(pos < 0)
            pos = Math.abs(pos) + 1;
        
        if(pos >= mat.length)
            return 0;

        while(mat[pos] == valor)
        {
            pos++;
        }
        
        if(pos >= mat.length)
            return 0;

        valores_maiores = mat.length - pos;

        return valores_maiores;
    }
    
    public static <T> void f(T valor, ArrayList<T> asd)
    {
        asd.add(valor);
    }
    
    public static int pesquisa(int mat[], int valor)
    {
        for(int i = 0; i < mat.length; i++)
        {
            if(mat[i] == valor)
                return i;
        }
        
        int pos = 0;
        
        for(int i = mat.length - 1; i > 0; i--)
        {
            if(valor > mat[i])
            {
                pos = i;
                break;
            }
        }
        
        pos *= -1;
        
        return pos;
    }
    
    public static void main(String[] args)
    {
        int mat[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        int valor = 10;
        
        System.out.println("Nº de elementos maiores que "+ valor +": " + maiores(mat, valor));
    }
}