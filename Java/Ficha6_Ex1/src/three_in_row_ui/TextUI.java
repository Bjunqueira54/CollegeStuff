package three_in_row_ui;

import three_in_row_logic.ThreeInRowGame;
import three_in_row_logic.states.AwaitPlacement;
import three_in_row_logic.states.AwaitReturn;
import three_in_row_logic.states.AwaitBeginning;
import three_in_row_logic.states.IStates;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class TextUI 
{
    private ThreeInRowGame game;
    private boolean quit = false;

    public TextUI(ThreeInRowGame game) 
    {
        this.game = game;
    }

    public void uiAwaitBeginning() 
    {
        Scanner sc = new Scanner(System.in);
        BufferedReader bin = new BufferedReader(new InputStreamReader(System.in));
        String option;
        char c;
        String [] words;
        int num;
        String name;
        
        System.out.println("\n=== AWAITING FOR THE BEGINNING OF THE GAME ===\n");
        System.out.println("Number of players: " + game.getNumPlayers() + "\n");
        System.out.println(game.getPlayer(1) != null ? "" + game.getPlayer(1) : "");
        System.out.println(game.getPlayer(2) != null ? "" + game.getPlayer(2) : "");
        
        
        if((game.getPlayer(1)!= null && game.getPlayer(1).getHasWon()) || (game.getPlayer(2)!= null && game.getPlayer(2).getHasWon() ))
        {    
            System.out.println(game.gridToString());
        }
        
        while (true) 
        {    
            do
            {               
                System.out.println();
                System.out.println("0 - Quit");
                System.out.println("1 - Set the number of players");
                System.out.println("2 - Set the name(s) of the player(s)");
                System.out.println("3 - Start");

                option = sc.next();
                
                if(option.length() >= 1)
                    c = option.charAt(0);
                else
                    c = ' ';
                
            } while(c < '0' || c > '3');
            
            switch(c)
            {    
                case '0':
                    quit = true;
                    return;

                case '1':
                    
                    System.out.println("Number of players (fixed in this version): 2");
                    game.setNumberPlayers(2);
                    
                    return;
                
                case '2':
                    
                    if(game.getNumPlayers()<1)
                        return;
                    
                    System.out.print("Enter the number of a player [1-" + game.getNumPlayers() + "] followed by its name: ");
                    
                    try
                    {    
                        option = bin.readLine().trim();
                        words = option.split(" ");
                        
                        if(words.length != 2)
                            return;
                                                
                        num = Integer.parseInt(words[0]);
                        
                        if(num < 1 || num > game.getNumPlayers())
                            return;
                        
                        name = words[1];

                        game.setPlayerName(num, name);
                        
                        System.out.println("number: " + num + "\tname: " + name);
                        
                    }catch (IOException | NumberFormatException ex) {System.out.println(ex);}
                                        
                    return;
                
                case '3': 
                    System.out.println("Game started");
                    
                    game.startGame();
                    return;
                    
                default:
                    return;
                    
            } //switch
            
        } //while
    
    } //uiWaitBeginning    

    public void uiAWaitPlacement()
    {
        Scanner sc = new Scanner(System.in);
        
        System.out.println();
        System.out.println("\n=== AWAITING FOR THE PLACEMENT OF A TOKEN === \n");
        System.out.println(game.getPlayer(1));
        System.out.println(game.getPlayer(2));
        System.out.println("\nCurrent player: " + game.getCurrentPlayerName());
        System.out.println(game.gridToString());

        System.out.println("\nPlay: line [1-3]  column [1-3]\nQuit: -1");
        System.out.print(game.getCurrentPlayerName() + "> ");
                
        while(!sc.hasNextInt())
        {
            sc.next();
        }
        
        int line = sc.nextInt();
        
        if (line == -1)
        {
            game.quit();
            return;
        }
        
        while(!sc.hasNextInt())
        {
            sc.next();
        }
        
        int column = sc.nextInt();
        
        game.placeToken(line-1, column-1);     
    }

    public void uiAWaitReturn() 
    {        
        System.out.println();
        System.out.println("\n=== AWAITING FOR THE RETURNING OF A TOKEN === \n");
        System.out.println(game.getPlayer(1));
        System.out.println(game.getPlayer(2));
        System.out.println("\nCurrent player: " + game.getCurrentPlayerName());
        System.out.println(game.gridToString());

        System.out.println("\nReturn : line [1-3] column [1-3]\nQuit: -1");
        System.out.print(game.getCurrentPlayerName() + "> ");
        
        Scanner sc = new Scanner(System.in);
        
        while(!sc.hasNextInt())
        {
            sc.next();
        }
        
        int line = sc.nextInt();
        
        if (line == -1) 
        {
            game.quit();
            return;
        }
        
        while(!sc.hasNextInt())
        {
            sc.next();
        }
        
        int column = sc.nextInt();
        
        game.returnToken(line-1, column-1);       
    }

    public void run() 
    {
        while (!quit) 
        {    
            IStates state = game.getState();
           
            if (state instanceof AwaitBeginning) 
            {
                uiAwaitBeginning();
            } 
            else if (state instanceof AwaitPlacement) 
            {
                uiAWaitPlacement();
            } 
            else if (state instanceof AwaitReturn) 
            {
                uiAWaitReturn();
            }           
        }
    }
}
