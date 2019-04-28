package gameLogic.Ship;

public class WeaponsBay extends Ship
{
    private int id = 7;

    public WeaponsBay()
    {
        super();
        addDoor(2);
        addDoor(11);
    }
    
    public int getId() { return id; }
}