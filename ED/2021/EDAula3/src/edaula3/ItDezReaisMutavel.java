package edaula3;

import java.util.ConcurrentModificationException;

public class ItDezReaisMutavel extends ItDezReais
{
    private DezReaisMutavel objm;
    private int indexm = -1;
    private int mod = 0;
    
    public ItDezReaisMutavel(DezReaisMutavel cl)
    {
        super(cl);
        this.objm = cl;
    }
    
    @Override
    public void remove()
    {
        DezReaisMutavel aux = (DezReaisMutavel) obj;
        aux.remove(indexm);
        mod++;
        checkMod();
    }
    
    public void add(Double n)
    {
        objm.add(n);
        mod++;
        checkMod();
    }
    
    private void checkMod()
    {
        if(this.mod != objm.getMod())
            throw new ConcurrentModificationException();
    }
}