package gameLogic.Ship;

public class Brig extends Ship
{
    private int id = 3;

    public Brig()
    {
        super();
        addDoor(5);
        addDoor(9);
    }
    
    public int getId() { return id; }
}
