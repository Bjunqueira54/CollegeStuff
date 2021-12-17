package pa.edficha3;

public class Point <A extends Number, B extends Number>
{
    private A p1;
    private B p2;
    
    public Point(A a, B b)
    {
        p1 = a;
        p2 = b;
    }
    
    public void copy(Point<? extends A, ? extends B> p)
    {
        p1 = p.p1;
        p2 = p.p2;
    }

    @Override
    public String toString() { return (p1 + ", " + p2); }
}