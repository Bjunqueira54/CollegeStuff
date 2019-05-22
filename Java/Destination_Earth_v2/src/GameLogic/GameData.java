package GameLogic;

import java.util.ArrayList;
import GameLogic.CrewMembers.*;
import GameLogic.Exceptions.*;
import GameLogic.Rooms.*;

public class GameData
{
    private int HP;
    private int Hull;
    private int round;
    private ArrayList<CrewMember> crew;
    private ArrayList<Room> ship;
    private ArrayList<Integer> rounds;
    
    public GameData()
    {
        crew = new ArrayList<>();
        ship = new ArrayList<>();
        rounds = new ArrayList<>();
        CreateShip();
        round = 0;
    }
    
    //Not sure if here or in Game. Decide Later.
    //Return value: [1; (6*n)]
    private int DiceRoller(int n)
    {
        return (int) ((Math.random() * (6 * n)) + 1);
    }
    
    private void CreateShip()
    {
        ship.add(new Bridge());
        ship.add(new SickBay());
        ship.add(new Brig());
        ship.add(new CrewQuarters());
        ship.add(new ConferenceRoom());
        ship.add(new ShuttleBay());
        ship.add(new WeaponsBay());
        ship.add(new MessHall());
        ship.add(new Engineering());
        ship.add(new Astrometrics());
        ship.add(new Holodeck());
        ship.add(new Hydroponics());
    }
    
    public void setDefaultAdventure()
    {
        rounds.add(2);
        rounds.add(3);
        rounds.add(4);
        rounds.add(15);
        rounds.add(0);
        rounds.add(4);
        rounds.add(5);
        rounds.add(16);
        rounds.add(0);
        rounds.add(6);
        rounds.add(17);
        rounds.add(0);
        rounds.add(8);
    }
    
    public void addCrewMember(CrewMember cm)
    {
        if(isCrewComplete())
            return;
        
        crew.add(cm);
    }
    
    public void clearAdventure() { rounds.clear(); }
    
    //0 - Resting Round
    //[1; 8] - Number of Aliens to Spawn
    //[11; 18] - Number of Aliens to Spawn and Retreat
    public void addRound(int round) throws InvalidRoundException
    {
        if(isAdventureComplete())
            return;
        
        if(round == 0 || (round >= 1 && round <= 8) || (round >= 11 && round <= 18))
            rounds.add(round);
        else
            throw new InvalidRoundException();
    }
    
    public String getAdventure()
    {
        String aux = "";
        
        if(rounds.isEmpty())
            return aux;
        
        for (int i = 0; i < rounds.size(); i++)
        {
            if(i+1 == round) aux += "(";
            
            if(rounds.get(i) == 0)
                aux += "R";
            else if(rounds.get(i) >= 1 && rounds.get(i) <= 8)
                aux += rounds.get(i) + "A";
            else if(rounds.get(i) >= 11 && rounds.get(i) <= 18)
                aux += (rounds.get(i) - 10) + "A*";
            
            if(i+1 == round) aux += ")";
            
            if(!(i == (rounds.size() - 1))) aux += ", ";
        }
        
        return aux;
    }
    
    public String getCrewMembers()
    {
        String aux = "";
        
        if(crew.isEmpty())
            return aux;
        
        for (int i = 0; i < crew.size(); i++)
        {
            aux += crew.get(i).toString();
            
            if(!(i == (crew.size() - 1))) aux += ", ";
        }
        
        return aux;
    }
    
    public boolean isCrewComplete() { return (crew.size() == 2); }
    public boolean isAdventureComplete() { return (rounds.size() == 13); }
}