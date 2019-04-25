package gameLogic.Ship;

public class WeaponsBay extends Ship
{
    int doors[] = {1,10};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}