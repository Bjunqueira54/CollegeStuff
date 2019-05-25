package GameLogic.States;

import GameLogic.Rooms.*;
import GameLogic.CrewMembers.*;
import GameLogic.GameData;

public class AwaitPlayerChoice extends gStateAdapter
{
    private GameData data;
    
    public AwaitPlayerChoice(GameData data)
    {
        this.data = data;
    }

    @Override
    public String toString() { return "AwaitPlayerChoice"; }
    
    // =========== ATTACK ===========
    
    public gState Attack(CrewMember cm)
    {
        
        return this; //temporary
    }
    
    // =========== MOVE ===========
    
    public gState Move(CrewMember cm, Room room) 
    {
        
        if(cm instanceof NavigationOfficer)
            data.moveCrewMember(cm, room, true); // true -> cm = navigation officer
        else
            data.moveCrewMember(cm, room, false); // false -> cm != navigation officer
        
        return this; //don't know what to return
    }
    
    // =========== PLACE TRAPS ===========
    
    public gState PlaceTraps(int room)
    {
        return this; //temporary
    }
    
    // =========== SEAL ROOM ===========
    
    public gState SealRoom(int room)
    {
        return this; //temporary
    }
    
    // =========== QUIT GAME ===========
    
    public gState quitGame()
    {
        return new MainMenu(data);
    }
    
    // =========== CHECK NEXT GAME STATE ===========
    
    private gState CheckNextGameState()
    {
        if(data.hasMoreAP())
            return this;
        else
        {
            // i don't inderstand how to deal wih the round situation
            // verify if next round is a rest round
            
            // data.addRound(1);
            return this; // temporary - to prevent error
        }
    }
    
}