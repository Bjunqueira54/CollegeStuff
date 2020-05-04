package GameLogic;

import GameLogic.GameStates.*;

public class Game
{
    GameData gData;
    GameState gState;
    
    public Game()
    {
        gData = new GameData();
        gState = new MainMenuState(gData);
    }
    
    public boolean isOver() { return (gData.isOver() || (gState instanceof ExitState)); }
    
    public void handleInput(char input)
    {
        GameState state = gState.handleInput(input);
        
        if(state != null)
            gState = state;
    }
    
    public String getState() { return gState.getStateName(); }
}