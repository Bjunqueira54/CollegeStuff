package gameLogic.Crew;

public class NavigationOfficer extends CrewMembers
{
    int movement = 2;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Can move 2 rooms for 1 action point";

    public NavigationOfficer()
    { 
        
    }
    
    public int getAttackHit() {return attack_hit;}
    
    public int getMovement() {return movement;}

    public int getAttackDie() {return attack_die;}
    
    public void setAttackDie(int change) {this.attack_die += change;}
    
    @Override
    public String toString()
    {
        return "Navigation Officer";
    }
}
