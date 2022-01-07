package pa.edficha6;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;

public class PrinterManager
{
    private Map<String, Printer> map;
    private Queue<Printer> printers = new PriorityQueue<>((Printer o1, Printer o2) -> o1.getNumberTasks() - o2.getNumberTasks());
    
    public PrinterManager() {
        map = new HashMap<>();
    }
    public PrinterManager(Map<String, Printer> m) {
        this.map = m;
    }
    
    public void addPrinter(String key, Printer printer) {
        map.put(key, printer);
        printers.add(printer);
    }
    public void addPrinter(Printer printer) {
        map.put(printer.getName(), printer);
        printers.add(printer);
    }
    public Printer getPrinter(String name) { return map.get(name); }
    public Set<String> getAllPrinterNames() { return map.keySet(); }
    public void removePrinter(String key) { map.remove(key); }
    public boolean checkPrinter(String key) { return map.containsKey(key); }
    public void print(PrintTask pt) {
        Printer aux = printers.poll();
        aux.addTask(pt);
        printers.add(aux);
    }
}