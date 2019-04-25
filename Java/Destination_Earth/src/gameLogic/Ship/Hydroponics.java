package gameLogic.Ship;

public class Hydroponics extends Ship
{
    int doors[] = {8,9};
    boolean sealed_room = false;
    
    public int[] getRoomDoors() {return doors;}
    
    public boolean getRoomState() {return sealed_room;}
    
    public void setRoomState() {sealed_room = true;}
}
