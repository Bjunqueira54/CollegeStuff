package gameLogic.Ship;

public class SickBay extends Ship
{
    private int id = 2;

    public SickBay()
    {
        super();
        addDoor(6);
        addDoor(7);
        addDoor(8);
    }
    
    public int getId() { return id; }
}
