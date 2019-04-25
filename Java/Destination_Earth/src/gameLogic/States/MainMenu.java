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
    public States ChooseCrew()
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public States chooseAction() { return this; }

    @Override
    public States quit()
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public States start()
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public States setGame()
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    public GameData getGameData() { return this.gamedata; }
}
