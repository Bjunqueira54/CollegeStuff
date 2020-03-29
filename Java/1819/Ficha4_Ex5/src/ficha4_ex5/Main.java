package ficha4_ex5;

import java.util.Arrays;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        PublicidadeGastronomica publicidade = new PublicidadeGastronomica();
        GaleriaDeSabores gds = new GaleriaDeSabores(publicidade);
        BurgerKing bk = new BurgerKing(publicidade);
        Italia italia = new Italia(publicidade);
        String [] opcoes = {"1 - Vegetariano\n", "2 - Dieta\n", "3 - Italiano\n",
            "4 - Fast food\n", "5 - Geral\n", "0 - Sair\n"};
        
        int opcao = -1;
        
        //Galeria de Sabores
        publicidade.addVegetariano(gds, "Empadao de Tofu");
        publicidade.addVegetariano(gds, "Requeijao com molho de ervas e mel");
        
        publicidade.addItaliano(gds, "Tagliateli  a la carbonara");
        publicidade.addItaliano(gds, "Risoto  de legumes");
        publicidade.addItaliano(gds, "Gelado de Cafe");
        
        publicidade.addDieta(gds, "Salada Mediterranica");
        publicidade.addDieta(gds, "Salada niçoise");
        publicidade.addDieta(gds, "Maça assada");
        
        publicidade.addGeral(gds, "Bifes de  peru  com molho  de  cenoura");
        publicidade.addGeral(gds, "Bacalhau  com natas");
        publicidade.addGeral(gds, "Salmao Grelhados");
        publicidade.addGeral(gds, "Arroz Doce");
        
        //Burger King
        publicidade.addFastFood(bk, "FishBurger");
        publicidade.addFastFood(bk, "ChickenBurger");
        publicidade.addFastFood(bk, "Tarte  de maçã  com gelado");
        
        publicidade.addVegetariano(bk, "BeanBurger");
        publicidade.addVegetariano(bk, "TofuBurger");
        publicidade.addVegetariano(bk, "Sorvete de Maça");
        
        //Italia
        publicidade.addItaliano(italia, "Lasanha  de dourada  com Mozarella");
        publicidade.addItaliano(italia, "Lasanha  do mar");
        publicidade.addItaliano(italia, "Tiramisu");
        
        publicidade.addGeral(italia, "Lulas  recheadas  com presunto");
        publicidade.addGeral(italia, "Leite Creme");
        
        Scanner sc = new Scanner(System.in);
        
        while(opcao != 0)
        {
            for (int i = 0; i < opcoes.length; i++)
            {
                System.out.print( opcoes[i] );
            }
            
            opcao = sc.nextInt();
            
            switch(opcao)
            {
                case 1:
                    System.out.println( publicidade.divulgaVegetariano() );
                    break;
                case 2:
                    System.out.println( publicidade.divulgaDieta() );
                    break;
                case 3:
                    System.out.println( publicidade.divulgaItaliano() );
                    break;
                case 4:
                    System.out.println( publicidade.divulgaFastFood() );
                    break;
                case 5:
                    System.out.println( publicidade.divulgaGeral() );
                    break;
                case 0:
                    return;
                default:
                    break;
            }
        }
    }
}