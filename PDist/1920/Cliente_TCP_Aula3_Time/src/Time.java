import java.io.Serializable;

public class Time implements Serializable
{
    public int hour;
    public int minute;
    public int second;
    
    public static final long serialVersionUID = 1;
    
    public Time() {}

    @Override
    public String toString() 
    {
        return String.format("%02d:%02d:02d", hour, minute, second);
    }
}