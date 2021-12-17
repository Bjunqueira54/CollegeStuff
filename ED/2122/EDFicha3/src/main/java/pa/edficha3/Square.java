package pa.edficha3;

public class Square implements Comparable<Rectangle>
{
    private final double area;
    public Square(int h, int w)
    {
        this.area = h * w;
    }
    
    public double getArea() { return area; }

    @Override
    public int compareTo(Rectangle o)
    { 
        double res = getArea() - o.getArea();
        
        if(res < 0) return -1;
        if(res > 0) return 1;
        return 0;
    }
}
