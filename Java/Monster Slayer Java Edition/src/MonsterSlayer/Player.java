package MonsterSlayer;

import java.lang.Math;

public class Player
{
    String name;
    
    int Health;
    int BaseDamage;
    int Block;
    int Heal;
    
    int CritChance;
    int MissChance;
    
    boolean asHealed;
    boolean isBlocking;
    
    public Player(String PlayerName)
    {
	name = PlayerName;
	BaseDamage = 30;
	CritChance = 5;
	MissChance = 5;
    }
    
    public int getHP() { return Health; }
    
    private boolean CritRoll()
    {
	return (Math.random() * (100 - 1) <= 5);
    }
    
    private boolean MissRoll()
    {
	return (Math.random() * (100 - 1) <= 5);
    }
    
    public int NormalAttack()
    {
	return 0;
    }
    
}
