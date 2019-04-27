package gameLogic;

import gameLogic.States.States;
import gameLogic.Crew.*;
import gameLogic.Exceptions.CrewMemberAlreadyPresentException;
import gameLogic.States.*;

public class Game
{
    GameData gamedata;
    States state;
    
    public Game()
    {
        gamedata = new GameData();
        state = new MainMenu(gamedata);
    }
    
    public void SetState(States state)
    {
        this.state = state;
    }
    
    public GameData getGameData() { return gamedata; }
    
    public States getGameState() { return state; }
    
    public boolean CompleteCrew() { return gamedata.CompleteCrew(); }
    
    public void AddCrewMember(CrewMembers crewmember) throws CrewMemberAlreadyPresentException { gamedata.AddCrewMember(crewmember); }
    
    public boolean isAdventureSet() { return gamedata.isAdventureSet(); }
    
    public void addRestingRound() { gamedata.addRestingRound(); }
    
    public void addSpawnAliensRound(int n) { gamedata.addSpawnAliensRound(n); }
    
    public void addSpawnRetreatingAliensRound(int n) { gamedata.addSpawnRetreatingAliensRound(n); }
    
    public void SetDefaultAdventure() { gamedata.SetDefaultAdventure(); }
    
    public String getRoundsAsString() { return gamedata.getRoundsAsString(); }
    
    public String getCrewMembersAsString() { return gamedata.getCrewMembersAsString(); }
    
    public void start() { state = state.startgame(); }
    
    public void ChooseCrew() { state = new ChooseCrewState(gamedata); }
}
