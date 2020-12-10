package edaula3;

public class ItDezReaisPositivos extends ItDezReais
{
    public ItDezReaisPositivos(DezReais dr)
    {
        super(dr);
    }
    
    @Override
    public boolean hasNext()
    {
        if(obj.get(super.index) > 0)
            return true;
        
        if(++index > obj.size())
            return false;
        
        return hasNext();
    }

    @Override
    public Double next()
    {
        return obj.get(++index);
    }
}