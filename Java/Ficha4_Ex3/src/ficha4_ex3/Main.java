package ficha4_ex3;

public class Main
{
    public static void main(String[] args) throws ExceptionNumeroInvalido
    {
        Operadora nowo = new Operadora("NOWO");
        
        Cartao cli1 = new Tagarela(910529131);
        
        nowo.AcrescentaCartao(cli1);
        
        nowo.CarregaCartao(910529131, 10);
    }
}