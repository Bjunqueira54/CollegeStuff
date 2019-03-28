package GameLogic;

import java.util.ArrayList;
import java.util.List;

public class Player implements Constantes
{
    String name;
    int id;
    
    List<Token> tokens;
    
    public Player(String name)
    {
        this(name, 0);
    }
    
    public Player(String name, int id)
    {
        this.name = name;
        this.id = id;
        this.tokens = new ArrayList<>();
        getNewTokens();
    }
    
    public final void getNewTokens()
    {
        tokens.clear();
        
        for(int i = 0; i < nTokens; i++)
            tokens.add(new Token(this));
    }
    
    public int getNumAvailableTokens() { return tokens.size(); }
    
    public boolean hasTokens() { return !tokens.isEmpty(); }
    
    public void setName(String name) { this.name = name; }
}