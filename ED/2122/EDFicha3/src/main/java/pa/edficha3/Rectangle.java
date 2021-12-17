package pa.edficha3;

public class Rectangle extends Figure
{
    private final double area;
    
    public Rectangle(int h, int w)
    {
        area = h * w;
    }
    
    @Override
    public double getArea() { return area; }
}