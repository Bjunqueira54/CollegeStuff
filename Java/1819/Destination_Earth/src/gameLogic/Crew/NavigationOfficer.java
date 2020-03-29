package gameLogic.Crew;

public class NavigationOfficer extends CrewMembers
{
    String name = "Navigation Officer";

    //provisorio
    String special = "Can move 2 rooms for 1 action point";

    public NavigationOfficer()
    { 
        super();
        movement = 2;
    }
    
    @Override
    public String toString() { return name; }
}