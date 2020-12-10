package ed_aula2;

public abstract class Shape implements Comparable<Shape>
{
    public abstract double getArea();

    @Override
    public int compareTo(Shape t)
    {
        return (int) (this.getArea() - t.getArea());
    }
}