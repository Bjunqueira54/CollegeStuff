package InterfaceTexto;

import ficha5_ex1.Elevador;
import ficha5_ex1.Piso1;
import ficha5_ex1.Piso2;
import ficha5_ex1.RC;
import java.util.Scanner;

public class Interface
{
    Scanner sc;
    Elevador elevator;

    public Interface()
    {
        sc = new Scanner(System.in);
        elevator = new Elevador();
    }
    
    private String getPiso()
    {
        if(elevator.getEstado().getClass() == RC.class)
            return "R/C";
        if(elevator.getEstado().getClass() == Piso1.class)
            return "1";
        if(elevator.getEstado().getClass() == Piso2.class)
            return "2";

        return "N/A";
    }
    
    private String printMenu()
    {
        return "Piso: " + getPiso() + "\n1 - Go Up\n2 - Go Down\n0 - Sair\n";
    }
    
    public void start()
    {
        int opt = -1;
        
        while(opt != 0)
        {
            printMenu();
            
            opt = sc.nextInt();
            
            switch(opt)
            {
                case 1:
                    elevator.goUp();
                    break;
                case 2:
                    elevator.goDown();
                    break;
                case 0:
                    return;
                default:
                    break;
            }
        }
    }
}