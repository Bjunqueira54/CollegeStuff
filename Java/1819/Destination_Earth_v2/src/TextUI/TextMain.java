package TextUI;

import GameLogic.Exceptions.*;
import java.util.Scanner;
import GameLogic.Game;
import java.util.ArrayList;

public class TextMain
{
    Scanner sc;
    Printer pr;
    Game game;
    
    int opt;
    
    boolean quitting;
    
    private class Printer
    {
        public Printer() {}
        
        public void PrintAdventureMenu()
        {
            PrintMenuInfo();
            System.out.println("1 - Add Alien Round");
            System.out.println("2 - Add Retreating Alien Round");
            System.out.println("3 - Add Resting Round");
            System.out.println("4 - Create the default adventure");
            System.out.println("5 - Clear Adventure");
            System.out.println("0 - Back to the main menu...");
        }
        
        public void PrintMenuInfo()
        {
            System.out.println("Crew: " + game.getCrewMembers());
            System.out.println("Adventure: " + game.getAdventure());
            System.out.println("");
        }
        
        public void PrintMainMenu()
        {
            PrintMenuInfo();
            System.out.println("1 - Start Game");
            System.out.println("2 - Select Crew");
            System.out.println("3 - Choose Adventure");
            System.out.println("0 - Quit Game");
        }
        
        public void PrintCrewChoice(ArrayList<String> crew)
        {
            for(int i = 1; i <= crew.size(); i++)
            {
                System.out.println(i + " - " + crew.get(i - 1));
            }
            
            System.out.println("0 - Quit Game");
        }
        
        public void PrintCrewMenu(int page)
        {
            PrintMenuInfo();
            
            if(page == 1)
            {
                System.out.println("1 - Captain");
                System.out.println("2 - Commander");
                System.out.println("3 - Communications Officer");
                System.out.println("4 - Doctor");
                System.out.println("5 - Engineer");
                System.out.println("6 - Moral Officer");
                System.out.println("7 - Navigation Officer");
                System.out.println("8 - Red Shirt");
                System.out.println("9 - Next Page");
                System.out.println("0 - Back to Main Menu...");
            }
            else if(page == 2)
            {
                System.out.println("1 - Science Officer");
                System.out.println("2 - Security Officer");
                System.out.println("3 - Shuttle Pilot");
                System.out.println("4 - Transporter Chief");
                System.out.println("9 - Previous Page");
                System.out.println("0 - Back to Main Menu...");
            }
        }
        
        public void PrintGameStats()
        {
            System.out.println(game.getCrewMembersWithLocation());
            System.out.println(game.stats());
        }
        
        public void PrintActionMenu(String cm)
        {
            PrintGameStats();
            
            int i = 1;
            System.out.println(i++ + " - Move (1AP)");
            System.out.println(i++ + " - Attack (1AP)");
            System.out.println(i++ + " - Set Trap (1AP)");
            System.out.println(i++ + " - Seal Room (1AP)");
            
            if(game.hasSetParticleDispenser())
                System.out.println(i++ + " - Detonate Particle Dispenser (1AP)");
            
            if(cm.equalsIgnoreCase("Doctor"))
                System.out.println(i++ + " - Heal 1 Health (1AP)");
            
            if(cm.equalsIgnoreCase("Engineer"))
                System.out.println(i++ + " - Fix 1 Hull (1AP)");

            if(cm.equalsIgnoreCase("Red Shirt"))
                System.out.println(i++ + " - Sacrifice Red Shirt(1AP) (+5HP)");
            
            if(i + 1 == 9)
                System.out.println("9 - Next Page...");
            
            System.out.println("0 - Quit Game");
        }
    }
    
    public TextMain()
    {
        sc = new Scanner(System.in);
        pr = new Printer();
        game = new Game();
        quitting = false;
    }
    
    private void MainMenu()
    {
        pr.PrintMainMenu();
        opt = sc.nextInt();
        
        switch(opt)
        {
            case 1:
                game.StartGame();
                break;
            case 2:
                game.ChooseCrew();
                break;
            case 3:
                game.ChooseAdventure();
                break;
            case 4:
                //secret options to reset the game
                game.reset();
                break;
            case 0:
                quitting = true;
                break;
            default:
                break;
        }
    }
    
    private void ChooseCrewMenu()
    {
        int page = 1;
        
        if(game.crewComplete())
            game.ClearCrew();

        do
        {
            pr.PrintCrewMenu(page);
            
            opt = sc.nextInt();
            
            if(opt == 9)
                page = (page == 1) ? 2 : 1;
        }
        while(opt == 9);
        
        try
        {
            if(page == 1)
            {
                switch(opt)
                {
                    case 1:
                        game.ChooseCrewMember("Captain");
                        break;
                    case 2:
                        game.ChooseCrewMember("Commander");
                        break;
                    case 3:
                        game.ChooseCrewMember("CommsOfficer");
                        break;
                    case 4:
                        game.ChooseCrewMember("Doctor");
                        break;
                    case 5:
                        game.ChooseCrewMember("Engineer");
                        break;
                    case 6:
                        game.ChooseCrewMember("MoralOfficer");
                        break;
                    case 7:
                        game.ChooseCrewMember("NavigationOfficer");
                        break;
                    case 8:
                        game.ChooseCrewMember("RedShirt");
                        break;
                    case 0:
                        game.MainMenu();
                        break;
                    default:
                        break;
                }
            }
            else if(page == 2)
            {
                switch(opt)
                {
                    case 1:
                        game.ChooseCrewMember("ScienceOfficer");
                        break;
                    case 2:
                        game.ChooseCrewMember("SecurityOfficer");
                        break;
                    case 3:
                        game.ChooseCrewMember("ShuttlePilot");
                        break;
                    case 4:
                        game.ChooseCrewMember("TransportChief");
                        break;
                    case 0:
                        game.MainMenu();
                        break;
                    default:
                        break;
                }
            }
        }
        catch(InvalidCrewMemberException ex)
        {
            System.out.println("Trying to be smart eh? No idea how you did it, but no custom strings allowed.");
        }
        catch(CrewMemberAlreadySelectedException ex)
        {
            System.out.println("You're already selected that crew member.");
        }
    }
    
    private void ChooseAdventure()
    {
        pr.PrintAdventureMenu();
        
        opt = sc.nextInt();
        
        try
        {
            switch(opt)
            {
                case 1:
                    System.out.print("Number of Aliens to spawn: ");
                    game.addRound(sc.next());
                    break;
                case 2:
                    System.out.print("Number of Aliens to spawn: ");
                    game.addRound(sc.next() + "*");
                    break;
                case 3:
                    game.addRound("R");
                    break;
                case 4:
                    game.setDefaultAdventure();
                    break;
                case 5:
                    game.ClearAdventure();
                    break;
                case 0:
                    game.MainMenu();
                    break;
                default:
                    break;
            }
        }
        catch(InvalidRoundException ex)
        {
            System.out.println("Something went wrong. InvalidRoundException.");
        }
    }
    
    private void FindOption(String cm)
    {
        if(cm.equalsIgnoreCase("Doctor"))
            game.Heal();
        else if(cm.equalsIgnoreCase("Engineer"))
            game.Repair();
        else if(cm.equalsIgnoreCase("Red Shirt"))
            game.Sacrifice();
    }
    
    private void ChooseAction(String cm)
    {
        pr.PrintActionMenu(cm);
        
        opt = sc.nextInt();
        
        switch(opt)
        {
            case 1: //move
                //game.Move(cm);
                break;
            case 2: //attack
                //game.Attack(cm);
                break;
            case 3: //set trap
                //game.SetTrap(cm);
                break;
            case 4: //seal room
                //game.SealRoom(cm);
                break;
            case 5:
                if(game.hasSetParticleDispenser())
                    //game.BlowParticleDispenser(cm);
                    break;
                else
                    //Usar uma função para descobrir que opção é que foi usada.
                    //FindOption(cm);
                    break;
            case 6:
                //Usar uma função para descobrir que opção é que foi usada.
                //FindOption(cm);
                break;
            case 0:
                game.QuitGame();
                break;
            default:
                break;
        }
    }
    
    private void ChooseCrewMember()
    {
        ArrayList<String> crew = game.getCrewMembersAsList();
        
        if(crew == null)
            return;
        
        pr.PrintCrewChoice(crew);
        
        opt = sc.nextInt();
        
        if(opt > 0 && opt <= crew.size())
            ChooseAction(crew.get(opt - 1));
        else
            System.out.println("Invalid Choice");
    }
    
    public void run()
    {
        while(!quitting)
        {
            if(game.getState().equalsIgnoreCase("MainMenu"))
                MainMenu();
            else if(game.getState().equalsIgnoreCase("ChooseCrew"))
                ChooseCrewMenu();
            else if(game.getState().equalsIgnoreCase("ChooseAdventure"))
                ChooseAdventure();
            else if(game.getState().equalsIgnoreCase("AwaitPlayerChoice"))
                ChooseCrewMember();
        }
    }
}