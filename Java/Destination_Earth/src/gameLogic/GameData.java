package gameLogic;

import gameLogic.Crew.*;
import gameLogic.Ship.*;
import static gameLogic.Dice.diceRoller;
import gameLogic.Exceptions.*;
import gameLogic.Tokens.*;
import java.util.ArrayList;

public class GameData
{
    static int MAX_POINTS = 12; //o max é sempre 12
    
    private final int DEFAULT_IP = 0;
    private final int DEFAULT_HP = 8;
    private final int DEFAULT_AP = 5;
    
    private int round = 1;
    private int HP;
    private int AP;
    private int IP;
    
    private ArrayList<CrewMembers> crew;
    private ArrayList<String> adventure;
    private ArrayList<Ship> ship;
    private ArrayList<Alien> aliens;
    private ArrayList<Token> tokens;
    
    private boolean hasDoctor = false;
    private boolean hasEngineer = false;
    private boolean hasCommander = false;
    
    private boolean AliensRetreatAfterRound = false;
    
    public GameData()
    {
        HP = DEFAULT_HP;
        AP = DEFAULT_AP;
        IP = DEFAULT_IP;
        
        crew = new ArrayList<>();
        adventure = new ArrayList<>();
        ship = new ArrayList<>();
        aliens = new ArrayList<>();
        tokens = new ArrayList<>();
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
    
    public boolean haveOrganicDetonators()
    {
        for (Token it : tokens)
        {
            if(it instanceof OrganicDetonator)
                return true;
        }
        return false;
    }
    
    public boolean haveParticleDispensers()
    {
        for (Token it : tokens)
        {
            if(it instanceof ParticleDispenser)
                return true;
        }
        return false;
    }
    
    public boolean haveSealRoomToken()
    {
        for (Token it : tokens)
        {
            if(it instanceof SealRoom)
                return true;
        }
        return false;
    }
    
    public void ClearCrew() { crew.clear(); }
    public void ClearAdventure() { adventure.clear(); }
    
    public boolean isAdventureSet() { return (adventure.size() >= 13); }
    public boolean isCrewComplete() { return (crew.size() == 2); }
    
    public void addRound(String round) { adventure.add(round); }
    
    /*
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
    
    public String getAdjacentRooms(int room) { return ship.get(room - 1).getDoors(); }
    
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
    
    public String getCrewMembersInfo()
    {
        String info = "";
        
        for (CrewMembers cm : crew)
        {
            info += cm.toString() + " Location: " + ship.get(cm.getCurrentPosition() - 1).getName() + "\n";
        }
        
        return info;
    }
    
    public CrewMembers getCrewMember(int index)
    {
        if(crew.get(index) == null)
            return null;
        else
            return crew.get(index);
    }
    
    public String getRound(int i) { return adventure.get(i-1); }
    
    public int getRoundNumber() { return round; }
    
    public int DieRoll() { return diceRoller(1); }
    
    private void SetupCrew()
    {
        for (CrewMembers it : crew)
        {
            if(it instanceof Commander)
            {
                hasCommander = true;
                AP = 6;
            }
            else if(it instanceof Doctor)
                hasDoctor = true;
            else if(it instanceof Engineer)
                hasEngineer = true;
            else if(it instanceof MoralOfficer)
                IP = 5;
            else if(it instanceof ShuttlePilot)
                HP += 4;
            
            it.setNewPosition(diceRoller(2));
            if(!ship.isEmpty())
                ship.get(it.getCurrentPosition() - 1).MoveCrewToHere(it);
        }
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
        ship.add(new Enginnering());
        ship.add(new Astrometrics());
        ship.add(new Holodeck());
        ship.add(new Hydroponics());
    }
    
    private void SpawnAliens()
    {
        String curRound = adventure.get(round - 1);
        
        if(curRound.length() == 1)
            return;
        
        if(curRound.length() == 3)
            AliensRetreatAfterRound = true;
        
        int numToSpawn = Character.getNumericValue(curRound.charAt(0));
        
        for(int i = 0; i < numToSpawn; i++)
        {
            int room = diceRoller(2);
            Alien alien = new Alien(room);
            aliens.add(alien);
            ship.get(room - 1).MoveAlienToHere(alien);
        }
    }
    
    public String getRoomsWithAliens()
    {
        if(aliens.isEmpty() || ship.isEmpty())
            return "[]";
        
        ArrayList<Integer> roomlist = new ArrayList<>();
        
        for (Alien it : aliens)
        {
            if(!(roomlist.contains((Integer) it.getCurrentRoom())))
                roomlist.add((Integer) it.getCurrentRoom());
        }
        
        String roomstr = "[";
        
        for(int i = 0; i < roomlist.size(); i++)
        {
            roomstr += ship.get(roomlist.get(i).intValue() - 1).getName();
            
            if(!(i == roomlist.size() - 1))
                roomstr += ", ";
        }
        
        roomstr += "]";
        
        return roomstr;
    }
    
    public void move(CrewMembers cm, int room) throws InvalidRoomException
    {
        if(cm instanceof TransporterChief)
        {
            ship.get(cm.getCurrentPosition()).MoveCrewOutOfRoom(cm);
            cm.setNewPosition(room);
        }
        
        String roomlist = getAdjacentRooms(room);
        
        roomlist = roomlist.replaceAll("[^0-9]", " ");
        ArrayList<Integer> intlist = new ArrayList<>();
        
        for(int i = 0; i < roomlist.length(); i++)
        {
            if(roomlist.charAt(i) != ' ')
                intlist.add((Integer) Character.getNumericValue(roomlist.charAt(i)));
        }
        
        if(intlist.contains((Integer) room))
        {
            ship.get(cm.getCurrentPosition()).MoveCrewOutOfRoom(cm);
            cm.setNewPosition(room);
            AP--;
        }
        else
            throw new InvalidRoomException();
    }
    
    public void moveNavOfficer(int room)
    {
        throw new UnsupportedOperationException("Not Yet Coded");
    }
    
    public void startgame()
    {
        CreateShip();
        SetupCrew();
        SpawnAliens();
    }
    
    public void nextRound()
    {
        round++;
        
        if(AliensRetreatAfterRound)
        {
            for (Ship room : ship)
            {
                room.clearAliens();
            }
            aliens.clear();
            AliensRetreatAfterRound = false;
        }
        
        if(hasCommander)
            AP = 6;
        else
            AP = 5;
        SpawnAliens();
    }
    
    public void CrewMemberAttack(CrewMembers cm, int room) throws InvalidRoomException, NoAliensToAttackException
    {
        if(!(cm instanceof ScienceOfficer) && (room != cm.getCurrentPosition()))
            throw new InvalidRoomException();
        
        int roll = diceRoller(cm.getDiceNumber());
        
        if(cm instanceof Captain)
        {
            if(roll + 3 > 6 * cm.getDiceNumber())
                roll = 6 * cm.getDiceNumber();
            else
                roll += 3;
        }
        
        if(!ship.get(room - 1).hasAliens())
            throw new NoAliensToAttackException();
        
        if(roll >= 5)
        {
            if(cm instanceof ScienceOfficer)
            {
                if(!CheckIfScienceOfficerCanAttack(cm, room))
                    throw new InvalidRoomException();
            }
            
            aliens.remove(ship.get(room - 1).killAlien());
            IP++;
        }
        
        AP--;
    }
    
    public boolean CheckIfScienceOfficerCanAttack(CrewMembers cm, int AttackRoom)
    {
        return ship.get(cm.getCurrentPosition()).hasDoor(AttackRoom);
    }
    
    public void PlaceOrganicDetonator(int room) throws NoOrganicDetonatorsException
    {
        if(!haveOrganicDetonators())
            throw new NoOrganicDetonatorsException();
        
        OrganicDetonator od;
        
        for (Token it : tokens)
        {
            if(it instanceof OrganicDetonator)
            {
                od = (OrganicDetonator) it;
                od.setCurrentRoom(room);
                ship.get(room - 1).addToken(od);
                AP--;
                return;
            }
        }
    }
    
    public void PlaceParticleDispencers(int room) throws NoParticleDispensersException
    {
        if(!haveParticleDispensers())
            throw new NoParticleDispensersException();
        
        ParticleDispenser pd;
        
        for (Token it : tokens)
        {
            if(it instanceof ParticleDispenser)
            {
                pd = (ParticleDispenser) it;
                pd.setCurrentRoom(room);
                ship.get(room - 1).addToken(pd);
                AP--;
                return;
            }
        }
    }
    
    public void SealRoom(int room) throws NoSealRoomTokensExceptions, RoomAlreadySealedException
    {
        if(!haveSealRoomToken())
            throw new NoSealRoomTokensExceptions();
        else if(ship.get(room - 1).getRoomSealState())
            throw new RoomAlreadySealedException();
        
        SealRoom sr;
        
        for(Token it : tokens)
        {
            if(it instanceof SealRoom)
            {
                sr = (SealRoom) it;
                sr.setCurrentRoom(room);
                ship.get(room - 1).addToken(sr);
                
                if(ship.get(room - 1).getRoomSealState())
                    ship.get(room - 1).toggleSealState();
                
                AP--;
                return;
            }
        }
    }
    
    public boolean hasDoctor() { return this.hasDoctor; }
    public boolean hasEngineer() { return this.hasEngineer; }
    
    public int getHP() { return HP; }
    public int getAP() { return AP; }
    public int getIP() { return IP; }
}
