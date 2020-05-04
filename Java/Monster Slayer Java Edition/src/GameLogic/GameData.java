package GameLogic;

public class GameData
{
    private Player player;
    private Monster monster;
    
    public GameData()
    {
        this.player = new Player();
        this.monster = new Monster();
    }
    
    public int getPlayerHP() { return this.player.getHP(); }
    public int getMonsterHP() { return this.monster.getHP(); }
    
    public void setPlayerName(String name) { player.SetPlayerName(name); }
    
    public boolean isOver()
    {
        if(getMonsterHP() == 0 || getPlayerHP() == 0)
            return true;
        else
            return false;
    }
}