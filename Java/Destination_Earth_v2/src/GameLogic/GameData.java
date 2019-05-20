package GameLogic;

import java.util.ArrayList;
import GameLogic.CrewMembers.*;
import GameLogic.Rooms.*;

public class GameData
{
    int HP;
    int Hull;
    ArrayList<CrewMember> crew;
    ArrayList<Room> ship;
    
    public GameData()
    {
        crew = new ArrayList<>();
        ship = new ArrayList<>();
    }
    
    //Not sure if here or in Game. Decide Later.
    //Return value: [1; (6*n)]
    private int DiceRoller(int n)
    {
        return (int) ((Math.random() * (6 * n)) + 1);
    }
}