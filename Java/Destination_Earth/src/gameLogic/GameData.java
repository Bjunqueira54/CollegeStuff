package gameLogic;

import gameLogic.Crew.*;
import gameLogic.Exceptions.CrewMemberAlreadyPresentException;
import gameLogic.Tokens.Alien;
import java.util.ArrayList;

public class GameData
{
    static int MAX_POINTS = 12; //o max é sempre 12
    
    static int DEFAULT_IP = 0;
    static int DEFAULT_HP = 8;
    static int DEFAULT_AP = 5;
    int HP;
    int AP;
    int IP;
    
    ArrayList<CrewMembers> crew;
    ArrayList<String> adventure;
    
    Alien alien;
    GameBoard game_board;
    
    public GameData()
    {
        HP = DEFAULT_HP;
        AP = DEFAULT_AP;
        IP = DEFAULT_IP;
        crew = new ArrayList<>();
        adventure = new ArrayList<>();
    }
    
    public void NewRound()//tem de puder ser mudado
    {
        AP = 5;
    }
    
    public static int getMaxPoints() {return MAX_POINTS;}
    
    public void AddCrewMember(CrewMembers crewmember) throws CrewMemberAlreadyPresentException
    {
        if(crew.isEmpty())
            crew.add(crewmember);
        else
        {
            for (CrewMembers it : crew)
            {
                if(crewmember.getClass() == it.getClass())
                {
                    throw new CrewMemberAlreadyPresentException();
                }
            }
            
            crew.add(crewmember);
        }
    }
    
    public boolean CompleteCrew() { return (crew.size() == 2); }
    
    public void ClearCrew() { crew.clear(); }
    public void ClearAdventure() { adventure.clear(); }
    
    public boolean isAdventureSet() { return (adventure.size() == 13); }
    
    public void addRestingRound() { adventure.add("R"); }
    public void addSpawnAliensRound(int n) { adventure.add(n + "A"); }
    public void addSpawnRetreatingAliensRound(int n) { adventure.add(n + "A*"); }
    public void SetDefaultAdventure()
    {
        ClearAdventure();
        
        adventure.add("2A");
        adventure.add("3A");
        adventure.add("4A");
        adventure.add("5A*");
        adventure.add("R");
        adventure.add("4A");
        adventure.add("5A");
        adventure.add("6A*");
        adventure.add("R");
        adventure.add("6A");
        adventure.add("7A*");
        adventure.add("R");
        adventure.add("8A");
    }
    
    public String getRoundsAsString() { return adventure.toString(); }
    public String getCrewMembersAsString()
    {
        int i = 1;
        String str = "[";
        
        for (CrewMembers it : crew)
        {
            str += it.toString();
            if(i < crew.size())
            {
                str += ", ";
                i++;
            }
        }
        
        str += "]";
        
        return str;
    }
}