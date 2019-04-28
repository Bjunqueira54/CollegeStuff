package gameLogic.Ship;

public class Astrometrics extends Ship
{
    private int id = 10;
    private String name = "Astrometrics";
    
    public Astrometrics()
    {
        super(false);
        addDoor(5);
        addDoor(6);
        addDoor(12);
    }
    
    public int getId() { return id; }
    
    @Override
    public String getName() { return name; }

    @Override
    public boolean hasDoor(int room) { return super.hasDoor(room); }
}