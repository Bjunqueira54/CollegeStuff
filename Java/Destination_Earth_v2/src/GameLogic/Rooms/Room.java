package GameLogic.Rooms;

import java.util.ArrayList;
import GameLogic.CrewMembers.*;
import GameLogic.Tokens.*;

public class Room
{
    boolean isSealed, hasParticleDispenser, hasOrganicDetonator;
    ArrayList<Alien> aliens;
    ArrayList<CrewMember> crew;
    
    public Room()
    {
        isSealed = false;
        hasOrganicDetonator = false;
        hasParticleDispenser = false;
    }
    
    public boolean isSealed() { return isSealed; }
    public boolean hasParticleDispenser() { return hasParticleDispenser; }
    public boolean hasOrganicDetonator() { return hasOrganicDetonator; }
    public boolean hasAliens() { return (aliens.size() > 0); }
    public boolean hasCrewMember() { return (crew.size() > 0); }
    
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
    
    
}