package GameLogic.GameStates;

import GameLogic.GameData;

public class GetPlayerNameState extends StateAdapter
{
    private GameData gData;
    private String name;
    private boolean isInstanced;
    
    public GetPlayerNameState(GameData gData)
    {
        super();
        this.gData = gData;
        name = "";
        isInstanced = false;
    }

    @Override
    public GameState handleInput(char input)
    {
        if(input != '\n')
        {
            name += input;
            return this;
        }
        else
        {
            gData.setPlayerName(name);
            return new BattleMenuState(gData);
        }
    }

    @Override
    public String getStateName() { return "GetPlayerNameState"; }
    
    public String askPlayerName()
    {
        if(!isInstanced)
        {
            isInstanced = true;
            return "What's your name?";
        }
        
        return "";
    }
}