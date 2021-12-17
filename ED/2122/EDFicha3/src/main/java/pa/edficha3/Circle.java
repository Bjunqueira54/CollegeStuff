package pa.edficha3;

public class Circle implements Comparable<Figure>
{
    private final double area;
    public Circle(int r)
    {
        this.area = 3.14 * r * r;
    }

    public double getArea() { return area; }
    
    @Override
    public int compareTo(Figure o)
    {
        double res = getArea() - o.getArea();
        
        if(res < 0) return -1;
        if(res > 0) return 1;
        return 0;
    }
}