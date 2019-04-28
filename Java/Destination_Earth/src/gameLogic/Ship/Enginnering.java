package gameLogic.Ship;

public class Enginnering extends Ship
{
    private int id = 9;

    public Enginnering()
    {
        super();
        addDoor(3);
        addDoor(12);
    }
    
    public int getId() { return id; }
}
