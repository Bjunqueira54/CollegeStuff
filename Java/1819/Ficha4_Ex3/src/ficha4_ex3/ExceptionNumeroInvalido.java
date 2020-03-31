package ficha4_ex3;

public class ExceptionNumeroInvalido extends Exception
{
    public ExceptionNumeroInvalido(int numero)
    {
        super("Numero Invalido " + numero);
    }
}
