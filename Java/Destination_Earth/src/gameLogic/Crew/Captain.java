package gameLogic.Crew;

public class Captain extends CrewMembers
{
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 3;
    //provisorio
    String special = "Can attack an alien on a 3+";

    public Captain()
    {
        
    }
    
    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}

    @Override
    public String toString()
    {
        return "Captain";
    }
}