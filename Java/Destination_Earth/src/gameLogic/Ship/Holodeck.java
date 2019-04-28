package gameLogic.Ship;

public class Holodeck extends Ship
{
    private int id = 11;

    public Holodeck()
    {
        super();
        addDoor(4);
        addDoor(7);
    }
    
    public int getId() { return id; }
}
