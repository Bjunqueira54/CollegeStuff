package gameLogic.Ship;

public class CrewQuarters extends Ship
{
    private int id = 4;
    private String name = "Crew Quarters";

    public CrewQuarters()
    {
        super(true);
        addDoor(8);
        addDoor(11);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
