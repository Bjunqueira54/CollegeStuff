package ui.text;

import java.util.Scanner;
import gameLogic.Game;
import gameLogic.States.ChooseCrewState;
import gameLogic.States.MainMenu;
import gameLogic.Crew.*;

public class MainText
{
    boolean quit = false;
    Scanner sc;
    Game game;
    
    public MainText(Game game)
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
    
    private void PrintCrewOptions(int n)
    {
        if(n == 1)
        {
            System.out.println("1 - Captain");
            System.out.println("2 - Commander");
            System.out.println("3 - Communications Officer");
            System.out.println("4 - Doctor");
            System.out.println("5 - Engineer");
            System.out.println("6 - Moral Officer");
            System.out.println("7 - Navigation Officer");
            System.out.println("8 - Red Shirt");
            System.out.println("9 - Science Officer");
            System.out.println("0 - Next...");
        }
        else if (n == 2)
        {
            System.out.println("1 - Security Officer");
            System.out.println("2 - Shuttle Pilot");
            System.out.println("3 - Transporter Chief");
            System.out.println("0 - Previous...");
        }
    }
    
    public void AddCrewMember(int menustate, int opt)
    {
        if(menustate == 1)
        {
            switch(opt)
            {
                default:
                    break;
                case 1:
                    game.AddCrewMember(new Captain());
                    break;
                case 2:
                    game.AddCrewMember(new Commander());
                    break;
                case 3:
                    game.AddCrewMember(new CommsOfficer());
                    break;
                case 4:
                    game.AddCrewMember(new Doctor());
                    break;
                case 5:
                    game.AddCrewMember(new Engineer());
                    break;
                case 6:
                    game.AddCrewMember(new MoralOfficer());
                    break;
                case 7:
                    game.AddCrewMember(new NavigationOfficer());
                    break;
                case 8:
                    game.AddCrewMember(new RedShirt());
                    break;
                case 9:
                    game.AddCrewMember(new ScienceOfficer());
                    break;
            }
        }
        else
        {
            switch(opt)
            {
                default:
                    break;
                case 1:
                    game.AddCrewMember(new SecurityOfficer());
                    break;
                case 2:
                    game.AddCrewMember(new ShuttlePilot());
                    break;
                case 3:
                    game.AddCrewMember(new TransporterChief());
                    break;
            }
        }
    }
    
    public void ChooseCrew()
    {
        game.SetState(new ChooseCrewState(game.getGameData()));
        
        int opt;
        int menustate = 1;

        while(!game.CompleteCrew())
        {
            PrintCrewOptions(menustate);
            
            opt = sc.nextInt();
            
            if((menustate == 2) && (opt > 3)) {}
            else if (opt == 0)
            {
                if(menustate == 1)
                    menustate = 2;
                else
                    menustate = 1;
            }
            else
            {
                AddCrewMember(menustate, opt);
            }
        }
    }
    
    public void run()
    {
        int opt;
        
        while(!quit)
        {
            game.SetState(new MainMenu(game.getGameData()));
            PrintMainMenu();
            
            opt = sc.nextInt();
            
            switch(opt)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    ChooseCrew();
                    break;
                case 4:
                    quit = true;
                    break;
                default: break;
            }
        }
    }
}