package gameLogic.Ship;

public class Enginnering extends Ship
{
    private int id = 9;
    private String name = "Engineering";

    public Enginnering()
    {
        super(true);
        addDoor(3);
        addDoor(12);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
