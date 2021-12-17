package pa.edficha3;

abstract class Figure implements Comparable<Figure>
{
    public Figure(){}
    
    public abstract double getArea();
    
    @Override
    public int compareTo(Figure o)
    {
        double res = getArea() - o.getArea();
        
        if(res < 0) return -1;
        if(res > 0) return 1;
        return 0;
    }
    
}