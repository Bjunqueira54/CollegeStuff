package Logic;

import Logic.States.iStates;
import Logic.States.AwaitBeginning;

public class Game
{
    private GameData gamedata;
    private iStates state;
    
    public Game()
    {
        gamedata = new GameData();
    }
}