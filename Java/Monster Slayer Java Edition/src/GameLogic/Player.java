package GameLogic;

public class Player
{
    private String name;
    
    private int hp;
    private boolean blocking;
    
    public Player(String name)
    {
        this.name = name;
        this.hp = 100;
        this.blocking = false;
    }
    
    public Player() { this("DefaultName"); }
    
    /**
     * Sets the Player's name after the GameData class has been
     * innitialized, but Player name hasn't been set yet.
     * @param name
     */
    public void SetPlayerName(String name)
    {
        if(this.name.equals("DefaultName"))
            this.name = name;
    }
    
    public final int getHP() { return this.hp; }
    public final String getName() { return this.name; }
    public final boolean isBlocking() { return this.blocking; }
    
    /**
     * Modifies the HP depending on value.
     * Accepts both positive and negative numbers.
     * @param value - The value to modify the HP.
     */
    public void setHP(int value) { this.hp += value; }

    @Override
    public String toString() { return "Name: " + getName() + "\nHP: " + getHP(); }
}