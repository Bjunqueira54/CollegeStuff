package Text_UI;

import GameLogic.MainGame;

public class Main
{
    public static void main(String[] args)
    {
        MainGame game = new MainGame();
        UIText uiText = new UIText(game);
        
        uiText.run();
    }
}