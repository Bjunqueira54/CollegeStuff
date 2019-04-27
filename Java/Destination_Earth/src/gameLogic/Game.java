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
    
    public boolean CompleteCrew() { return gamedata.isCrewComplete(); }
    
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
    
    public int getRoundNumber() { return getGameData().getRoundNumber(); }
    
    public String getRoundType(int round) { return getGameData().getRound(round); }
    
    public int getHP() { return getGameData().getHP(); }
    
    public int getAP() { return getGameData().getAP(); }
    
    public int getIP() { return getGameData().getIP(); }
    
    public String getCrewMember(int index) { return getGameData().getCrewMember(index - 1); }
}
