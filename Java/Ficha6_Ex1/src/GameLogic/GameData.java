package GameLogic;

import java.util.ArrayList;
import java.util.List;

public class GameData implements Constantes
{
    List<Player> players;
    Token grid[][];
    
    int nPlayers;
    int nCurrentPlayer;
    
    public GameData()
    {
        players = new ArrayList<>();
        nPlayers = 2;
        nCurrentPlayer = 1;
        players.add(new Player("PlayerA", 1));
        players.add(new Player("PlayerB", 2));
        
        grid = new Token[dim][dim];
    }
    
    public void initialize()
    {
        for (Player player : players)
            player.getNewTokens();
        
        grid = new Token[dim][dim];
    }
    
    public void setNumPlayers(int nPlayers)
    {
        this.nPlayers = nPlayers;
    }
    
    public Player getCurrentPlayer()
    {
        return players.get(nCurrentPlayer - 1);
    }
    
    public void setPlayerName(int index, String name)
    {
        players.get(index - 1).setName(name);
    }
}