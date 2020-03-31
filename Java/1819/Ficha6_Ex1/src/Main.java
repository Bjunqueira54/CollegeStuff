import three_in_row_logic.ThreeInRowGame;
import three_in_row_ui.TextUI;

public class Main 
{
    public static void main(String[] args)
    {       
        TextUI textUI = new TextUI(new ThreeInRowGame());
        textUI.run();   
    }
}
