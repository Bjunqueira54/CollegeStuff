package GameLogic.GameStates;

import GameLogic.GameStates.*;
import GameLogic.GameData;

public class BattleMenuState extends StateAdapter
{
    private GameData gData;
    
    public BattleMenuState(GameData gData)
    {
        super();
        this.gData = gData;
    }
    
    @Override
    public GameState Attack()
    {
        return this;
    }
    
    @Override
    public GameState handleInput(char input)
    {
        switch(input)
        {
            case 1:
                return this;
            case 2:
                return this;
            case 3:
                return this;
            default:
                return this;
        }
    }
    
    @Override
    public GameState Defend()
    {
        return this;
    }
    
    @Override
    public GameState Heal()
    {
        return this;
    }
    @Override
    public String getStateName() { return "BattleMenuState"; }
    
}