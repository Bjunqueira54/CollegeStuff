package gameLogic.States;

import gameLogic.GameData;

public class AwaitRoundPlayerChoice implements States
{
    private GameData gamedata;
    
    public AwaitRoundPlayerChoice(GameData gamedata)
    {
        this.gamedata = gamedata;
    }

    @Override
    public States startgame()
    {
        return this;
    }

    @Override
    public States quitgame()
    {
        return new MainMenu(gamedata);
    }
}