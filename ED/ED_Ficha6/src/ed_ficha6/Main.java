package ed_ficha6;

import java.util.Iterator;
import java.util.PriorityQueue;

public class Main
{
    public static void main(String[] args)
    {
        GestorImpressoras gestor = new GestorImpressoras();
        Impressora printer1 = new Impressora("Impressora 1", 1337, "HP", "Pavillon", "idkwat2do", "lel.420");
        Impressora printer2 = new Impressora("Impressora 2", 360, "Toshiba", "Satellite", "pc.n4m3s.4.printers", "69");
        
        gestor.adicionaImpressora(printer1);
        gestor.adicionaImpressora(printer2);
        
        System.out.println(gestor.getNomes());
        
        gestor.getPrinter("Impressora 1").show();
        gestor.getPrinter("Impressora 2").show();
        
        gestor.removeImpressora(printer2.getNome());
        
        System.out.println(gestor.getNomes());
        
        System.out.println("\n\nPRIORITY QUEUE PART!\n\n");
        
        Trabalho t, t1 = new Trabalho("T1", 3), t2 = new Trabalho("T2", 2);
        
        System.out.println("Fila de espera: ");
        gestor.mostraFila();
        
        System.out.println("-> Fila de espera com t1");
        gestor.imprime(t1);
        gestor.mostraFila();
        
        System.out.println("->Fila de espera com t1 e t2");
        gestor.imprime(t2);
        gestor.mostraFila();
    }
}