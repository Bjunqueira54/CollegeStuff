package GameLogic.GameStates;

public class CreditsState extends StateAdapter
{
    public CreditsState()
    {
        super();
    }

    @Override
    public GameState handleInput(char input) { return new MainMenuState(); }
    
    @Override
    public String getStateName() { return "CreditsState"; }
}