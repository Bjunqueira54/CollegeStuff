package gameLogic.Ship;

public class CrewQuarters extends Ship
{
    int doors[] = {4,5,9,11};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}
