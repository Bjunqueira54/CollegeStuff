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
    public gState StartGame()
    {
        if(data.isAdventureComplete() && data.isCrewComplete())
        {
            data.StartGame();
            return new AwaitPlayerChoice(data);
        }
        else
            return this;
    }

    @Override
    public String toString()
    {
        return "MainMenu";
    }
}