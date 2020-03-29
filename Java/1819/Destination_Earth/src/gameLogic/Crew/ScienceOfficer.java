package gameLogic.Crew;

public class ScienceOfficer extends CrewMembers
{
    String name = "Science Officer";

    //provisorio
    String special = "Can attack aliens in any adjacent room as long as there is a door";

    public ScienceOfficer()
    { 
        super();
    }
    
    @Override
    public String toString() { return name; }
}