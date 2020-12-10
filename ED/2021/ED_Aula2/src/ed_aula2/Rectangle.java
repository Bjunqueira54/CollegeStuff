package ed_aula2;

public class Rectangle extends Shape
{
    private final double area;
    
    public Rectangle(int a)
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
        return "Rectangle";
    }
}