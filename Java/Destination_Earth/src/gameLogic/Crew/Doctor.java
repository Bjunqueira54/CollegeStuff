package gameLogic.Crew;

public class Doctor extends CrewMembers
{
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Can heal"
            + "3 health for 1 ip when resting"
            + "1 health for 1 action point"
            + "1 health per round for free if in sickbay";

    public Doctor()
    {
        
    }
    
    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}
}
