package gameLogic.Ship;

public class Holodeck extends Ship
{
    int doors[] = {3,6};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}
