package pa.edficha6;

public class PrintTask implements Comparable<PrintTask>
{
    private static int DEFAULT_COUNTER = 0;
    private final String name;
    private final Integer startPage;
    private final Integer endPage;
    
    public PrintTask() {
        this.name = "Task #" + (++DEFAULT_COUNTER);
        startPage = 1;
        endPage = 10;
    }
    public PrintTask(String name, Integer startPage, Integer endPage) {
        this.name = name;
        this.startPage = startPage;
        this.endPage = endPage;
    }
    
    public int getNumberPages() { return (endPage - startPage); }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        
        str.append("Task: ").append(name).append("\n");
        str.append("Pages: ").append(getNumberPages());
        
        return str.toString();
    }

    @Override
    public int compareTo(PrintTask o) { return (getNumberPages() - o.getNumberPages()); }
}