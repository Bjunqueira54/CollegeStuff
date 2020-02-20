package gameLogic.Ship;

public class Bridge extends Ship
{
    private int id = 1;
    private String name = "Bridge";
    
    public Bridge()
    {
        super(false);
        addDoor(5);
        addDoor(8);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }

    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
