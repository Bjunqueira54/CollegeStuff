package GameLogic.States;

import GameLogic.GameData;
import GameLogic.CrewMembers.*;
import GameLogic.Exceptions.*;

public class AwaitRestingPlayerChoice extends gStateAdapter
{
    private GameData data;
    
    public AwaitRestingPlayerChoice(GameData data)
    {
        this.data = data;
    }
    
    @Override
    public String toString() { return "AwaitRestingPlayerChoice"; }
    
    // =========== ADD HEALTH ===========
    
    public gState addHealth() throws InvalidHealthException
    {
        data.addHealth(0);
        
        return this;
    }
    
    // =========== REPAIR HULL ===========
    
    public gState repairHull() throws InvalidHullException
    {
        data.addHull(0);
        
        return this;
    }
    
    // =========== TRADE IP ===========
    
    public gState tradeIP()
    {
        return this;
    }
    
    // =========== QUIT GAME ===========
    
    public gState quitGame()
    { return new MainMenu(data); }
}
