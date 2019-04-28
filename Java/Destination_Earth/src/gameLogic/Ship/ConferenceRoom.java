package gameLogic.Ship;

public class ConferenceRoom extends Ship
{
    private int id = 5;

    public ConferenceRoom()
    {
        super();
        addDoor(1);
        addDoor(3);
        addDoor(8);
        addDoor(10);
    }
    
    public int getId() { return id; }
}
