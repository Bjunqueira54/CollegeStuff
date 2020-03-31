package gameLogic.Crew;

public class Commander extends CrewMembers
{
    String name = "Commander";
    
    //provisorio
    String special = "6 action points per turn";

    public Commander()
    {
        super();
    }
    
    @Override
    public String toString() { return name; }
}