package three_in_row_logic.states;

import three_in_row_logic.Player;
import three_in_row_logic.GameData;
import three_in_row_logic.Token;

public class AwaitReturn extends StateAdapter
{    
    public AwaitReturn(GameData g) 
    {
        super(g);
    }

    @Override
    public IStates returnToken(int line, int column)
    { 
        Player p = getGame().getCurrentPlayer();
        
        if (line < 0 || line >= DIM || column < 0 || column >= DIM) 
        {
            return this;
        }
        
        Token Token = getGame().getToken(line, column);
        
        if (Token == null || Token.getPlayer() != p)
        {
            return this;
        }
        
        p.getAvailableTokens().add(Token);
        getGame().removeToken(line, column);
        return new AwaitPlacement(getGame());
    }
    
    @Override
    public IStates quit()
    { 
        getGame().getNotCurrentPlayer().setHasWon(true);
        return new AwaitBeginning(getGame());
    }
}
