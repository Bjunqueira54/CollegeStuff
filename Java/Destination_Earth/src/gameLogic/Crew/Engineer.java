package gameLogic.Crew;

public class Engineer extends CrewMembers
{
    String name = "Engineer";

    //provisorio
    String special = "Can fix hull. "
            + "2 hull for 1 ip when resting"
            + "1 hull for 1 action point"
            + "1 hull per round for free if in engineering";

    public Engineer()
    { 
        super();
    }
    
    @Override
    public String toString() { return name; }
}