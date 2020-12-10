package ed_aula2;

public class Triangle extends Shape
{
    private final double area;
    
    public Triangle(double a)
    {
        this.area = a;
    }

    @Override
    public double getArea()
    {
        return this.area;
    }
    
    @Override
    public String toString()
    {
        return "Triangle";
    }
}