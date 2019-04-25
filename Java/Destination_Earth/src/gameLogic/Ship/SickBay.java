package gameLogic.Ship;

public class SickBay extends Ship
{
    int doors[] = {5,6,7};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}
