package ed_ficha5;

import java.util.ArrayList;

public class Main
{
    public static void main(String[] args)
    {
        ArrayList<Integer> list = new ArrayList<>();
        
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        
        //MyCollection.fill(list, 10);
        
        System.out.println(list);
        
        MyCollection.showReverse(list);
    }
}