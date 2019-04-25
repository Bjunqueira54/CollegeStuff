package gameLogic;

import gameLogic.States.gStates;

public class Game
{
    Player player;
    GameBoard game_board;
    GameData game_data;
    gStates journey_tracker;
    
    public Game()
    {
        player = new Player();
        game_board = new GameBoard();
    }
}