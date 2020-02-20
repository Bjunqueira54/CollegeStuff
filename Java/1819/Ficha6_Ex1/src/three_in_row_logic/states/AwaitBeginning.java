package three_in_row_logic.states;

import three_in_row_logic.GameData;

public class AwaitBeginning extends StateAdapter 
{   
    public AwaitBeginning(GameData g) 
    {
        super(g);
    }
    
    @Override
    public IStates setNumberPlayers(int num)
    { 
        getGame().setNumPlayers(num);
        return this; 
    }
    
    @Override
    public IStates setName(int num, String name)
    { 
        /*...*/
        return this; 
    }
    
    @Override
    public IStates startGame()
    {
        if(getGame().initialize())
        {
            return new AwaitPlacement(getGame());
        }
        
        return this; 
    }  
 }
