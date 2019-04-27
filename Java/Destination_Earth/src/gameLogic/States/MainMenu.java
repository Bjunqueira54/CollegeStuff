package gameLogic.States;

import gameLogic.GameData;

public class MainMenu implements States
{
    private GameData gamedata;
    
    public MainMenu(GameData gamedata)
    {
        this.gamedata = gamedata;
    }

    @Override
    public States quitgame()
    {
        return this;
    }

    @Override
    public States startgame()
    {
        return new AwaitRoundPlayerChoice(gamedata);
    }
    
    public GameData getGameData() { return this.gamedata; }
}
