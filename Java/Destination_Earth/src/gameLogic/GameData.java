package gameLogic;

import gameLogic.Crew.*;
import gameLogic.Tokens.Alien;
import java.util.ArrayList;

public class GameData
{
    static int MAX_POINTS = 12; //o maximo é sempre 12
    
    static int DEFAULT_HP = 8;
    static int DEFAULT_AP = 5;
    int HP;
    int AP;
    int IP;
    
    ArrayList<CrewMembers> crew;
    
    Alien alien;
    GameBoard game_board;
    
    public GameData()
    {
        HP = DEFAULT_HP;
        AP = DEFAULT_AP;
        IP = 0;
        crew = new ArrayList<>();
    }
    
    public void NewRound()
    {
        AP = 5;
    }
    
    public static int getMaxPoints() {return MAX_POINTS;}
    
    public void AddCrewMember(CrewMembers crewmember) { crew.add(crewmember); }
    
    public boolean CompleteCrew() { return (crew.size() == 2); }
    
    public void ClearCrew() { crew.clear(); }
}