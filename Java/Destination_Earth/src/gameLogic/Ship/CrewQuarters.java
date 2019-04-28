package gameLogic.Ship;

public class CrewQuarters extends Ship
{
    private int id = 4;

    public CrewQuarters()
    {
        super();
        addDoor(8);
        addDoor(11);
    }
    
    public int getId() { return id; }
}
