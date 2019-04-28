package gameLogic.Ship;

public class Hydroponics extends Ship
{
    private int id = 12;

    public Hydroponics()
    {
        super();
        addDoor(9);
        addDoor(10);
    }
    
    public int getId() { return id; }
}
