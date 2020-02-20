package three_in_row_logic.states;

import three_in_row_logic.Player;
import three_in_row_logic.GameData;
import three_in_row_logic.Token;

public class AwaitPlacement extends StateAdapter
{
    private int prevLine, prevColumn;

    public AwaitPlacement(GameData g) 
    {
        super(g);
        prevLine = prevColumn = -1;
    }

    public AwaitPlacement(GameData g, int prevLine, int prevColumn) 
    {
        super(g);
        this.prevLine = prevLine;
        this.prevColumn = prevColumn;
    }

    public boolean isPrevLocation(int line, int column) 
    {
        return line == prevLine && column == prevColumn;
    }

    @Override
    public IStates placeToken(int line, int column) 
    {
        if(isPrevLocation(line, column))
        {
            return this;
        }
        
        if (line < 0 || line >= DIM || column < 0 || column >= DIM) 
        {
            return this;
        }
        
        Player p = getGame().getCurrentPlayer();        
        Token token = p.getAvailableTokens().get(0);

        if (getGame().placeToken(token, line, column)) 
        {           
            p.getAvailableTokens().remove(0);
            
            if (getGame().hasWon(p)) 
            {
                p.setHasWon(true);
                return /*...*/;
            }
            
            getGame().setNextPlayerTurn();
                        
            if(getGame().getCurrentPlayer().getNumAvailableTokens() > 0)
            {
                return /*...*/;
            }
            else
            {
                return /*...*/;
            }           
        } 
        
        return this;
    }

    @Override
    public IStates quit() 
    {
        getGame()./*...*/.setHasWon(true);
        return /*...*/;
    }   
}
