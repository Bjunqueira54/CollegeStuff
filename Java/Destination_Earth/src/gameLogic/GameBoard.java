package gameLogic;

import gameLogic.Ship.Ship;
import gameLogic.Tokens.Alien;
import static gameLogic.Dice.diceRoller;

public class GameBoard 
{
    Ship ship;
    private final Player p;
    private final Alien a;
          
    public GameBoard(Player player, Alien alien)
    {
        ship = new Ship();
        p = player;
        a = alien;
        
        placePCsOnBoard();
    }
    
    public void placePCsOnBoard()
    {
        for (int i=0; i<getPCsLength(); i++)
            p.setPosition(i, diceRoller(2));
    }
    
    private int getPCsLength() {return p.PCs.length;}
}
