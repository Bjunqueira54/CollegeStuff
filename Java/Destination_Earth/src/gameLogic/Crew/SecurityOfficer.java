package gameLogic.Crew;

public class SecurityOfficer extends CrewMembers
{
    int movement = 1;
    int attack_die = 2;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Starts with 2d6 for attack";

    public SecurityOfficer()
    {
        
    }
    
    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}
    
    @Override
    public String toString()
    {
        return "Security Officer";
    }
}
