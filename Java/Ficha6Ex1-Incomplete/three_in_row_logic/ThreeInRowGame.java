package three_in_row_logic;

import three_in_row_logic.states.*;
/**
 *
 * @author Fafe
 */
public class ThreeInRowGame
{    
    private GameData gameData;
    private IStates state; 
    
    public ThreeInRowGame()
    {
        gameData = new GameData();
        setState(new AwaitBeginning(gameData));
    }

    public GameData getGameLogic() {
        return gameData;
    }

    public void setGameLogic(GameData gameData)
    {
        this.gameData = gameData;
    }

    public IStates getState()
    {
        return state;
    }
    
    private void setState(IStates state)
    {
        this.state = state;
    }        
    
     // Methods retrieve data from the game
    
    public String gridToString()
    {
        return gameData.gridToString();
    }                    

    public int getNumPlayers()
    {
        return gameData.getNumPlayers();
    }
    
    public Player getPlayer(int number)
    {
        return gameData.getPlayer(number);
    }        

    public String grelhaToString()
    {
        return gameData.gridToString();
    }

    public int getNumCurrentPlayer()
    {
        return gameData.getNumCurrentPlayer();
    }

    public String getCurrentPlayerName()
    {
        return gameData.getCurrentPlayer().getName();
    }
    
    // Methods that are intended to be used by the user interfaces and that are delegated in the current state of the finite state machine 
    
    public void setNumberPlayers(int num)
    {
        setState(getState().setNumberPlayers(num));
    }

    public void setPlayerName(int num, String name) 
    {
        setState(getState().setName(num, name));
    }

    public void startGame()
    {
        setState(getState().startGame());
    }

    public void placeToken(int line, int column)
    {
        setState(getState().placeToken(line, column));
    }

    public void returnToken(int line, int column)
    {
        setState(getState().returnToken(line, column));
    }

    public void quit()
    {
        setState(getState().quit());
    }
}
