package gameLogic.Crew;

public class Doctor extends CrewMembers
{
    String name = "Doctor";

    //provisorio
    String special = "Can heal"
            + "3 health for 1 ip when resting"
            + "1 health for 1 action point"
            + "1 health per round for free if in sickbay";

    public Doctor()
    {
        super();
    }
    
    @Override
    public String toString() { return name; }
}