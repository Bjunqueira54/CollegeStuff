package Logic.States;

import Logic.GameData;

public class AwaitBeginning extends StateAdapter
{
    public AwaitBeginning(GameData gamedata)
    {
        super(gamedata);
    }
    
    @Override
    public iStates start()
    {
        return new AwaitBet(getGameData());
    }

    @Override
    public iStates finish()
    {
        return new GameOver(getGameData());
    }
}