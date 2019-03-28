package GameLogic;

public class Token
{
    Player owner;

    public Token(Player owner)
    {
        this.owner = owner;
    }
    
    public Player getPlayer() { return owner; }
}