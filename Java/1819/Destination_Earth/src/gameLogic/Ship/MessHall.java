package gameLogic.Ship;

public class MessHall extends Ship
{
    private int id = 8;
    private String name = "Mess Hall";

    public MessHall()
    {
        super(false);
        addDoor(1);
        addDoor(2);
        addDoor(4);
        addDoor(5);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}
