package gameLogic;

import gameLogic.Crew.*;
import gameLogic.Exceptions.CrewMemberAlreadyPresentException;
import gameLogic.Tokens.Alien;
import java.util.ArrayList;

public class GameData
{
    static int MAX_POINTS = 12; //o maximo é sempre 12
    
    static int DEFAULT_IP = 0;
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
        IP = DEFAULT_IP;
        crew = new ArrayList<>();
    }
    
    public void NewRound()//tem de puder ser mudado
    {
        AP = 5;
    }
    
    public static int getMaxPoints() {return MAX_POINTS;}
    
    //é possivel adicionar dois membros do mesmo tipo, nao pode acontecer
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
}