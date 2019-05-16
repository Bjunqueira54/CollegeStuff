package TextUI;

import java.util.Scanner;
import GameLogic.Game;

public class TextMain
{
    Scanner sc;
    Game game;
    boolean quitting;
    
    public TextMain()
    {
        sc = new Scanner(System.in);
        game = new Game();
        quitting = false;
    }
    
    private void MainMenu()
    {
        Printer.PrintMainMenu();
    }
    
    public void run()
    {
        while(!quitting)
        {
            if(game.getState().equalsIgnoreCase("MainMenu"))
            {
                MainMenu();
            }
        }
    }
}