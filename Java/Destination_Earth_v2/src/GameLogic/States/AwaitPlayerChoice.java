package GameLogic.States;

import GameLogic.CrewMembers.*;
import GameLogic.GameData;

public class AwaitPlayerChoice extends gStateAdapter
{
    private GameData data;
    
    public AwaitPlayerChoice(GameData data)
    {
        this.data = data;
    }

    @Override
    public String toString() { return "AwaitPlayerChoice"; }
    
    // move
    public gState Move(CrewMember cm) 
    {
        return this; //temporary
    }
    
    // attack
    public gState Attack(CrewMember cm)
    {
        return this; //temporary
    }
    
    // place traps
    public gState PlaceTraps(int room)
    {
        return this; //temporary
    }
    
    // seal room
    public gState SealRoom(int room)
    {
        return this; //temporary
    }
}