package gameLogic.Ship;

import gameLogic.Crew.CrewMembers;
import static gameLogic.GameData.getMaxPoints;
import gameLogic.Tokens.*;
import java.util.ArrayList;

public class Ship
{
    static int MAX_HULL_HP = getMaxPoints();
    int hull_HP;
    private boolean sealed_room = false;
    private final boolean sealable;
    private ArrayList<Integer> doors;
    private ArrayList<Token> tokens;
    private ArrayList<Alien> aliens;
    private ArrayList<CrewMembers> crew;
    
    public Ship(boolean canSeal)
    {
        this.hull_HP = MAX_HULL_HP;
        tokens = new ArrayList<>();
        doors = new ArrayList<>();
        crew = new ArrayList<>();
        aliens = new ArrayList<>();
        sealable = canSeal;
    }

    public int getHullHP() {return hull_HP;}
    
    public String getName() { return ""; }
    
    public boolean getRoomSealState() { return sealed_room; }
    
    public void toggleSealState() { sealed_room = !sealed_room; }
    
    public void setHullHP(int change) {hull_HP += change;}
    
    public String getDoors() { return doors.toString(); }
    
    public boolean hasDoor(int room)
    {
        for (Integer door : doors)
        {
            if(door.intValue() == room)
                return true;
        }
        
        return false;
    }
    
    public void addDoor(int door) { doors.add(door); }
    
    public boolean canBeSealed() { return sealable; }
    
    public boolean MoveCrewToHere(CrewMembers cm)
    {
        if(!getRoomSealState())
        {
            crew.add(cm);
            return true;
        }
        else
            return false;
    }
    
    public void MoveCrewOutOfRoom(CrewMembers cm) { if(!crew.isEmpty()) crew.remove(cm); }
    
    public boolean hasCrewMember() { return !crew.isEmpty(); }
    
    public void MoveAlienToHere(Alien alien)
    {
        if(!getRoomSealState())
            aliens.add(alien);
    }
    
    public Alien MoveAlienOutOfRoom(Alien alien)
    {
        if(!aliens.isEmpty())
            return aliens.remove(aliens.indexOf(alien));
        else
            return null;
    }
    
    public boolean hasAliens() { return !aliens.isEmpty(); }
    
    public void clearAliens() { aliens.clear(); }
    
    public Alien killAlien() { return aliens.remove(aliens.size() - 1); }
    
    public void addToken(Token token)
    {
        if(token instanceof Alien)
            MoveAlienToHere((Alien) token);
        else if(token instanceof SealRoom)
        {
            if(canBeSealed() && !hasAliens() && !hasCrewMember())
                tokens.add(token);
        }
        else
            tokens.add(token);
    }
    
    public boolean hasOrganicDetonator()
    {
        for (Token token : tokens)
        {
            if(token instanceof OrganicDetonator)
                return true;
        }
        
        return false;
    }
    
    public boolean hasParticleDispenser()
    {
        for (Token token : tokens)
        {
            if(token instanceof ParticleDispenser)
                return true;
        }
        
        return false;
    }
}
