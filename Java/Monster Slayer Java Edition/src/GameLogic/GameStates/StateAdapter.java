package GameLogic.GameStates;

import GameLogic.Exceptions.*;

public class StateAdapter implements GameState
{
    public StateAdapter() {}
    
    @Override
    public GameState handleInput(char input) { return this; }
    
    @Override
    public GameState Attack() { return this; }
    
    @Override
    public GameState Defend() { return this; }
    
    @Override
    public GameState Heal() { return this; }
    
    @Override
    public String getStateName() { return ""; }
}