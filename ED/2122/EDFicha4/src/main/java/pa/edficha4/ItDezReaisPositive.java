package pa.edficha4;

import java.util.Iterator;

public class ItDezReaisPositive extends ItDezReaisMutavel
{
    public ItDezReaisPositive(DezReaisMutavel dr) {
        super(dr);
    }

    @Override
    public boolean hasNext() {
        return nextPositiveIndex(lastPos + 1) >= 0;
    }

    @Override
    public Double next() {
        lastPos = nextPositiveIndex(++lastPos);
        return classRef.get(lastPos);
    }
    
    public int nextPositiveIndex(int from) {
        if(from >= classRef.size()) return -1;
        
        while(classRef.get(from) < 0)
            if(++from >= classRef.size()) return -1;
        
        return from;
    }
}