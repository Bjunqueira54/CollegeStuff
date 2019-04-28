package gameLogic.Ship;

import static gameLogic.GameData.getMaxPoints;
import gameLogic.Tokens.Token;
import java.util.ArrayList;

public class Ship
{
    static int MAX_HULL_HP = getMaxPoints();
    int hull_HP;
    boolean sealed_room = false;
    private ArrayList<Integer> doors;
    private ArrayList<Token> tokens;
    
    public Ship()
    {
        this.hull_HP = MAX_HULL_HP;
        tokens = new ArrayList<>();
        doors = new ArrayList<>();
    }

    public int getHullHP() {return hull_HP;}
    
    public boolean getRoomState() { return sealed_room; }
    
    public void toggleSealState() { sealed_room = !sealed_room; }
    
    public void setHullHP(int change) {hull_HP += change;}
    
    public String getDoors() { return doors.toString(); }
    
    public void addDoor(int door)
    {
        doors.add(door);
    }
}
