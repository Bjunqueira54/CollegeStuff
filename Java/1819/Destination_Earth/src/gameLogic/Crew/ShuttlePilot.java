package gameLogic.Crew;

public class ShuttlePilot extends CrewMembers
{
    String name = "Shuttle Pilot";

    //provisorio
    String special = "Starts with 4 extra health";

    public ShuttlePilot()
    { 
        super();
    }
    
    @Override
    public String toString() { return name; }
}