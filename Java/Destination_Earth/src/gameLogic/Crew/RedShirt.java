package gameLogic.Crew;

public class RedShirt extends CrewMembers
{
    String name = "Red Shirt";
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Can be sacrificed to gain 5 health at any time";

    public RedShirt()
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
