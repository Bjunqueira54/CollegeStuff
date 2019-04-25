package gameLogic.Crew;

public class ShuttlePilot extends CrewMembers
{
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Starts with 4 extra health";

    public ShuttlePilot()
    { 
        
    }
    
    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}
}
