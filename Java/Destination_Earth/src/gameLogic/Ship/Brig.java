package gameLogic.Ship;

public class Brig extends Ship
{
    private int id = 3;
    private String name = "Brig";

    public Brig()
    {
        super(true);
        addDoor(5);
        addDoor(9);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
