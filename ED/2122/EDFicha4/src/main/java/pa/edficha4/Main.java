package pa.edficha4;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Main
{
    public static void main(String[] args)
    {
        DezReais dr = new DezReais();
        
        for(double i = 1; i <= 10; i++)
            dr.addDouble(i);
        
        System.out.println(dr);
        
        ItDezReais it = new ItDezReais(dr);
        
        while(it.hasNext())
            System.out.print(it.next() + " ");
        System.out.println("");
        
        DezReaisMutavel drm = new DezReaisMutavel();
        
        for(int i = 0; i < 10; i++)
            drm.addDouble(i * 0.1 + 5.0);
        
        ItDezReaisMutavel idrm = new ItDezReaisMutavel(drm);
        
        int count = 0;
        Double dbl;
        
        while(idrm.hasNext() && (dbl = idrm.next()) < 5.4)
            System.out.println(count++ + ": " + dbl);
        
        idrm.remove();
        
        System.out.println("");
        ItDezReaisMutavel idrm2 = new ItDezReaisMutavel(drm);
        
        count = 0;
        
        while(idrm2.hasNext())
            System.out.println(count++ + ": " + idrm2.next());
        
        System.out.println("Ex7-----------------");
        
        List<Double> al = new ArrayList<>();
        
        for(int i = 1; i <= 10; i++)
            al.add(i * 10.0);
        
        System.out.println("Max value in drm: " + genericMax(dr));
        System.out.println("Max value in idrm: " + genericMax(drm));
        System.out.println("Max value in ArraList: " + genericMax(al));
    }
    
    public static Double max(Iterable< Double> tab) {
        Iterator<Double> it = tab.iterator();
        Double currentMax = it.next(), aux;
        
        while(it.hasNext())
        {
            aux = it.next();
            if(aux > currentMax) currentMax = aux;
        }
        
        return currentMax;
    }
    
    public static <T extends Comparable<? super T>> T genericMax(Iterable<T> d) {
        Iterator<T> it = d.iterator();
        T max = it.next(), aux;
        
        while(it.hasNext())
        {
            aux = it.next();
            if(aux.compareTo(max) > 0) max = aux;
        }
        
        return max;
    }
}