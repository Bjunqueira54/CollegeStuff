package gameLogic.States;

import gameLogic.GameData;

public class AwaitRestingPlayerChoice extends StateAdapter
{
    public AwaitRestingPlayerChoice(GameData g) { super(g); }

    @Override
    public States AddHealth()
    {
        getGameData().addHealth();
        return this;
    }

    @Override
    public States Repair()
    {
        getGameData().RepairHull();
        
        return this;
    }
    
    @Override
    public States quitgame()
    {
        return new MainMenu(new GameData());
    }
}