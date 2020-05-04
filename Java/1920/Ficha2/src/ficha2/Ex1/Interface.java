package ficha2.Ex1;

import java.util.Scanner;

public class Interface
{
    private final GameLogic game;
    private Scanner sc;
    private String letter;
    
    public Interface(GameLogic g)
    {
        sc = new Scanner(System.in);
        this.game = g;
    }
    
    public void run()
    {
        char option;
        
        System.out.print("What's your name: ");
        String name = sc.next();
        game.setPlayerName(name);
        
        do
        {
            play();
            
            System.out.print("Play again?(Y/y to confirm): ");
            option = sc.next().charAt(0);
        }
        while(Character.compare(Character.toLowerCase(option), 'y') == 0);
    }
    
    public void play()
    {
        game.newGame();
        
        while(!game.isGameOver())
        {
            System.out.println(game.getPlayerName());
            System.out.println("Score: " + game.getPlayerScore());
            System.out.println("Word: " + game.getGameWord());
            System.out.println("Lives: " + game.getLives());
            System.out.println("Used letters: " + game.getUsedLetters());
            
            if(game.isGameOver())
                continue;
            
            System.out.print("Choose a letter or a word: ");
            
            letter = sc.next();
            game.checkInput(letter);
        }
        
        if(game.getLives() <= 0)
            System.out.println("You Lost!");
        else
            System.out.println("You Won!\nThe word was: " + game.getGameWord());
    }
}