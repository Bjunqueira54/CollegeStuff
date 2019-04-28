package ui.text;

import java.util.Scanner;
import gameLogic.Game;
import gameLogic.States.*;
import gameLogic.Crew.*;
import gameLogic.Exceptions.*;
import java.util.ArrayList;
import java.util.InputMismatchException;

public class MainText
{
    boolean quit = false;
    int menu_crew_page = 1;
    Scanner sc;
    Game game;
    
    int count = 0;
    CrewMembersText crew_names;
    
    public MainText(Game game)
    {
        sc = new Scanner(System.in);
        this.game = game;
        crew_names = new CrewMembersText();
    }
    
    private States getGameState() { return game.getGameState(); }
    
    private void PrintMainMenu()
    {
        System.out.println("1 - Start Game");
        System.out.println("2 - Choose Adventure");
        System.out.println("3 - Choose Crew");
        System.out.println("0 - Quit Game");
    }
    
    private void PrintCrewMenu(int page)
    {
        crew_names.CrewOptions(page);
    }
    
    private void PrintAdventureMenu()
    {
        System.out.println("1 - Spawn Aliens");
        System.out.println("2 - Spawn Aliens with Retreat");
        System.out.println("3 - Rest");
        System.out.println("4 - Default Adventure");
        System.out.println("0 - Exit");
    }
    
    private void PrintSpawnAliensMenu()
    {
        System.out.println("1 - 1 Alien");
        System.out.println("2 - 2 Aliens");
        System.out.println("3 - 3 Aliens");
        System.out.println("4 - 4 Aliens");
        System.out.println("5 - 5 Aliens");
        System.out.println("6 - 6 Aliens");
        System.out.println("7 - 7 Aliens");
        System.out.println("8 - 8 Aliens");
        System.out.println("9 - 9 Aliens");
    }
    
    private void PrintGameStats()
    {
        int round = game.getRoundNumber();
        
        System.out.println("Round: " + round + "\tRound Type: " + game.getRoundType(round));
        System.out.println("HP: " + game.getHP() + "\tAP: " + game.getAP() + "\tIP: " + game.getIP());
        System.out.print(game.getCrewMembersInfo());
        System.out.println(game.getRoomsWithAliens());
    }
    
    private void PrintRoundMenu()
    {
        System.out.println("\nSelect Crew Member");
        System.out.println("1 - " + game.getCrewMember(1));
        System.out.println("2 - " + game.getCrewMember(2));
        System.out.println("0 - Quit Game");
    }
    
    private void PrintActionMenu(CrewMembers cm)
    {
        System.out.println("1 - Attack");
        System.out.println("2 - Move");
        System.out.println("3 - Place Organic Detonator");
        System.out.println("4 - Place Particle Dispenser");
        System.out.println("5 - Seal Room");
        
        if(cm instanceof Doctor)
            System.out.println("6 - Heal");
        else if(cm instanceof Engineer)
            System.out.println("6 - Repair");
        
        System.out.println("0 - Back");
    }
    
    public int AdjacentRoomMenu(int room)
    {
        String parse = game.getAdjacentRooms(room);
        String parts = parse.replaceAll("[^0-9]", " ");
        String strarray[] = parts.split(" ");
        
        ArrayList<Integer> choice = new ArrayList<>();
        
        int i;
        
        for(i = 0; i < strarray.length; i++)
        {
            if(strarray[i].equals(""))
                continue;
            
            choice.add(Integer.parseInt(strarray[i]));
        }
        
        for(i = 0; i < choice.size(); i++)
            System.out.println(i+1 + " - Room #" + choice.get(i).intValue());
        
        System.out.println(i + 1 + " - Room #" + room);
        choice.add(room);
        System.out.println("0 - Back...");
        
        do
        {
            i = Read();
        }
        while(!choice.contains((Integer) i) || i == 0);
        
        return choice.get(choice.indexOf((Integer) i));
    }
    
    public void PrintSealRoomMenu()
    {
        System.out.println("1 - Brig, Room #3");
        System.out.println("2 - Crew Quarters, Room #4");
        System.out.println("3 - Weapon's Bay, Room #7");
        System.out.println("4 - Engineering, Room #9");
        System.out.println("5 - Holodeck, Room #11");
        System.out.println("6 - Hydroponics, Room #12");
        System.out.println("0 - Back...");
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
        int opt;

        PrintCrewMenu(menu_crew_page);

        opt = Read();

        menu_crew_page = ChooseCrewProcessing(menu_crew_page, opt);
    }
    
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
    
    private boolean verifyOption(int opt)
    {
        return (opt >= 0 && opt <= 9);
    }

    public void ChooseAdventure()
    {
        int opt;
        
        System.out.println(game.getRoundsAsString());
        PrintAdventureMenu();

        opt = Read();

        if(opt >= 0 && opt <= 4)
        {
            switch(opt)
            {
                case 1:
                    SpawnAliens(false);
                    break;
                case 2:
                    SpawnAliens(true);
                    break;
                case 3:
                    game.addRestingRound();
                    break;
                case 4:
                    game.SetDefaultAdventure();
                    break;
                default:
                    break;
            }
        }
    }
    
    public void SpawnAliens(boolean retreating)
    {
        int opt;
        PrintSpawnAliensMenu();
        
        opt = Read();
        
        if(verifyOption(opt))
        {
            if(retreating)
                game.addSpawnRetreatingAliensRound(opt);
            else
                game.addSpawnAliensRound(opt);
        }
    }
    
    private int Read()
    {
        ChooseText();
        try
        {
            return sc.nextInt();
        }
        catch(InputMismatchException ex)
        {
            sc.next();
            return -1;
        }
    }
    
    private void ChooseText()
    {
        System.out.print("Escolha\n-> ");
    }
    
    private void RoundMenu()
    {
        int opt;
        
        PrintGameStats();
        
        PrintRoundMenu();
        
        opt = Read();
        
        if(opt == 0)
        {
            game.quitgame();
            return;
        }
        
        CrewMembers cm = game.getCrewMember(opt);
        
        if(cm != null)
        {
            PrintActionMenu(cm);
            
            opt = Read();
            
            switch(opt)
            {
                case 1: //Attack
                {
                    int room;
                    if(cm instanceof ScienceOfficer)
                    {
                        room = AdjacentRoomMenu(cm.getCurrentPosition());
                    }
                    else
                        room = cm.getCurrentPosition();
                    try
                    {
                        game.SetState(getGameState().Attack(cm, room));
                    }
                    catch(InvalidRoomException ex)
                    {
                        System.out.println("Invalid Room Choice");
                    }
                    catch(NoAliensToAttackException ex)
                    {
                        System.out.println("There's no Aliens to attack in that room");
                    }
                    break;
                }
                case 2: //move
                {
                    int room = AdjacentRoomMenu(cm.getCurrentPosition());
                    
                    try
                    {
                        game.SetState(getGameState().Move(cm, room));
                    }
                    catch(InvalidRoomException ex)
                    {
                        System.out.println("Invalid Room Choice");
                    }
                    
                    break;
                }
                case 3: //Place Organic Detonator
                    try
                    {
                        game.SetState(getGameState().PlaceOrganicDetonator(cm));
                    }
                    catch(NoOrganicDetonatorsException ex)
                    {
                        System.out.println("No Organic Detonators remaining");
                    }
                    break;
                case 4: //Place Particle Dispenser
                    try
                    {
                        game.SetState(getGameState().PlaceParticleDispenser(cm));
                    }
                    catch(NoParticleDispensersException ex)
                    {
                        System.out.println("No Particle Dispensers remaining");
                    }
                    break;
                case 5: //Seal a room
                {
                    PrintSealRoomMenu();
                    
                    opt = Read();
                    
                    if(opt > 6)
                        break;
                    
                    try
                    {
                        game.SetState(getGameState().SealRoom(opt));
                    }
                    catch(NoSealRoomTokensExceptions ex)
                    {
                        System.out.println("No Seal Room Tokens remaining.");
                    }
                    catch(RoomAlreadySealedException ex)
                    {
                        System.out.println("This room as already been sealed!");
                    }
                    break;
                }
                case 6: //Heal OR repair
                    break;
                case 0: //Back
                    return;
                default:
            }
        }
    }
    
    public void run()
    {
        while(!quit)
        {
            States state = getGameState();
            
            if(state instanceof MainMenu)
            {
                MainMenu();
            }
            else if(state instanceof ChooseCrewState)
            {
                ChooseCrew();
            }
            else if(state instanceof ChooseAdventureState)
            {
                ChooseAdventure();
            }
            else if(state instanceof AwaitRoundPlayerChoice)
            {
                RoundMenu();
            }
            else if(state instanceof AwaitRestingPlayerChoice)
            {
                //RestingMenu();
            }
        }
    }
    
    public void MainMenu()
    {
        int opt;
        
        System.out.println(game.getRoundsAsString());
        System.out.println(game.getCrewMembersAsString());
        PrintMainMenu();

        opt = Read();

        switch(opt)
        {
            case 1:
                game.start();
                break;
            case 2:
                game.ChooseAdventure();
                break;
            case 3:
                game.ChooseCrew();
                break;
            case 0:
                quit = true;
                break;
            default:
                break;
        }
    }
}