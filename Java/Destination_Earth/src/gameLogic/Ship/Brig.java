package gameLogic.Ship;

public class Brig extends Ship
{
    int doors[] = {4,8};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}
