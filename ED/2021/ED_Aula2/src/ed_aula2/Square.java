package ed_aula2;

public class Square extends Shape
{
    private final double area;
    
    public Square(double a)
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
        return "Square";
    }
}
