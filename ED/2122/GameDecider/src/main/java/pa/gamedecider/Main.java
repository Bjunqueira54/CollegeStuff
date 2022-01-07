package pa.gamedecider;

import java.util.Random;

public class Main
{
    public static void main(String[] args) {
        int dice = diceRoll();
        boolean coin = coinFlip();
        
        if(coin)
        {
            if(dice >= 1 && dice <= 3)
                System.out.println("Play 2v2 Ranked");
            else
                System.out.println("Play Short comp Ranked");
        }
        else
        {
            if(dice >= 4 && dice <= 6)
                System.out.println("Play 2v2 Unranked");
            else
                System.out.println("Play Short comp Unranked");
        }
    }
    
    public static int diceRoll() {
        Random r = new Random();
        return r.nextInt(6) + 1;
    }
    
    //False = heads; True = tails
    public static boolean coinFlip() {
        Random r = new Random();
        int res = r.nextInt(2);
        
        return res == 0;
    }
}