package gameLogic.Ship;

import static gameLogic.GameData.getMaxPoints;

public class Ship
{
    static int MAX_HULL_HP = getMaxPoints();
    int hull_HP;

    public int getHullHP() {return hull_HP;}
}
