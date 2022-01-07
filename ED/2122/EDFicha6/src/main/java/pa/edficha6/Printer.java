package pa.edficha6;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Printer
{
    ////////////////
    ///Properties///
    ////////////////
    
    private static int DEFAULT_COUNTER = 0;
    private final String name;
    private final Integer port;
    private final String brand;
    private final String model;
    private final Integer driver;
    private final Double version;
    
    private final Queue<PrintTask> queue = new PriorityQueue<>(
            (PrintTask a, PrintTask b) ->
                    a.getNumberPages() - b.getNumberPages());;
    
    //////////////////
    ///Constructors///
    //////////////////
    
    public Printer() {
        String str = "Default #" + ++DEFAULT_COUNTER;
        
        name = str;
        port = 1337;
        brand = str;
        model = str;
        driver = 1;
        version = 1.0;
    }
    public Printer(String name, Integer port, String brand, String model, Integer driver, Double version) {
        this.name = name;
        this.port = port;
        this.brand = brand;
        this.model = model;
        this.driver = driver;
        this.version = version;
    }
    
    /////////////////////
    ///Printer Methods///
    /////////////////////
    
    public String getName() { return this.name; }
    public Integer getPort() { return port; }
    public String getBrand() { return brand; }
    public String getModel() { return model; }
    public Integer getDriver() { return driver; }
    public Double getVersion() { return version; }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        
        str.append(this.name).append(" ");
        str.append(this.port).append(" ");
        str.append(this.brand).append(" ");
        str.append(this.model).append(" ");
        str.append(this.driver).append(" ");
        str.append(this.version);
        
        return str.toString();
    }
    
    //////////////////
    ///Task Methods///
    //////////////////
    
    public void addTask(PrintTask t) { queue.add(t); }
    public boolean hasNextTask() { return (queue.peek() != null); }
    public PrintTask nextTask() { return queue.peek(); }
    public int getNumberTasks() { return queue.size(); }
}