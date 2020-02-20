package Logic.Balls;

import Logic.GameData;

public class WhiteBall extends Ball
{

    public WhiteBall(GameData gamedata)
    {
        super(gamedata);
    }

    @Override
    public void removeAfterBet()
    {
        int nBettedBalls = getGameData().getNBettedBalls();
        getGameData().addWhiteBalltoCollection(this);
    }
}