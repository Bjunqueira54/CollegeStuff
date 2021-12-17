package pa.edficha3;

public class Triangle implements Comparable<Object>
{
    private final double area;
    public Triangle(int h, int b)
    {
        this.area = ((h * b) / 2);
    }
    
    public double getArea() { return this.area; }

    @Override
    public int compareTo(Object o)
    {
        Figure aux = (Figure) o;
        
        double res = getArea() - aux.getArea();
        
        if(res < 0) return -1;
        if(res > 0) return 1;
        return 0;
    }
}