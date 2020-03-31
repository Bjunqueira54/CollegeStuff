package gameLogic.States;

import gameLogic.GameData;

public class ChooseAdventureState extends StateAdapter
{
    public ChooseAdventureState(GameData g)
    {
        super(g);
        getGameData().ClearAdventure();
    }
    
    @Override
    public States ChooseDefaultAdventure()
    {
        getGameData().SetDefaultAdventure();
        
        return new MainMenu(getGameData());
    }
    
    @Override
    public States ChooseAdventure(String round)
    {
        getGameData().addRound(round);
        
        if(getGameData().isAdventureSet())
            return new MainMenu(getGameData());
        else
            return this;
    }
}