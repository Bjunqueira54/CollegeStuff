package gameLogic.Crew;

public class CommsOfficer extends CrewMembers
{
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "before an alien attacks, roll 1d6"
            + "on a 1 or 2 that alien doesn't attack this officer";

    public CommsOfficer()
    {
        
    }
}
