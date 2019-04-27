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
        if(getGameData().isAdventureSet() && getGameData().isCrewComplete())
        {
            getGameData().startgame();
            
            if(getGameData().getRound(1).compareToIgnoreCase("R") == 0)
                return new AwaitRestingPlayerChoice(getGameData());
            else
                return new AwaitRoundPlayerChoice(getGameData());
        }
        else
            return this;
    }
}