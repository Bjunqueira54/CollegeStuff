package Logic.States;

import Logic.GameData;

public class StateAdapter implements iStates
{
    private GameData gamedata;
    
    public StateAdapter(GameData gamedata)
    {
        this.gamedata = gamedata;
    }
    
    public GameData getGameData() { return gamedata; }
    
    @Override
    public iStates start()
    {
        return this;
    }

    @Override
    public iStates finish()
    {
        return this;
    }

    @Override
    public iStates bet(int nBalls)
    {
        return this;
    }

    @Override
    public iStates RemoveOneFromSack()
    {
        return this;
    }

    @Override
    public iStates RemoveTwoRandom()
    {
        return this;
    }
}