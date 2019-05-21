package GameLogic;

import java.util.ArrayList;
import GameLogic.CrewMembers.*;
import GameLogic.Rooms.*;

public class GameData
{
    private int HP;
    private int Hull;
    private ArrayList<CrewMember> crew;
    private ArrayList<Room> ship;
    
    public GameData()
    {
        crew = new ArrayList<>();
        ship = new ArrayList<>();
        CreateShip();
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
    
    public void addCrewMember(CrewMember cm) { crew.add(cm); }
    
    public String getCrewMembers()
    {
        String crewstr = "";
        
        if(crew.isEmpty())
            return crewstr;
        
        for(int i = 0; i < crew.size(); i++)
            crewstr += crew.get(i).toString() + ", ";
        
        return crewstr;
    }
    
    public boolean isCrewComplete() { return (crew.size() == 2); }
}