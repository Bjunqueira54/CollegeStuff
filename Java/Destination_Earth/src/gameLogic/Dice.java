package gameLogic;

public class Dice
{
    public static int diceRoller(int n)
    {
        int total=0;
        for (int i=0; i<n; i++)
            total += (int) ((Math.random() * 5) + 1);
        return total;
    }
}