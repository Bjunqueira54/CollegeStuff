package gameLogic.Ship;

public class Bridge extends Ship
{
    private int id = 1;
    
    public Bridge()
    {
        super();
        addDoor(5);
        addDoor(8);
    }
    
    public int getId() { return id; }
}
