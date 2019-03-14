package MonsterSlayer;

public final class GameStrings
{
    static private final String welcome_screen = "Welcome to Monster Slayer";
    static private final String name_select = "What's your name: ";
    static private final String game_start = "Good luck and have fun %s";
    
    static private final String first_round_heal = "You cannot heal on the first round";
    static private final String hero_defeat = "%s has been killed by the monster";
    static private final String defeat1 = "You lost";
    static private final String defeat2 = "Git Gud";
    
    static private final String hero_victory = "%s has defeated the monster";
    static private final String victory1 = "You win";
    static private final String victory2 = "Congratulations";
    
    static private final String hero_damage = "%s deals %i damage";
    static private final String hero_block = "%s blocks %i damage";
    static private final String hero_heal = "%s heals himself for %i health points";
    static private final String hero_crit = "%s gets a critical strike, dealing %i damage";
    static private final String hero_stun = "The monster is now stunned";
    static private final String hero_special = "%s does a special attack, dealing &i damage and healing himself for %i health points";
    
    static private final String monster_damage = "The monster deals %i damage";
    static private final String monster_stun_rounds = "The monster is stunned for %i more rounds";
    static private final String monster_stun_round = "The monster is stunned for 1 more round";
    
    private GameStrings()
    {
	throw new UnsupportedOperationException();
    }
    
    static public final String WelcomeScreen() { return welcome_screen; }
    static public final String NameSelection() { return name_select; }
    static public final String GameStart() { return game_start; }
    
    static public final String getFirstRoundHealError() { return first_round_heal; }
    static public final String getHeroDefeat() { return hero_defeat; }
    static public final String getDefeatScreen() { return defeat1 + '\n' + defeat2; }
    
    static public final String getHeroVictory() { return hero_victory; }
    static public final String getVictoryScreen() { return victory1 + '\n' + victory2; }
    
    static public final String getHeroDamage() { return hero_damage; }
    static public final String getHeroBlock() { return hero_block; }
    static public final String getHeroHeal() { return hero_heal; }
    static public final String getHeroCrit() { return hero_crit; }
    static public final String getHeroStun() { return hero_stun; }
    static public final String getHeroSpecial() { return hero_special; }
    
    static public final String getMonsterDamage() { return monster_damage; }
    static public final String getMonsterStunRounds(int i)
    {
	if(i == 1)
	    return monster_stun_round;
	else
	    return monster_stun_rounds;
    }
    
}
