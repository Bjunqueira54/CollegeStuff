package GameLogic.States;

import GameLogic.GameData;

public class MainMenu extends gStateAdapter
{
    private GameData data;
    
    public MainMenu(GameData data)
    {
        this.data = data;
    }

    @Override
    public String toString()
    {
        return "MainMenu";
    }
}