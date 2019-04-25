package gameLogic.Ship;

public class Enginnering extends Ship
{
    int doors[] = {2,11};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
}
