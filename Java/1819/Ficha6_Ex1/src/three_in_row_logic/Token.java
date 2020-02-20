package three_in_row_logic;

public class Token
{  
    private Player player;

    public Token(Player player) 
    {
        this.player = player;
    }

    public Player getPlayer()
    {
        return player;
    }

    @Override
    public String toString()
    {
        return "" + player.getName().charAt(0);
    }   
}
