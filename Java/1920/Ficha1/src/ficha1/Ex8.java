package ficha1;

import java.util.Scanner;

public class Ex8
{
    private int[][] mat;
    
    public Ex8() {}
    
    public void play()
    {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Size of triangle: ");
        String input = sc.next();
        
        int size = Integer.parseInt(input);
        
        createTriangle(size);
        
        System.out.println(toString());
    }
    
    private void createTriangle(int size)
    {
        mat = new int[size][];
        
        for(int y = 0; y < size; y++)
        {
            mat[y] = new int[y+1];
            
            for(int x = 0; x < mat[y].length; x++)
            {
                if(y - 1 < 0)   // is this the first line?
                    mat[y][x] = 1;
                else if(x - 1 < 0)  //is this the first position?
                    mat[y][x] = 1;
                else if(x >= mat[y-1].length)   //is the current position bigger than the previous line length?
                    mat[y][x] = 1;
                else
                    mat[y][x] = mat[y-1][x] + mat[y-1][x-1];
            }
        }
    }

    @Override
    public String toString()
    {
        String str = "";
        
        for(int y = 0; y < mat.length; y++)
        {
            for(int x = 0; x < mat[y].length; x++)
            {
                str += mat[y][x] + " ";
            }
            
            str += '\n';
        }
        
        return str;
    }
}