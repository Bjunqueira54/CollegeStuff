package GameLogic;

public class Monster
{
    private int hp;
    private boolean stunned;
    private int stunDuration;
    
    private final int MAXHP = 250;
    private final int MINDMG = 15;
    private final int MAXDMG = 25;
    
    public Monster()
    {
        this.hp = MAXHP;
        this.stunned = false;
        this.stunDuration = 0;
    }
    
    public final int getHP() { return this.hp; }
    public final boolean isStunned() { return this.stunned; }
    public final int getStunDuration() { return this.stunDuration; }
    
    /**
     * Gets a damage value from the monster, between MAXDMG(25) and MINDMG(15).
     * The attack has a 5% chance to miss and a 5% chance to be a critical,
     * dealing Double Damage.
     * @return An integer of the full damage dealt by the monster (can be a critical) OR
     *  0 if the attack missed.
     */
    public final int getDamage()
    {
        int finalDamage = 0;
        int damageRange = MAXDMG - MINDMG + 1;
        
        //5% miss chance
        if((Math.random() * (100 + 1) ) <= 5)
            return finalDamage;
        
        finalDamage = (int) (Math.random() * damageRange) + MINDMG;
        
        if((Math.random() * (100 + 1)) <= 5)
            finalDamage *= 2;
        
        return finalDamage;
    }
    
    /**
     * Modifies the HP depending on value.
     * Accepts both positive and negative numbers.
     * @param value - The value to modify the HP.
     */
    public void setHP(int value)
    {
        if(value <= (-1) * getHP())
            this.hp = 0;
        
        if(value >= MAXHP)
            this.hp = MAXHP;
        
        this.hp += value;
    }
    
    /**
     * Attempts to stun the monster. It may fail.
     * @return 'true' if the monster was successfully stunned.
     * 'false' if the monster was already stunned.
     */
    public boolean stun()
    {
        if(isStunned())
            return false;
        
        manageStunState();
        return true;
    }
    
    
    /**
     *Internal class stun manager to toggle and set stun & stun duration.
     */
    private void manageStunState()
    {
        if(!isStunned())
        {
            this.stunned = true;
            this.stunDuration = 3;
        }
        else
        {
            this.stunDuration--;
            
            if(this.stunDuration <= 0)
            {
                this.stunned = false;
                this.stunDuration = 0;
            }
        }
    }

    @Override
    public String toString() { return "Monster\nHP: " + getHP(); }
}