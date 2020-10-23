package edmainclass;

public class Main
{
    public static void main(String[] args)
    {
        int tab[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
        
        int j, chave = 4;
        int result;
        double d;
        boolean res;
        
        res = binInterativo(tab, chave);
        result = bin(tab, chave);
        
        System.out.println(result);
        
        if(res)
            System.out.println("Chave existe\n");
        else
            System.out.println("Chave nao existe\n");
    }
    
    public static boolean binInterativo(int tab[], int chave)
    {
        int linf = 0, lsup = tab.length-1;
        int meio = lsup / 2;
        
        do
        {
            if(tab[meio] == chave)
                return true;
            
            if(tab[meio] < chave)
                linf = meio + 1;
            else
                lsup = meio - 1;
            
            meio = (linf + lsup) / 2;
        }
        while(linf<lsup);
        
        if(tab[meio] == chave)
            return true;
        
        return false;
    }
    
    public static double percent(int tab[], int valor)
    {
        int pos = bin(tab, valor);
        
        if(pos >= 0)
            return (double) pos/tab.length;
        
        int posInsert = -pos - 1;
        
        return posInsert/(double)tab.length;
    }
    
    public static int bin(int tab[], int chave)
    {
        int linf = 0, lsup = tab.length, meio = tab.length/2;
        
        do
        {
            if(tab[meio] == chave)
                return 0;
            
            if(tab[meio] < chave)
                linf = meio + 1;
            else
                lsup = meio - 1;
            
            meio = (linf + lsup) / 2;
        }
        while(linf < lsup);
        
        if(tab[meio] == chave)
            return 0;
        else if(tab[meio] < chave)
            return -meio - 2;
        
        return -meio - 1;
    }
    
    public static boolean testaRepetidos(int tab[], int chave)
    {
        int j = bin(tab, chave);
        
        if(j < 0)
            return false;
        
        if(j == 0)
            if(tab[1] != chave)
                return false;
            else
                return true;
        
        if(j == tab.length)
            if(tab[j - 1] != chave)
                return false;
             else
                return true;
        
        if((tab[j] == tab[j - 1]) || (tab[j] == tab[j + 1]))
            return true;
        
        return false;
    }
    
    public static int procuraMenor(int tab[], int chave)
    {
        int j, pos = bin(tab, chave);
        
        if(pos == -1 || pos == 0)
            return chave;
        
        if(pos < 0)
            pos = -pos - 1;
        
        return tab[pos - 1];
    }
    
    public static int pesquisaBinariaNeg(int tab[], int chave)
    {
        int linf = 0, lsup = tab.length - 1, meio = tab.length / 2;
        
        do
        {
            if(tab[meio] == chave)
                return meio;
            if(chave * tab[meio] >= 0)
                if(tab[meio] < chave)
                    linf = meio + 1;
                else
                    lsup = meio - 1;
            else
                if(tab[meio] < chave)
                    lsup = meio - 1;
                else
                    linf = meio + 1;
            
            meio = (linf + lsup) / 2;
        }
        while(linf < lsup);
        
        if(tab[meio] == chave)
            return meio;
        
        return -1;
    }
    
    public static int maiorQueIndice(int tab[])
    {
        for(int j = 0; j < tab.length; j++)
            if(tab[j] > j)
                return j;
        
        return -1;
    }
}