package gameLogic.Ship;

public class SickBay extends Ship
{
    private int id = 2;
    private String name = "Sick Bay";

    public SickBay()
    {
        super(false);
        addDoor(6);
        addDoor(7);
        addDoor(8);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
