package gameLogic.Ship;

public class Bridge extends Ship
{
    int doors[] = {};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
}
