import gameLogic.Game;
import ui.text.TextMain;

public class Main
{
    public static void main(String[] args)
    {
        TextMain text = new TextMain(new Game());
        
        text.run();
    }
}
