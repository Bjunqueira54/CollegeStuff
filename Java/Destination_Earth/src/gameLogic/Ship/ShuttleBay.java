package gameLogic.Ship;

public class ShuttleBay extends Ship
{
    int doors[] = {1,9};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}
