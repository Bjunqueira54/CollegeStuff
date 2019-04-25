package gameLogic.Ship;

public class ConferenceRoom extends Ship
{
    int doors[] = {0,2,7,9};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
}
