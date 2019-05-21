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
        
    }
    
    public void QuitGame()
    {
        data = new GameData();
        state = new MainMenu(data);
    }
    
    public void MainMenu() { state = new MainMenu(data); }
    public void ChooseCrew() { state = new ChooseCrew(data); }
    public void ChooseCrewMember(String name) throws InvalidCrewMemberException, CrewMemberAlreadySelectedException
    { state = state.ChooseCrewMember(name); }
    
    public String getState() { return state.toString(); }
    
    public String getCrewMembers() { return "[" + data.getCrewMembers() + "]"; }
    
    public boolean crewComplete() { return data.isCrewComplete(); }
}