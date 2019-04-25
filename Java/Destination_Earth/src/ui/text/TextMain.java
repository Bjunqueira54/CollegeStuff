package ui.text;

import java.util.Scanner;
import gameLogic.Game;

public class TextMain
{
    boolean quit = false;
    Scanner sc;
    Game game;
    
    public TextMain(Game game)
    {
        sc = new Scanner(System.in);
        this.game = game;
    }
    
    private void PrintMainMenu()
    {
        System.out.println("1 - Start Game");
        System.out.println("2 - Choose Adventure");
        System.out.println("3 - Choose Crew");
        System.out.println("4 - Quit Game");
    }
    
    public void run()
    {
        int opt;
        
        while(!quit)
        {
            PrintMainMenu();
            
            opt = sc.nextInt();
            
            switch(opt)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    quit = true;
                    break;
                default: break;
            }
        }
    }
}