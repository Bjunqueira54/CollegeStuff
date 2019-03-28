package GameLogic;

public interface Estados
{
    public Estados setNumberPlayers(int nPlayers);
    public Estados setName(int iPlayer, String name);
    public Estados startGame(int nPlayers);
    public Estados placeToken(int x, int y);
    public Estados ReturnToken(int x, int y);
    public Estados quit();
}