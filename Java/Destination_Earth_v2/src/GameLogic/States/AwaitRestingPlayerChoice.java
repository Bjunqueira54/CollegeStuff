package GameLogic.States;

import GameLogic.GameData;
import GameLogic.CrewMembers.*;

public class AwaitRestingPlayerChoice
{
    private GameData data;
    
    public AwaitRestingPlayerChoice(GameData data)
    {
        this.data = data;
    }
    
    @Override
    public String toString() { return "AwaitRestingPlayerChoice"; }
}
