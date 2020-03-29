package gameLogic.Ship;

public class WeaponsBay extends Ship
{
    private int id = 7;
    private String name = "Weapons Bay";

    public WeaponsBay()
    {
        super(true);
        addDoor(2);
        addDoor(11);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }
    
    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}