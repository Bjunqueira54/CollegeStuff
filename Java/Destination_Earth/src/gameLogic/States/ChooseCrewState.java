package gameLogic.States;

import gameLogic.GameData;

public class ChooseCrewState implements States
{
    GameData gamedata;
    
    public ChooseCrewState(GameData gamedata)
    {
        this.gamedata = gamedata;
    }
    
    @Override
    public States setGame() { return this; }

    @Override
    public States ChooseCrew() { return this; }

    @Override
    public States start() { return this; }

    @Override
    public States quit() { return this; }

    @Override
    public States chooseAction() { return this; }
    
    public GameData getGameData() { return this.gamedata; }
}