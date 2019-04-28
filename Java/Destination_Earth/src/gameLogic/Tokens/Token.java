package gameLogic.Tokens;

public abstract class Token
{
    private int curPos;
    
    public Token(int room)
    {
        curPos = room;
    }
    
    public int getCurrentRoom() { return curPos; }
}