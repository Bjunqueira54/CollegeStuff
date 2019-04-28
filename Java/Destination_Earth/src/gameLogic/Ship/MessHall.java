package gameLogic.Ship;

public class MessHall extends Ship
{
    private int id = 8;

    public MessHall()
    {
        super();
        addDoor(1);
        addDoor(2);
        addDoor(4);
        addDoor(5);
    }
    
    public int getId() { return id; }
}
