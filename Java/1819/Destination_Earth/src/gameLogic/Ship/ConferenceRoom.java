package gameLogic.Ship;

public class ConferenceRoom extends Ship
{
    private int id = 5;
    private String name = "Conference Room";

    public ConferenceRoom()
    {
        super(false);
        addDoor(1);
        addDoor(3);
        addDoor(8);
        addDoor(10);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
