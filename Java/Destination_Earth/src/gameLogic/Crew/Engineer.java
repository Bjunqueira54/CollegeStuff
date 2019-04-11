package gameLogic.Crew;

public class Engineer extends CrewMembers
{
    int movement = 1;
    int attack = 1;//d6
    //provisorio
    String special = "Can fix hull. "
            + "2 hull for 1 ip when resting"
            + "1 hull for 1 action point"
            + "1 hull per round for free if in engineering";

    public Engineer()
    {
        
    }
}
