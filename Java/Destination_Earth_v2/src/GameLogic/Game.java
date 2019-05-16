package GameLogic;

import GameLogic.CrewMembers.*;
import GameLogic.Rooms.*;
import GameLogic.States.*;

public class Game
{
    GameData data;
    gStates state;
    
    public Game()
    {
        data = new GameData();
        state = new MainMenu();
    }
    
    public void StartGame()
    {
        
    }
    
    public void QuitGame()
    {
        data = new GameData();
        state = new MainMenu();
    }
}