package gameLogic;

import gameLogic.States.States;

public class Game
{
    Player player;
    GameBoard game_board;
    GameData gamedata;
    States state;
    
    public Game()
    {
        player = new Player();
        game_board = new GameBoard();
        gamedata = new GameData();
    }
}