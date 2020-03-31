package three_in_row_logic;

import java.util.ArrayList;
import java.util.List;

public class GameData implements Constants
{
    private List<Player> players;

    private int numCurrentPlayer;
    private int numPlayers;
    private Token[][] grid;
   
    public GameData() 
    {
        players = new ArrayList<>();
        numCurrentPlayer = -1;
        numPlayers = 2; 
        players.add(new Player("A"));
        players.add(new Player("B"));
        grid = new Token[DIM][DIM];
    }
    
    public boolean initialize() 
    {
        grid = new Token[DIM][DIM];
        players.get(0).getNewTokens();
        players.get(1).getNewTokens();

        numCurrentPlayer = 1;

        return true;
    }
    
    public int getNumPlayers() 
    {
        return numPlayers;
    }    
        
    public int getNumCurrentPlayer() 
    {
        return numCurrentPlayer;
    }

    public int getNumNotCurrentPlayer() 
    {
        return (numCurrentPlayer == 1 ? 2: 1);
    }

    public Player getCurrentPlayer() 
    {
        if(numCurrentPlayer > 0 && numCurrentPlayer <= players.size()){
            return players.get(numCurrentPlayer - 1);
        }
        
        return null;
    }

    public Player getNotCurrentPlayer() 
    {
        if (numCurrentPlayer == 1) {
            return players.get(1);
        } else if (numCurrentPlayer == 2) {
            return players.get(0);
        }
        
        return null;
    }
    
    public Player getPlayer(int number) 
    {
        if (number <= 0 || number > players.size())
            return null;
        
        return players.get(number-1);
    }        

    public Token getToken(int line, int column) 
    {
        if (line < 0 || line >= DIM || column < 0 || column >= DIM) {
            return null;
        }
        
        if (grid == null) {
            return null;
        }
        
        return grid[line][column];
    }
    
    public boolean setNumPlayers(int numPlayers) 
    {
        this.numPlayers = 0;
        
        if (numPlayers < 0 || numPlayers > 2) {
            return false;
        }

        this.numPlayers = numPlayers;

        return true;
    }
        
    public void setPlayer(int num, Player player) 
    {
        players.set(num, player);
    }
    
    public void setNextPlayerTurn() 
    {
        numCurrentPlayer = (numCurrentPlayer == 1 ? 2 : 1);
    }

    public boolean setPlayerName(int num, String name) 
    {
        try{
            players.get(num-1).setName(name);
            return true;
        }catch(IndexOutOfBoundsException e){
            return false;
        }
    }
    
    public boolean placeToken(Token token, int line, int column) 
    {
        if (line < 0 || line >= DIM || column < 0 || column >= DIM) {
            return false;
        }
        
        if (grid[line][column] != null) {
            return false;
        }
        
        grid[line][column] = token;
        return true;
    }

    public boolean removeToken(int line, int column) 
    {
        if (line < 0 || line >= DIM || column < 0 || column >= DIM) {
            return false;
        }
        
        if (grid[line][column] == null) {
            return false;
        }
        
        grid[line][column] = null;
        return true;
    }
        
    public boolean isOver() 
    {
        return hasWon(players.get(0)) || hasWon(players.get(1));

    }
    
    public boolean hasWon(Player player) 
    {
        return isAlignedH(player) || isAlignedD(player) || isAlignedV(player);
    }
    
    private boolean isAlignedH(Player player) 
    {
        for (int i = 0; i < DIM; i++) {
            if (isAlignedH(player, i)) {
                return true;
            }
        }
        return false;
    }
    
    private boolean isAlignedH(Player player, int line)
    {
        for (Token token : grid[line]) {
            if (token == null || token.getPlayer() != player) {
                return false;
            }
        }
        return true;
    }

    private boolean isAlignedV(Player player)
    {
        for (int i = 0; i < DIM; i++) {
            if (isAlignedV(player, i)) {
                return true;
            }
        }
        return false;
    }
    
    private boolean isAlignedV(Player player, int column) 
    {
        for (int i = 0; i < grid[column].length; i++) {
            Token token = grid[i][column];
            if (token == null || token.getPlayer() != player) {
                return false;
            }
        }
        return true;
    }
 
    private boolean isAlignedD(Player player) 
    {
        return isAlignedMainD(player) || isAlignedSecondaryD(player);
    }

    private boolean isAlignedMainD(Player player) 
    {
        for (int i = 0; i < DIM; i++) {
            if (grid[i][i] == null || grid[i][i].getPlayer() != player) {
                return false;
            }
        }
        return true;
    }

    private boolean isAlignedSecondaryD(Player player) 
    {
        for (int i = 0; i < DIM; i++) {
            if (grid[i][DIM - 1 - i] == null || grid[i][DIM - 1 - i].getPlayer() != player) {
                return false;
            }
        }
        return true;
    }           

    public String gridToString() 
    {
        String s = "";
        
        s += String.format("\t%5s", "");
        
        for (int i = 0; i < DIM; i++){
            s += String.format("%4d", i+1);
        }
        
        s+= String.format("\n\t%5s", "");
        
        for (int i = 0; i < DIM; i++){
            s += String.format("%4s", "_");
        }
        
        s += "\n";
        
        for (int i = 0; i < DIM; i++) {
            
            s += String.format("\t%4d|", i+1);
            
            for (int j = 0; j < DIM; j++) {
                
                String boardSquare;
                
                if (grid[i][j] != null) {
                    boardSquare = "" + grid[i][j].getPlayer().getName().charAt(0);
                } else {
                    boardSquare = " ";
                }
                
                s += String.format("%4s", boardSquare);
            
            }
            
            s += '\n';
        
        }
        
        return s;
    }                
}
