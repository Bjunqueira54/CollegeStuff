package gameLogic.Crew;

public class ScienceOfficer extends CrewMembers
{
    String name = "Science Officer";
    int movement = 1;
    int attack_die = 1;//d6
    int attack_hit = 5;
    //provisorio
    String special = "Can attack aliens in any adjacent room as long as there is a door";

    public ScienceOfficer()
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
