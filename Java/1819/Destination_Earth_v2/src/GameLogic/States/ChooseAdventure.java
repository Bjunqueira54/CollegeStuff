package GameLogic.States;

import GameLogic.Exceptions.InvalidRoundException;
import GameLogic.GameData;

public class ChooseAdventure extends gStateAdapter
{
    private GameData data;
    public ChooseAdventure(GameData data) { this.data = data; }
    
    @Override
    public String toString()
    {
        return "ChooseAdventure";
    }

    @Override
    public gState ChooseRound(String round) throws InvalidRoundException
    {
        int rnd;
        
        if(round.length() >= 2 && (round.charAt(0) >= '1' && round.charAt(0) <= '8') && round.charAt(1) == '*')
        {
            rnd = Character.getNumericValue(round.charAt(0));
            
            if(rnd >= 1 && rnd <= 8)
                data.addRound(rnd + 10);
        }
        else if((round.charAt(0) >= '1' && round.charAt(0) <= '8') && round.length() == 1)
        {
            rnd = Character.getNumericValue(round.charAt(0));
            
            if(rnd >= 1 && rnd <= 8)
                data.addRound(rnd);
        }
        else if(Character.toLowerCase(round.charAt(0)) == 'r')
        {
            data.addRound(0);
        }
        else
            throw new InvalidRoundException();
        
        if(data.isAdventureComplete())
            return new MainMenu(data);
        else
            return this;
    }

    @Override
    public gState setDefaultAdventure()
    {
        data.setDefaultAdventure();
        
        return new MainMenu(data);
    }
    
    @Override
    public gState clearAdventure()
    {
        data.clearAdventure();
        
        return this;
    }
}