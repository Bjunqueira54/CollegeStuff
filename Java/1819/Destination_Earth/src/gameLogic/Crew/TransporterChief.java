package gameLogic.Crew;

public class TransporterChief extends CrewMembers
{
    String name = "Transporter Officer";

    //provisorio
    String special = "Can teleport to any room on the ship for 1 action point";

    public TransporterChief()
    {
        super();
    }
    
    @Override
    public String toString() { return name; }
}