package gameLogic.Ship;

public class Astrometrics extends Ship
{
    private int id = 10;
    
    public Astrometrics()
    {
        super();
        addDoor(5);
        addDoor(6);
        addDoor(12);
    }
    
    public int getId() { return id; }
}