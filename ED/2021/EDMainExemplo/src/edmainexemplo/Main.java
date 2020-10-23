/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edmainexemplo;

import java.util.Arrays;
import java.util.Random;

/**
 *
 * @author gothicdread
 */
public class Main
{
    private static long stopTime;
    private static long startTime;
    
    static void ex1b(long n)
    {
            long soma=0;
            startTimer();
            
            for(long i=0;i<n;i++)
                soma++;
            
            System.out.println("Soma="+soma);
            
            stopTimer();
            showTime();
    }

    static void ex1a(long n)
    {
            long soma=0;
            startTimer();
            
            for(long i=0;i<n;i++)
                for(long j=0;j<n;j++)
                    soma++;
            
            System.out.println("Soma="+soma);
            
            stopTimer();
            showTime();
    }

    private static void showTime()
    {
        long interval = stopTime-startTime;
        long secs = interval/1000000000L;
        long decs = interval-secs*1000000000L;
        
        decs /= 100000000L;
        System.out.println("secs="+secs+"."+decs);
    }

    private static void stopTimer()
    {
        stopTime=System.nanoTime();
    }

    private static void startTimer()
    {
        startTime=System.nanoTime();
    }
    
    static int[] criaArrayCom(int valor, int dimensao, boolean diferentes)
    {
        int m[] = new int[dimensao];
        
        if(diferentes)
        {
            for(int i = 0; i < dimensao; i++)
                m[i] = i*10;
            
            if((valor % 10 != 0) || (0 > valor) || (valor > (dimensao-1) * 10))
                m[0]=valor;
        }
        else
        {
            Random r = new Random();
            int gama = (Math.abs(valor) < 10) ? 10 : Math.abs(valor);
            
            for(int i = 0; i < dimensao; i++)
                m[i] = r.nextInt(gama * 4) - gama * 2;
            m[0] = valor;
        }
        
        Arrays.sort(m);
        
        return m;
    }
    
    private static boolean numExistsRecursive(int[] array, int valor, int index)
    {
        if(index >= array.length)
            return false;
        else if(array[index] == valor)
            return true;
        else
            return numExistsRecursive(array, valor, ++index);
    }
    
    private static boolean numExistInteractive(int[] array, int valor)
    {
        int min, max;
        min = 0;
        max = array.length - 1;
        
        do
        {
            int mid = (int) (max + min) / 2;
            
            if(array[mid] == valor)
                return true;
            else if(array[mid] > valor)
                max = mid - 1;
            else
                min = mid + 1;
        }
        while(min < max);
        
        return false;
    }
    
    public static boolean numExists(int[] array, int valor)
    {
        //Ficha 2 Ex 1
        /*int index = (int) (0 + array.length) / 2;
        
        if(valor > array[index])
            return numExistsRecursive(array, valor, index);
        else
            return numExistsRecursive(array, valor, 0);*/
        
        //Ficha 2 Ex 2
        return numExistInteractive(array, valor);
    }
    
    public static int getNumIndex(int[] array, int key)
    {
        int min, max;
        min = 0;
        max = array.length - 1;
        
        do
        {
            int mid = (int) (max + min) / 2;
            
            if(array[mid] == key)
                return mid;
            else if(array[mid] > key)
                max = mid - 1;
            else
                min = mid + 1;
        }
        while(min < max);
        
        return -1;
    }
    
    public static int getNumIndexInsert(int[] array, int key)
    {
        int min = 0, max = array.length - 1;
        int mid = 0;
        
        do
        {
            mid = (int) (min + max) / 2;
            
            if(array[mid] == key)
                return mid;
            else if(key < array[mid])
                max = mid - 1;
            else
                min = mid + 1;
        }
        while(min < max);
        
        return mid * -1;
    }
    
    public static float getNumLowerPercentage(int[] array, int key)
    {
        int index = getNumIndex(array, key);
        
        if(index < 0)
            return 0;
        
        return (float) index/ array.length;
    }
    
    public static int getNumBetweenKeys(int[] array, int key1, int key2)
    {
        int index1 = getNumIndexInsert(array, key1);
        int index2 = getNumIndexInsert(array, key2);
        
        if(index1 < 0)
            index1 = (index1 + 1) * -1;
        
        if(index2 < 0)
            index2 = (index2 + 1) * -1;
        
        if(index1 > index2)
            return index1 - index2;
        else
            return index2 - index1;
    }
    
    public static boolean numExistsRepeated(int[] array, int key)
    {
        int index = getNumIndex(array, key);
        
        if(index < 0)
            return false;
        
        return array[index - 1] == key || array[index + 1] == key;
    }
    
    public static int getHighestNum(int[] array, int key)
    {
        int index = getNumIndex(array, key);
        
        if(index < 0)
            index = (index + 1) * -1;
        else
            index = index - 1;
        
        return array[index];
    }

    public static int getNumIndexFromInvertedArray(int[] array, int key)
    {
        int min = 0, max = array.length -1, mid = (int) (max + min) / 2;
        
        do
        {
            
        }
        while(min < max);
        
        if(array[mid] == key)
            return mid;
        else
            return -1;
    }
    
    public static void main(String[] args) 
    {
        int valor = 54;
        int[] array = criaArrayCom(54, 2500, true);
        
        int index = getNumIndexInsert(array, valor);
        
        if(index >= 0)
            System.out.println("Numero " + valor + " existe na posicao " + index);
        else
            System.out.println("Numero " + valor + " não existe, mas pode ser inserido na posição " + Math.abs(index + 1));
        
        System.out.println(getNumLowerPercentage(array, valor) + " dos numeros são menores que " + valor);
        
        System.out.println("A gama de numero de valores entre 0 e " + valor + " é " + getNumBetweenKeys(array, 0, valor));
        
        System.out.println("Existem repetidos de " + valor + ": " + numExistsRepeated(array, valor));
        
        System.out.println("Maior numero abaixo de " + valor + "(ou " + valor + " se não existir): " + getHighestNum(array, valor));
    }
}