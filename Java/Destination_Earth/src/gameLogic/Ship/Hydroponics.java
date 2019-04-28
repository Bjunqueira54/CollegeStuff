package gameLogic.Ship;

public class Hydroponics extends Ship
{
    private int id = 12;
    private String name = "Hydroponics";

    public Hydroponics()
    {
        super(true);
        addDoor(9);
        addDoor(10);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
