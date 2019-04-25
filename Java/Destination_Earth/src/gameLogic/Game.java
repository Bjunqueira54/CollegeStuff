package gameLogic;

import gameLogic.States.States;
import gameLogic.Tokens.Alien;

public class Game
{
    Player player;
    Alien alien;
    GameBoard game_board;
    GameData gamedata;
    States state;
    
    public Game()
    {
        player = new Player();
        //game_board = new GameBoard();
        gamedata = new GameData();
    }
}
