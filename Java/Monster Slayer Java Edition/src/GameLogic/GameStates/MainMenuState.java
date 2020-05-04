package GameLogic.GameStates;

import GameLogic.GameData;

public class MainMenuState extends StateAdapter
{
    private GameData gData;
    
    public MainMenuState()
    {
        super();
        this.gData = new GameData();
    }
    
    public MainMenuState(GameData gData)
    {
        super();
        this.gData = gData;
    }

    @Override
    public GameState handleInput(char input)
    {
        switch(input)
        {
            case '1':
                return new GetPlayerNameState(gData);
            case '2':
                return new CreditsState();
            case '3':
                return new ExitState();
            default:
                return this;
        }
    }
    
    @Override
    public String getStateName() { return "MainMenuState"; }
}