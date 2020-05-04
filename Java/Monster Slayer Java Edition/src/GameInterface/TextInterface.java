package GameInterface;

import GameLogic.Game;
import java.util.Scanner;

public class TextInterface
{
    Game game;
    Scanner sc;
    
    public TextInterface()
    {
        game = new Game();
        sc = new Scanner(System.in);
    }
    
    public void run()
    {
        while(!game.isOver())
        {
            handleState();
        }
    }
    
    private void handleState()
    {
        String gStateString = game.getState();
        
        switch (gStateString)
        {
            case "MainMenuState":
                System.out.println("1 - Start Game");
                System.out.println("2 - Credits");
                System.out.println("3 - Exit Game");
                break;
            case "GetPlayerNameState":
                System.out.print("What's your name: ");
                break;
            case "CreditsState":
                System.out.println("Main Developer: Bruno 'GothicDread' Junqueira");
                break;
            case "BattleMenuState":
                System.out.println("1 - Attack");
                System.out.println("2 - Defend");
                System.out.println("3 - Heal");
                break;
            case "ExitState":
                System.out.println("Thank you for Playing!");
                System.exit(0);
            default:
                System.out.println("FATAL ERROR - UNKNOWN GAME STATE!");
                System.exit(1);
        }
        
        char input = sc.next().charAt(0);
        game.handleInput(input);
    }
}