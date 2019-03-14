package MonsterSlayer;

import java.util.Scanner;

public class Game
{
    Player hero;
    NPC monster;
    String name;
    //Interface window;
    
    public Game(String GameTitle)
    {
	//window = new Interface(GameTitle, 800, 600);
    }
    
    //public Interface getInterfaceWindow() { return window; }
    
    public static void main(String[] args)
    {
	Scanner sc = new Scanner(System.in);
	Game game = new Game("Monster Slayer");
    }
}
