package gameLogic.Crew;

public class Captain extends CrewMembers
{
    String name = "Captain";
    int roll_bonus = 3;
    
    //provisorio
    String special = "Can attack an alien on a 3+";

    public Captain()
    {
        super();
    }

    @Override
    public String toString() { return name; }

    @Override
    public int getDieRoll()
    {
        int roll = super.getDieRoll();
        
        if(roll + roll_bonus > getDiceNumber() * 6)
            return (getDiceNumber() * 6);
        else
            return (roll + roll_bonus);
    }
}