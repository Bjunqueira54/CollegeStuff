package ficha1.Exercicio6;

public class Ex6
{
    public Ex6() {}
    
    public void play()
    {
        Matriz mat1 = new Matriz();
        Matriz mat2 = new Matriz();
        
        mat1.setRandomMatrix();
        mat2.setRandomMatrix();
        
        System.out.println(mat1.toString());
        System.out.println(mat2.toString());
        
        Matriz res = new Matriz();
        
        res.addMatrix(mat1, mat2);
        
        System.out.println(res.toString());
    }
}