package GameLogic;

public class MainGame
{
    GameData game;
    Estados state;
    
    public MainGame()
    {
        game = new GameData();
        state = new AwaitBeginning(game);
    }
}