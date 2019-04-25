package gameLogic;

import gameLogic.States.States;
import gameLogic.Crew.*;

public class Game
{
    GameData gamedata;
    States state;
    
    public Game()
    {
        gamedata = new GameData();
    }
    
    public void SetState(States state)
    {
        this.state = state;
    }
    
    public GameData getGameData() { return gamedata; }
    
    public States getGameState() { return state; }
    
    public boolean CompleteCrew() { return gamedata.CompleteCrew(); }
    
    public void AddCrewMember(CrewMembers crewmember)
    {
        gamedata.AddCrewMember(crewmember);
    }
}
