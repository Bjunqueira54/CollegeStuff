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
    
    
}