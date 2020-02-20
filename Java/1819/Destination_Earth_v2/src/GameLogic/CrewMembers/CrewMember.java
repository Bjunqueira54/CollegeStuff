package GameLogic.CrewMembers;

import GameLogic.Rooms.*;

public class CrewMember
{
    private int move;   // Number of Rooms to move
    private int attack; // Attack * Dice Roll
    private Room curRoom;
    
    public CrewMember()
    {
        move = 1;
        attack = 1;
        curRoom = null;
    }
    
    public CrewMember(int move, int attack)
    {
        this.move = move;
        this.attack = attack;
        curRoom = null;
    }
    
    public int getMove() { return move; }
    public int getAttack() { return attack; }
    
    public void setRoom(Room room) { this.curRoom = room; }
    public String getRoom() { return curRoom.toString(); }
}