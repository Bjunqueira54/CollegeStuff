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
        
        int[] diff_array = createArray(15, 10, true);
        System.out.print("[");
        for(int i = 0; i < array.length; i++)
        {
            System.out.print(diff_array[i]);
            
            if(i+1 < array.length)
                System.out.print(" ");
        }
        System.out.println("]");
        
        int[] ex9_array = {3,6,8, -10,-3,-2,-1};
        
        boolean ex1 = binRecursive(array, 3);
        boolean ex2 = binInteractive(array, 3);
        int ex3 = binIndex(array, 1);
        int ex4 = binSearchPos(array, 2);
        double ex5 = binPercentageLowerThanValue(array, 3);
        int ex6 = numbersInRange(diff_array, 10, 50);
        boolean ex7 = repeatInArray(array, 5);
        int ex8 = getBiggestLower(diff_array, 89);
        int ex9 = searchWeirdArrayPos(ex9_array, -5);
        int ex10 = searchHigherThanIndex(array);
        
        System.out.println("binRecursive: " + (ex1 ? "Key Exists!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binInteractive: " + (ex2 ? "Key Exists!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binIndex: " + ((ex3 != -1) ? "Key Exists in " + (ex3 + 1) + "!\n" : "Key Doesn't Exist!\n"));
        System.out.println("binSearchPos: " + ((ex4 >= 0) ? "Key Exists in " + (ex4 + 1) + "!\n" : "Key Doesn't Exist! It should be inserted into " + (Math.abs(ex4)) + "!\n"));
        System.out.println("binPercentageLowerThanValue: Key is greater than " + (ex5 * 100) + "% of the numbers in the table!\n");
        System.out.println("numbersInRange: There's " + ex6 + " numbers in the chosen key range.\n");
        System.out.println("repeatInArray: The chosen key is " + (ex7 ? "" : "not ") + "repeated in the array.\n");
        System.out.println("getBiggestLower: The biggest value under the chosen key is " + ex8 + ".\n");
        System.out.println("searchWeirdArrayPos: The chosen key " + (ex9 != -1 ? "exists in position " + ex9 + ".\n" : "doesn't exist in the array.\n"));
        System.out.println("searchHigherThanIndex: " + (ex10 != -1 ? "Position " + ex10 : "Doesn't exist"));
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
    private static int numbersInRange(int[] a, int v1, int v2) {
        int pos1 = binSearchPos(a, v1), pos2 = binSearchPos(a, v2);
        
        if(pos1 < 0) pos1 = -pos1 - 1;
        if(pos2 < 0) pos2 = -pos2 - 1;
        else pos2++;
        
        return pos2 - pos1;
    }
    private static boolean repeatInArray(int[] a, int v) {
        int pos = binIndex(a, v);
        
        if(pos < 0) return false;
        
        if(pos == 0)
            return a[pos] == a[pos + 1];
        
        if(pos == a.length - 1)
            return a[pos] == a[pos - 1];
        
        return (a[pos - 1] == a[pos] || a[pos + 1] == a[pos]);
    }
    private static int getBiggestLower(int[] a, int v) {
        int pos = binSearchPos(a, v);
        
        if(pos < 0) pos = -pos - 1;
        
        if(pos == 0) return v < a[pos] ? v : a[pos];
        else return a[pos - 1];
    }
    private static int searchWeirdArrayPos(int[] a, int v) {
        int start = 0, end = a.length - 1, mid = end / 2;
        
        do
        {
            if(a[mid] == v) return mid;

            if(v * a[mid] >= 0)
            {
                if(a[mid] < v) start = mid + 1;
                else end = mid - 1;
            }
            else
            {
                if(a[mid] < v) end = mid - 1;
                else start = mid + 1;
            }

            mid = (start + end) / 2;
        }
        while(start < end);
        
        if(a[mid] == v) return mid;
        return -1;
    }
    private static int searchHigherThanIndex(int[] a) {
        //LINEAR COMPLEXITY SOLUTION
        /*
        for(int i = 0; i < a.length; i++)
            if(a[i] > i)
                return i;
        return -1;*/
        
        //LOGARITMIC SOLUTION
        int start = 0, end = a.length, mid = end / 2;
        
        do
        {
            if(a[mid] > mid) end = mid;
            else start = mid + 1;
            
            mid = (start + end) / 2;
        }
        while(start < end);
        
        if(a[mid] > mid) return mid;
        
        return -1;
    }
}