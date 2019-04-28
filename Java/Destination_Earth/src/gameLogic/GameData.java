package gameLogic;

import gameLogic.Crew.*;
import static gameLogic.Dice.diceRoller;
import gameLogic.Exceptions.CrewMemberAlreadyPresentException;
import gameLogic.Tokens.Alien;
import java.util.ArrayList;

public class GameData
{
    static int MAX_POINTS = 12; //o max é sempre 12
    
    private final int DEFAULT_IP = 0;
    private final int DEFAULT_HP = 8;
    private final int DEFAULT_AP = 5;
    
    private final int round = 1;
    private int HP;
    private int AP;
    private int IP;
    
    private ArrayList<CrewMembers> crew;
    private ArrayList<String> adventure;
    
    private Alien alien;
    private GameBoard game_board;
    
    private boolean hasDoctor = false;
    private boolean hasEngineer = false;
    
    public GameData()
    {
        HP = DEFAULT_HP;
        AP = DEFAULT_AP;
        IP = DEFAULT_IP;
        crew = new ArrayList<>();
        adventure = new ArrayList<>();
    }
    
    /**
     * (static) returns maximum hit points
     * @return MAX_POINTS
     */
    public static int getMaxPoints() { return MAX_POINTS; }
    
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
    
    public void ClearCrew() { crew.clear(); }
    public void ClearAdventure() { adventure.clear(); }
    
    public boolean isAdventureSet() { return (adventure.size() >= 13); }
    public boolean isCrewComplete() { return (crew.size() == 2); }
    
    public void addRound(String round) { adventure.add(round); }
    
    /**
     * create a default adventure
     */
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
    public String getCrewMember(int index) { return crew.get(index).toString(); }
    
    public String getRound(int i) { return adventure.get(i-1); }
    public int getRoundNumber() { return round; }
    
    public int DieRoll() { return diceRoller(1); }
    
    public void startgame()
    {
        for (CrewMembers it : crew)
        {
            if(it instanceof Commander)
                AP = 6;
            else if(it instanceof Doctor)
                hasDoctor = true;
            else if(it instanceof Engineer)
                hasEngineer = true;
            else if(it instanceof MoralOfficer)
                IP = 5;
            else if(it instanceof ShuttlePilot)
                HP += 4;
            
            it.setNewPosition(DieRoll());
        }
    }
    
    public boolean hasDoctor() { return this.hasDoctor; }
    public boolean hasEngineer() { return this.hasEngineer; }
    
    public int getHP() { return HP; }
    public int getAP() { return AP; }
    public int getIP() { return IP; }
}