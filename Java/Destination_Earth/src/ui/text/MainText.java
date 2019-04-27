package ui.text;

import java.util.Scanner;
import gameLogic.Game;
import gameLogic.States.ChooseCrewState;
import gameLogic.States.MainMenu;
import gameLogic.Crew.*;
import gameLogic.Exceptions.CrewMemberAlreadyPresentException;

public class MainText
{
    boolean quit = false;
    Scanner sc;
    Game game;
    
    int[] taken = {0,0};
    int count = 0;
    CrewMembersText crew_names;
    
    public MainText(Game game)
    {
        sc = new Scanner(System.in);
        this.game = game;
        crew_names = new CrewMembersText();
    }
    
    private void PrintMainMenu()
    {
        System.out.println("1 - Start Game");
        System.out.println("2 - Choose Adventure");
        System.out.println("3 - Choose Crew");
        System.out.println("4 - Quit Game");
    }
    
    private void PrintCrewOptions(int page)
    {
        crew_names.CrewOptions(taken, page);
    }
    
    public void AddCrewMember(int menu_page, int opt) throws CrewMemberAlreadyPresentException
    {
        if(menu_page == 1)
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
        else if(menu_page == 2)
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
    
    public void ChooseCrew()
    {
        game.SetState(new ChooseCrewState(game.getGameData()));
        
        int opt;
        int menu_page = 1;

        while(!game.CompleteCrew())
        {
            PrintCrewOptions(menu_page);
            
            opt = Read();
            
            menu_page = ChooseCrewProcessing(menu_page, opt);
        }
    }
    
    //menu_page = 
    private int ChooseCrewProcessing(int menu_page, int opt)
    {
        if(verifyOption(opt, menu_page))
        {
            if(opt == 0)
            {
                if(menu_page == 1)
                    return 2;
                else 
                    return 1;
            }
            else
            {
                try
                {
                    AddCrewMember(menu_page, opt);
                }
                catch(CrewMemberAlreadyPresentException ex)
                {
                    System.out.println("Crew Member Already Selected");
                }
            }
        }
        return 1;
    }
    
    private boolean verifyOption(int opt, int page)
    {
        return ((page == 1 && (opt >= 0 && opt <= 9)) || (page == 2 && (opt >= 0 && opt <= 3)));
    }
    
    public void run()
    {
        int opt;
        
        while(!quit)
        {
            game.SetState(new MainMenu(game.getGameData()));
            PrintMainMenu();
            
            opt = Read();
            
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
    
    private int Read()
    {
        ChooseText();
        return sc.nextInt();
    }
    
    private void ChooseText()
    {
        System.out.print("Escolha\n-> ");
    }
}