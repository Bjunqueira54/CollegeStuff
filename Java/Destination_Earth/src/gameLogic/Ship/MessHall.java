package gameLogic.Ship;

public class MessHall extends Ship
{
    int doors[] = {0,1,3,4};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}
