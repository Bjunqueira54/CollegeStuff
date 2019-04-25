package gameLogic;

import gameLogic.States.gStates;
import gameLogic.Tokens.Alien;

public class Game
{
    Player player;
    Alien alien;
    GameBoard game_board;
    GameData game_data;
    gStates journey_tracker;
    
    public Game()
    {
        player = new Player();
        game_board = new GameBoard(player,alien);
    }
}