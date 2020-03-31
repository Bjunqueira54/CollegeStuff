package GameLogic.Rooms;

import java.util.ArrayList;
import GameLogic.CrewMembers.*;
import GameLogic.Tokens.*;

public class Room
{
    int id;
    String name;
    boolean isSealed, hasParticleDispenser, hasOrganicDetonator;
    boolean canBeSealed;
    ArrayList<Alien> aliens;
    ArrayList<CrewMember> crew;
    ArrayList<Token> tokens;
    
    public Room(int id, String name, boolean Sealable)
    {
        this.id = id;
        this.name = name;
        this.isSealed = false;
        this.hasOrganicDetonator = false;
        this.hasParticleDispenser = false;
        this.canBeSealed = Sealable;
        
        aliens = new ArrayList<>();
        crew = new ArrayList<>();
        tokens = new ArrayList<>();
    }
    
    public final boolean isSealed() { return isSealed; }
    public final boolean hasParticleDispenser() { return hasParticleDispenser; }
    public final boolean hasOrganicDetonator() { return hasOrganicDetonator; }
    public final boolean hasAliens() { return (aliens.size() > 0); }
    public final boolean hasCrewMember() { return (crew.size() > 0); }
    public final boolean canBeSealed() { return canBeSealed; }
    
    public void addCrewMember(CrewMember cm) { crew.add(cm); }
    public void addAlien(Alien alien) { aliens.add(alien); }
    
    public Alien removeAlien()
    {
        if(!aliens.isEmpty())
            return (aliens.remove(aliens.size() - 1));
        else
            return null;
    }
    
    public boolean removeCrewMember(CrewMember cm)
    {
        if(!crew.isEmpty())
            return crew.remove(cm);
        else
            return false;
    }
    
    public boolean SealRoom()
    {
        if(isSealed == false)
        {
            isSealed = true;
            return true;
        }
        else
            return false;
    }
    
    public boolean PlaceOrganicDetonator()
    {
        if(hasOrganicDetonator == false)
        {
            hasOrganicDetonator = true;
            return true;
        }
        else
            return false;
    }
    
    public boolean PlaceParticleDispenser()
    {
        if(hasParticleDispenser == false)
        {
            hasOrganicDetonator = true;
            return true;
        }
        else
            return false;
    }
    
    public boolean unsealRoom()
    {
        if(isSealed == true)
        {
            isSealed = false;
            return true;
        }
        else
            return false;
    }
    
    public boolean removeParticleDispenser()
    {
        if(hasParticleDispenser == true)
        {
            hasParticleDispenser = false;
            return true;
        }
        else
            return false;
    }
    
    public boolean removeOrganicDetonator()
    {
        if(hasOrganicDetonator == true)
        {
            hasOrganicDetonator = false;
            return true;
        }
        else
            return false;
    }
    
    @Override
    public String toString()
    {
        return id + " - " + name;
    }
}