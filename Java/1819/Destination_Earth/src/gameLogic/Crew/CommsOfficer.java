package gameLogic.Crew;

public class CommsOfficer extends CrewMembers
{
    String name = "Communications Officer";
    
    //provisorio
    String special = "before an alien attacks, roll 1d6"
            + "on a 1 or 2 that alien doesn't attack this officer";

    public CommsOfficer()
    {
        super();
    }

    public int getSavingThrow() { return (1 + (int) (Math.random() * 6 ) ); }
    
    @Override
    public String toString() { return name; }
}