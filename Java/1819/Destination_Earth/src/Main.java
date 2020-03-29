import gameLogic.Game;
import ui.text.MainText;

public class Main
{
    public static void main(String[] args)
    {
        MainText text = new MainText(new Game());
        
        text.run();
    }
}