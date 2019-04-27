package gameLogic.States;

import gameLogic.GameData;

public class MainMenu extends StateAdapter
{
    public MainMenu(GameData gamedata)
    {
        super(gamedata);
    }

    @Override
    public States startgame()
    {
        return new AwaitRoundPlayerChoice(gamedata);
    }
}