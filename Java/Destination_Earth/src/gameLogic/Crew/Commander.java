package gameLogic.Crew;

import static gameLogic.Player.setAP;

public class Commander extends CrewMembers
{
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "6 action points per turn";

    public Commander()
    {
        setAP(1);
    }
}
