package gameLogic.Crew;

public class Commander extends CrewMembers
{
    int movement = 1;
    int attack_die = 1; //d6
    int attack_hit = 5;
    int AP = 6;
    
    //provisorio
    String special = "6 action points per turn";

    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}
    
    public int getCommanderAP() {return AP;}
    
    @Override
    public String toString()
    {
        return "Commander";
    }
}