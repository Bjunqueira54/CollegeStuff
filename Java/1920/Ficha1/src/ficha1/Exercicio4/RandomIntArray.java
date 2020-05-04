package ficha1.Exercicio4;

public class RandomIntArray
{
    private final int[] mat;
    private int[] duped_mat;
    private int duped;
    
    public RandomIntArray()
    {
        mat = new int[20];
        duped_mat = new int[0];
        duped = 0;
        
        initDupedMat();
        populateMatrix();
    }
    
    private void populateMatrix()
    {
        int buffer;
        
        for(int i = 0; i < mat.length; i++)
        {
            while(true)
            {
                buffer = (int) (Math.random() * 100) + 1;
                
                if(hasNumber(buffer)) addToDupedMat(buffer);
                else break;
            }
            
            mat[i] = buffer;
        }
    }
    
    private boolean hasNumber(int num)
    {
        for(int i = 0; i < mat.length; i++)
            if(num == mat[i])
                return true;
        
        return false;
    }
    
    private void initDupedMat()
    {
        for(int i = 0; i < duped_mat.length; i++)
            duped_mat[i] = -1;
    }
    
    private void addToDupedMat(int num)
    {
        int[] newmat = new int[duped_mat.length + 1];
        
        System.arraycopy(duped_mat, 0, newmat, 0, duped_mat.length);
        
        newmat[newmat.length - 1] = -1;
        
        duped_mat = newmat;
        
        for(int i = 0; i < duped_mat.length; i++)
            if(duped_mat[i] == -1)
            {
                duped_mat[i] = num;
                break;
            }
        
        duped++;
    }
    
    public int showDuped() { return duped; }
    
    public String showDupedNumbers()
    {
        String str = "";
        
        for(int i = 0; i < duped_mat.length; i++)
            str += duped_mat[i] + " ";
        
        return str;
    }
    
    @Override
    public String toString()
    {
        String str = "";
        
        for(int i = 0; i < mat.length; i++)
            str += mat[i] + " ";
        
        return str;
    }
}