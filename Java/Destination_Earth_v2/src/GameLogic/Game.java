package GameLogic;

import GameLogic.Exceptions.*;
import GameLogic.States.*;

public class Game
{
    private GameData data;
    private gState state;
    
    public Game()
    {
        this.data = new GameData();
        this.state = new MainMenu(data);
    }
    
    public void StartGame()
    {
        data.StartGame();
        state = new AwaitPlayerChoice(data);
    }
    
    public void QuitGame()
    {
        data = new GameData();
        state = new MainMenu(data);
    }
    
    public void MainMenu() { state = new MainMenu(data); }
    public void ChooseCrew() { state = new ChooseCrew(data); }
    public void ChooseAdventure() { state = new ChooseAdventure(data); }
    
    public void ChooseCrewMember(String name) throws InvalidCrewMemberException, CrewMemberAlreadySelectedException
    { state = state.ChooseCrewMember(name); }
    
    public void ChooseAdventureRound(String round) throws InvalidRoundException
    { state = state.ChooseRound(round); }
    
    public void setDefaultAdventure() { state = state.setDefaultAdventure(); }
    
    public String getState() { return state.toString(); }
    
    public String getCrewMembers() { return "[" + data.getCrewMembers() + "]"; }
    
    public String getAdventure() { return "[" + data.getAdventure() + "]"; }
    
    public boolean crewComplete() { return data.isCrewComplete(); }
    
    public void ClearAdventure() { state = state.clearAdventure(); }
    
    public void addRound(String round) throws InvalidRoundException
    { state = state.ChooseRound(round); }
    
    //Secret Dev Debugging function
    //Use to reset the game back to the starting stage
    public void reset()
    {
        data = new GameData();
        state = new MainMenu(data);
    }
}