package gameLogic;

import gameLogic.States.States;
import gameLogic.Crew.*;
import gameLogic.Exceptions.CrewMemberAlreadyPresentException;
import gameLogic.States.*;

public class Game
{
    private GameData gamedata;
    private States state;
    
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
    
    public void AddCrewMember(CrewMembers crewmember) throws CrewMemberAlreadyPresentException { SetState(getGameState().ChooseCrew(crewmember)); }
    
    public boolean isAdventureSet() { return gamedata.isAdventureSet(); }
    
    public void addRestingRound() { SetState(getGameState().ChooseAdventure("R")); }
    
    public void addSpawnAliensRound(int n) { SetState(getGameState().ChooseAdventure(n + "A")); }
    
    public void addSpawnRetreatingAliensRound(int n) { SetState(getGameState().ChooseAdventure(n + "A*")); }
    
    public void SetDefaultAdventure() { SetState(getGameState().ChooseDefaultAdventure()); }
    
    public String getRoundsAsString() { return gamedata.getRoundsAsString(); }
    
    public String getCrewMembersAsString() { return gamedata.getCrewMembersAsString(); }
    
    public void start() { SetState(getGameState().startgame()); }
    
    public void ChooseCrew() { SetState(new ChooseCrewState(gamedata)); }
    
    public void ChooseAdventure() { SetState(new ChooseAdventureState(gamedata)); }
}
