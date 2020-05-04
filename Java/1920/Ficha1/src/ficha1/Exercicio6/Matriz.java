package ficha1.Exercicio6;

public class Matriz
{
    private int[][] mat;
    
    public Matriz()
    {
        this(5);
    }
    
    public Matriz(int size)
    {
        mat = new int[size][size]; //Matrixes have lines == columns
    }
    
    public void setMatrix(int[][] a)
    {
        if(a.length == getSize())
            for(int y = 0; y < a.length; y++)
                for(int x = 0; x < a[y].length; x++)
                    mat[y][x] = a[y][x];
    }
    
    public void setRandomMatrix()
    {
        for(int y = 0; y < getSize(); y++)
                for(int x = 0; x < getSize(); x++)
                    mat[y][x] = (int) (Math.random() * 100 ) + 1;;
    }
    
    public int getSize() { return mat.length; }
    
    public int getNumber(int y, int x)
    {
        if(y <= getSize() && x <= getSize())
            return mat[y][x];
        else
            throw new ArrayIndexOutOfBoundsException();
    }
    
    public void addMatrix(Matriz a, Matriz b)
    {
        if(a.getSize() == getSize() && b.getSize() == getSize())
            for(int y = 0; y < getSize(); y++)
                for(int x = 0; x < getSize(); x++)
                    mat[y][x] = a.getNumber(y, x) + b.getNumber(y, x);
    }

    @Override
    public String toString()
    {
        String str = "";
        
        for(int y = 0; y < getSize(); y++)
        {
            for(int x = 0; x < getSize(); x++)
            {
                str += mat[y][x] + " ";
            }
            str += '\n';
        }
        
        return str;
    }
}