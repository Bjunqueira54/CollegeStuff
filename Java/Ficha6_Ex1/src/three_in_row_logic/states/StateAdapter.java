package three_in_row_logic.states;

import three_in_row_logic.GameData;

public class StateAdapter implements IStates, three_in_row_logic.Constants 
{
    private GameData game;

    public StateAdapter(GameData g)
    {
        this.game = g;
    }

    public GameData getGame() 
    {
        return game;
    }
    
    public void setGame(GameData game) 
    {
        this.game = game;
    }

    @Override
    public IStates setNumberPlayers(int num) { return this;}

    @Override
    public IStates setName(int num, String name) { return this;}

    @Override
    public IStates startGame() { return this;}

    @Override
    public IStates placeToken(int linha, int coluna) { return this;}

    @Override
    public IStates returnToken(int linha, int coluna) { return this;}

    @Override
    public IStates quit() { return this;}   
}
