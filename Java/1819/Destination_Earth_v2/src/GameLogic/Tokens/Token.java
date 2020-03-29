package GameLogic.Tokens;

import GameLogic.Rooms.*;

public class Token
{
    private Room curRoom;
    private boolean isSet;
    
    public Token()
    {
        isSet = false;
    }
    
    public Room getCurrentRoom() { return curRoom; }
    
    public boolean isSet() { return this.isSet; }
    
    private void setTrap() { isSet = true; }
    
    public void setRoom(Room room)
    {
        curRoom = room;
        setTrap();
    }
}