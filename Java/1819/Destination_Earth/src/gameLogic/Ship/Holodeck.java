package gameLogic.Ship;

public class Holodeck extends Ship
{
    private int id = 11;
    private String name = "Holodeck";

    public Holodeck()
    {
        super(true);
        addDoor(4);
        addDoor(7);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
