package gameLogic.Crew;

public class MoralOfficer extends CrewMembers
{
    String name = "Moral Officer";

    //provisorio
    String special = "Starts with 5 inspiration points";

    public MoralOfficer()
    {
        super();
    }
    
    @Override
    public String toString() { return name; }
}