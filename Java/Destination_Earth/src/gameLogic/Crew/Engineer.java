package gameLogic.Crew;

public class Engineer extends CrewMembers
{
    String name = "Engineer";
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Can fix hull. "
            + "2 hull for 1 ip when resting"
            + "1 hull for 1 action point"
            + "1 hull per round for free if in engineering";

    public Engineer()
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
