package gameLogic.Ship;

public class ShuttleBay extends Ship
{
    private int id = 6;
    private String name = "Shuttle Bay";

    public ShuttleBay()
    {
        super(false);
        addDoor(2);
        addDoor(10);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
