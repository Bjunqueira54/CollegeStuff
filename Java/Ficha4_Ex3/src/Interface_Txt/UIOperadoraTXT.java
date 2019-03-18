package Interface_Txt;

import ficha4_ex3.Operadora;

public class UIOperadoraTXT
{
    String opcoes[] =
    {
        "Consulta saldo",
        "Faz Chamada",
        "Consulta saldo",
        "Carrega saldo",
        "Mostra cartoes por numero",
        "Mostra cartoes por saldo"
    };
    
    Operadora telco;

    public UIOperadoraTXT(Operadora telco)
    {
        this.telco = telco;
    }
    
    public void MostraOpcoes(String opcoes[])
    {
        for (String opcoe : opcoes)
        {
            System.out.println(opcoe);
        }
    }
    
    public void executa()
    {
        int opcao = 1;
        
        while(true)
        {
            MostraOpcoes(opcoes);
            
            switch(opcao)
            {
                case 0:
                    return;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        }
    }
}
