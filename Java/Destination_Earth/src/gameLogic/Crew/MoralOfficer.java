package gameLogic.Crew;

public class MoralOfficer extends CrewMembers
{
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Starts with 5 inspiration points";

    public MoralOfficer()
    {
        
    }
    
    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}
}
