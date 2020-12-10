package ed_aula2;

public class Point <A extends Number, B extends Number>
{
    private A x;
    private B y;
    
    public Point(A p1, B p2)
    {
        this.x = p1;
        this.y = p2;
    }

    @Override
    public String toString()
    {
        StringBuilder str = new StringBuilder();
        
        str.append(this.x).append(' ').append(this.y);
        
        return str.toString();
    }
    
    public void copy(Point<? extends A, ? extends B> p)
    {
        this.x = p.x;
        this.y = p.y;
    }
}
