package gameLogic.Crew;

public class SecurityOfficer extends CrewMembers
{
    String name = "Security Officer";

    //provisorio
    String special = "Starts with 2d6 for attack";

    public SecurityOfficer()
    {
        super();
        dice = 2;
    }
    
    @Override
    public String toString() { return name; }
}