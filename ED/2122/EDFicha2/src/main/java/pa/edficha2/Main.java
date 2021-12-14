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
        
        System.out.print("[");
        for(int i = 0; i < array.length; i++)
        {
            System.out.print(array[i]);
            
            if(i+1 < array.length)
                System.out.print(" ");
        }
        System.out.println("]");
        
        boolean ex1 = binRecursive(array, 3);
        boolean ex2 = binInteractive(array, 3);
        int ex3 = binIndex(array, 1);
        int ex4 = binSearchPos(array, 2);
        double ex5 = binPercentageLowerThanValue(array, 3);
        
        System.out.println("binRecursive: " + (ex1 ? "Key Exists!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binInteractive: " + (ex2 ? "Key Exists!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binIndex: " + ((ex3 != -1) ? "Key Exists in " + (ex3 + 1) + "!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binCmp: " + ((ex4 >= 0) ? "Key Exists in " + (ex4 + 1) + "!\n" : "Key Doesn't Exist! It should be inserted into " + (Math.abs(ex4)) + "!\n"));
        System.out.println("binPercentage: Key is greater than " + (ex5 * 100) + "% of the numbers in the table!\n");
    }
    
    private static boolean binRecursive(int[] a, int v) {
        int start = 0, end = a.length, mid = (end + start) / 2;
        
        if(end == 0)
            return false;
        if(a[mid] == v)
            return true;
        
        if(a[mid] > v) end = mid - 1;
        else start = mid + 1;
        
        if(end < a.length) end++;
        
        int[] NewArray = Arrays.copyOfRange(a, start, end);
        
        return binRecursive(NewArray, v);
    }
    private static boolean binInteractive(int[] a, int v) {
        int start = 0, end = a.length - 1, mid = end / 2;
        
        do
        {
            if(a[mid] == v) return true;
            if(a[mid] < v) start = mid + 1;
            else end = mid - 1;
            
            mid = (start + end) / 2;
        }
        while(start < end);
        
        return (a[mid] == v);
    }
    private static int binIndex(int[] a, int v) {
        int start = 0, end = a.length - 1, mid = end / 2;
        
        do
        {
            if(a[mid] == v) return mid;
            if(a[mid] < v) start = mid + 1;
            else end = mid - 1;
            
            mid = (start + end) / 2;
        }
        while(start < end);
        
        if(a[mid] == v)
            return mid;
        else
            return -1;
    }
    private static int binSearchPos(int[] a, int v) {
        int start = 0, end = a.length - 1, mid = a.length / 2;
        
        do
        {
            if(a[mid] == v) return mid;
            if(a[mid] < v) start = mid + 1;
            else end = mid - 1;
            
            mid = (start + end) / 2;
        }
        while(start < end);
        
        if(a[mid] == v) return mid;
        
        if(a[mid] < v) return -mid-2;
        return -mid-1;
    }
    private static double binPercentageLowerThanValue(int[] a, int v) {
        int pos = binSearchPos(a, v);
        
        if(pos >= 0) return (double) pos / a.length;
        
        pos = Math.abs(pos);
        
        return (double) (pos - 1) / a.length;
    }
}