package gameLogic.States;

import gameLogic.GameData;

public class AwaitRoundPlayerChoice extends StateAdapter
{
    public AwaitRoundPlayerChoice(GameData gamedata)
    {
        super(gamedata);
    }

    @Override
    public States quitgame()
    {
        return new MainMenu(gamedata);
    }
}