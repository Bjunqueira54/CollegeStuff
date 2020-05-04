package ficha2;

import ficha2.Ex1.*;

public class Main
{
    public static void main(String[] args)
    {
        runEx1();
    }

    private static void runEx1()
    {
        GameLogic game = new GameLogic();
        ficha2.Ex1.Interface ex1 = new Interface(game);

        ex1.run();
    }
}
