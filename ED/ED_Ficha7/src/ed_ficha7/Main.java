package ed_ficha7;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

public class Main
{
    public static int randInt(int min, int max)
    {
        Random rand = new Random();

        int randomNum = rand.nextInt((max - min) + 1) + min;

        return randomNum;
    }
    
    public static void main(String[] args)
    {
        Arvore<Integer> bt = new Arvore<>();
        
        ArrayList<Integer> array = new ArrayList();
        int a, b, i, hl, len;
        Integer temp;
        Random r = new Random();
        
        len = 1000000;
        
        for(i = 0; i < len; i++)
            array.add(new Integer(randInt(1, 1000000)));

        hl = len / 2;
        
        for(i = 0; i < hl; i++)
        {
            a = r.nextInt(len);
            b = r.nextInt(len);
            temp = array.get(a);
            array.set(a, array.get(b));
            array.set(b, temp);
        }
        
        Iterator it = array.iterator();
        
        while(it.hasNext())
            bt.insere((Integer) it.next());
        
        System.out.println("A Arvore tem " + bt.Tamanho() + " elementos");
        System.out.println("A Arvore tem " + bt.Profundidade() + " niveis");
        System.out.println("Devia ter " + Math.log(len) / Math.log(2));
    }
}