package gameLogic.Crew;

public class RedShirt extends CrewMembers
{
    String name = "Red Shirt";

    //provisorio
    String special = "Can be sacrificed to gain 5 health at any time";

    public RedShirt()
    { 
        super();
    }
    
    @Override
    public String toString() { return name; }
}