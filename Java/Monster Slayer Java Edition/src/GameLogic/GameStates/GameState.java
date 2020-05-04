package GameLogic.GameStates;

import GameLogic.Exceptions.*;

public interface GameState
{
    public GameState handleInput(char input);
    
    //Battle Menu State Changers
    public GameState Attack();
    public GameState Defend();
    public GameState Heal();
    
    public String getStateName();
}