package pa.edficha6;

public class Main
{
    public static void main(String[] args)
    {
        Printer p1 = new Printer();
        Printer p2 = new Printer();
        Printer p3 = new Printer();
        
        PrinterManager pm = new PrinterManager();
        
        pm.addPrinter(p1.getName(), p1);
        pm.addPrinter(p2.getName(), p2);
        pm.addPrinter(p3.getName(), p3);
        
        System.out.println(pm.getAllPrinterNames());
        System.out.println(pm.getPrinter("Default #1").toString());
        
        pm.removePrinter("Default #2");
        System.out.println(pm.getAllPrinterNames());
        
        PrintTask t1 = new PrintTask();
        PrintTask t2 = new PrintTask();
        
        pm.print(t1);
        pm.print(t2);
    }
}