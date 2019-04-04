package Logic.States;

import Logic.Balls.Ball;
import Logic.Exceptions.EmptyBagException;
import Logic.Exceptions.IllegalBetValueException;
import Logic.GameData;

public class AwaitBet extends StateAdapter
{

    public AwaitBet(GameData gamedata)
    {
        super(gamedata);
    }

    @Override
    public iStates bet(int nBalls)
    {
        Ball randomBall;
        
        try
        {
            getGameData().setNBettedBalls(nBalls);
            randomBall = getGameData().getRandomBall();
        }
        catch(IllegalBetValueException ex)
        {
            return this;
        }
        catch(EmptyBagException ex)
        {
            return new GameOver(getGameData());
        }
    }
}