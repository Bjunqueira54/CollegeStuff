package gameLogic.Crew;

public class TransporterChief extends CrewMembers
{
    String name = "Transporter Officer";
    int movement = 0;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Can teleport to any room on the ship for 1 action point";

    public TransporterChief()
    {
        
    }
    
    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}
    
    @Override
    public String toString()
    {
        return name;
    }
}