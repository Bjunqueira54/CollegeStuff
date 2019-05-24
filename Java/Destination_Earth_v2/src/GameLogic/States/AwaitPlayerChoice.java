package GameLogic.States;

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
    public gState Move() 
    {
        
        return this; //temporary
    }
    
    // attack
    public gState Attack()
    {
        return this; //temporary
    }
    
    // place traps
    public gState PlaceTraps()
    {
        return this; //temporary
    }
    
    // seal room
    public gState SealRoom()
    {
        return this; //temporary
    }
}