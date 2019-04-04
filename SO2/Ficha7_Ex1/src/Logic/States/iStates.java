package Logic.States;

public interface iStates
{
    public iStates start();
    public iStates finish();
    public iStates bet(int nBalls);
    public iStates RemoveOneFromSack();
    public iStates RemoveTwoRandom();
}