package gameLogic.States;

public interface States
{
    public States setGame();
    public States ChooseCrew();
    public States start();
    public States quit();
    public States chooseAction();
}