package edaula3;

import java.util.Iterator;

public class EDAula3
{
    public static void main(String[] args)
    {
        DezReais dr = new DezReais();
        DezReaisMutavel drm = new DezReaisMutavel();
        
        for(int i = 0; i < 10; i++)
            dr.add(Math.random());
        
        for(int i = 0; i < 10; i++)
            drm.add(Math.random());
        
        Iterator it = dr.iterator();
        Iterator itm = drm.iterator();
        
        while(it.hasNext())
            System.out.println(it.next());
        
        System.out.println("///////////////////");
        
        while(itm.hasNext())
            System.out.println(itm.next());
        
        itm = drm.iterator();
        while(itm.hasNext())
            if((Double) itm.next() > 0.5)
                break;
        
        //itm.remove();
        
        itm = drm.iterator();
        
        System.out.println("///////////////////");
        
        while(itm.hasNext())
            System.out.println(itm.next());
        
        System.out.println("///////////////////");
        
        it = dr.iterator();
        itm = dr.iterator();
        
        Double max_normal = -900000000d;
        Double max_mutavel = -900000000d;
        
        while(it.hasNext())
        {
            Double temp = (Double) it.next();
            
            if(temp > max_normal)
                max_normal = temp;
        }
        
        while(itm.hasNext())
        {
            Double temp = (Double) itm.next();
            
            if(temp > max_mutavel)
                max_mutavel = temp;
        }
        
        System.out.println("max normal: " + max_normal);
        System.out.println("max mutavel: " + max_mutavel);
        
        System.out.println("///////////////////");
        
        System.out.println(maior(dr));
    }
    
    public static <T extends Comparable<? super T>> T maior(Iterable<T> obj)
    {
        Iterator<T> it = obj.iterator();
        
        T m, temp;
        
        m = it.next();
        
        while(it.hasNext())
        {
            temp = it.next();
            
            if(temp.compareTo(m) > 0)
                m = temp;
        }
        
        return m;
    }
}