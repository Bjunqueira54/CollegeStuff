package gameLogic.Crew;

public class Captain extends CrewMembers
{
    String name = "Captain";
    int roll_bonus = 3;
    
    //provisorio
    String special = "Can attack an alien on a 3+";

    public Captain()
    {
        super();
    }

    @Override
    public String toString() { return name; }
}