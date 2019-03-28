package GameLogic;

public class StateAdapter implements Estados
{
    GameData gamedata;
    
    public StateAdapter (GameData game)
    {
        this.gamedata = game;
    }

    @Override
    public Estados setNumberPlayers(int nPlayers)
    {
        gamedata.setNumPlayers(nPlayers);
        return this;
    }

    @Override
    public Estados setName(int iPlayer, String name)
    {
        this.gamedata.setPlayerName(iPlayer, name);
        return this;
    }

    @Override
    public Estados startGame(int nPlayers)
    {
        return new AwaitReturn(gamedata); //??
    }

    @Override
    public Estados placeToken(int x, int y)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Estados ReturnToken(int x, int y)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Estados quit()
    {
        gamedata.initialize();
        return new AwaitBeginning(gamedata);
    }
}
