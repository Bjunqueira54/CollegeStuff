package Logic;

import Logic.Balls.*;
import Logic.Exceptions.EmptyBagException;
import Logic.Exceptions.IllegalBetValueException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class GameData
{
    static int NBALLS = 10;
    
    List<Ball> bag;
    List<WhiteBall> collectedBalls;
    
    List<WhiteBall> removedWhite;
    List<BlackBall> removedBlack;
    
    int nBettedBalls;
    
    public GameData()
    {
        bag = new ArrayList<>();
        collectedBalls = new ArrayList<>();
        removedWhite = new ArrayList<>();
        removedBlack = new ArrayList<>();
        
        
        for (int i = 0; i < NBALLS; i++)
        {
            bag.add(new WhiteBall(this));
            bag.add(new BlackBall(this));
        }
        
        Collections.shuffle(bag);
    }
    
    public Ball getRandomBall() throws EmptyBagException
    {
        if(isBagEmpty()) throw new EmptyBagException();
        
        int r = (int) (Math.random() * bag.size());
        
        return bag.remove(r);
    }
    
    public boolean isBagEmpty()
    {
        return bag.isEmpty();
    }
    
    public int getNBettedBalls()
    {
        return nBettedBalls;
    }
    
    public void setNBettedBalls(int nBet) throws IllegalBetValueException
    {
        if(collectedBalls.size() < nBet)
            throw new IllegalBetValueException();
    }
    
    public void addWhiteBalltoCollection(WhiteBall wBall)
    {
        collectedBalls.add(wBall);
    }
}