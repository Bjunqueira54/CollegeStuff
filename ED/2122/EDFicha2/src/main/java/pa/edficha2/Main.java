package pa.edficha2;

import java.util.Arrays;
import java.util.Random;

public class Main
{
    private static int[] createArray(int v, int s, boolean r) {
        int m[] = new int[s];
        
        if(r)
        {
            for(int i = 0; i < s; i++)
                m[i] = i * 10;
            
            if((v % 10 != 0) || (0 > v) || (v > (s - 1) * 10))
                m[0] = v;
        }
        else
        {
            Random rand = new Random();
            
            int range = (Math.abs(v) < 10) ? 10 : Math.abs(v);
            
            for(int i = 0; i < s; i++)
                m[i] = rand.nextInt(range * 4) - range * 2;
            
            m[0] = v;
        }
        
        Arrays.sort(m);
        
        return m;
    }
    
    public static void main(String[] args) {
        int[] array = createArray(5, 10, false);
        
        for(int i : array)
            System.out.print(i + " ");
        System.out.println("");
        
        boolean ex1 = binRecursive(array, 5);
        boolean ex2 = binInteractive(array, 0);
        int ex3 = binIndex(array, 1);
        int ex4 = binCmp(array, 2);
        double ex5 = binPercentage(array, 3);
        
        System.out.println("binRecursive: " + (ex1 ? "Key Exists!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binInteractive: " + (ex2 ? "Key Exists!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binIndex: " + ((ex3 != -1) ? "Key Exists in " + ex3 + "!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binCmp: " + ((ex4 >= 0) ? "Key Exists in " + ex4 + "!\n" : "Key Doesn't Exist! It should be inserted into " + (Math.abs(ex4) - 1) + "!\n"));
        System.out.println("binPercentage: Key is greater than " + ex5 + "% of the numbers in the table!\n");
    }
    
    private static boolean binRecursive(int[] tab, int key) {
        int start = 0, end = tab.length, mid = (start + end) / 2;
        
        if(end == 0)
        {
            System.out.println("Empty Table\n");
            return false;
        }
        
        if(tab[mid] == key) return true;
        
        if(tab[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
        
        if(end < tab.length) end++;
        
        int[] newt = Arrays.copyOfRange(tab, start, end);
        
        return binRecursive(newt, key);
    }
    
    private static boolean binInteractive(int[] tab, int key) {
        int linf = 0, lsup = tab.length - 1;
        int mid = lsup / 2;
        
        do
        {
            if(tab[mid] == key) return true;
            
            if(tab[mid] < key)
                linf = mid + 1;
            else
                lsup = mid - 1;
            
            mid = (linf + lsup) / 2;
        }
        while(linf < lsup);
        
        return (tab[mid] == mid);
    }
    
    private static int binIndex(int[] tab, int key) {
        int linf = 0, lsup = tab.length - 1;
        int mid = tab.length / 2;
        
        do
        {
            if(tab[mid] == key) return mid;
            
            if(tab[mid] < key)
                linf = mid + 1;
            else
                lsup = mid - 1;
            
            mid = (linf + lsup) / 2;
        }
        while(linf < lsup);
        
        if(tab[mid] == key)
            return mid;
        
        return -1;
    }
    
    private static int binCmp(int[] tab, int key) {
        int linf = 0, lsup = tab.length - 1;
        int mid = tab.length / 2;
        
        do
        {
            if(tab[mid] == key) return mid;
            
            if(tab[mid] < key)
                linf = mid + 1;
            else
                lsup = mid - 1;
            
            mid = (linf + lsup) / 2;
        }
        while(linf < lsup);
        
        if(tab[mid] == key) return mid;
        
        if(tab[mid] < key)
            return -mid - 2;
        return -mid - 1;
    }
    
    private static double binPercentage(int[] tab, int key) {
        int pos = binCmp(tab, key);
        
        if(pos >= 0) return (double) pos / tab.length;
        
        int posInsert = -pos - 1;
        return posInsert / (double) tab.length;
    }
    
    private static int binNegativeSearch(int[] tab, int key) {
        int linf = 0, lsup = 0, mid = tab.length / 2;
        
        do
        {
            if(tab[mid] == key) return mid;
            
            if(key * tab[mid] >= 0)
                if(tab[mid] < key)
                    linf = mid + 1;
                else
                    lsup = mid - 1;
            else
                if(tab[mid] < key)
                    lsup = mid - 1;
                else
                    linf = mid + 1;
            
            mid = (linf + lsup) / 2;
        }
        while(linf < lsup);
        
        if(tab[mid] == key)
            return mid;
        return -1;
    }
}