package gameLogic.Ship;

public class ShuttleBay extends Ship
{
    private int id = 6;

    public ShuttleBay()
    {
        super();
        addDoor(2);
        addDoor(10);
    }
    
    public int getId() { return id; }
}
