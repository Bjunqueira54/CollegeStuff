package Logic.Balls;

import Logic.GameData;

public abstract class Ball
{
    private GameData gamedata;
    
    public Ball(GameData gamedata)
    {
        this.gamedata = gamedata;
    }
    
    public GameData getGameData() { return this.gamedata; }
    
    public abstract void removeAfterBet();
}