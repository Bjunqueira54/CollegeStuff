package gameLogic.States;

public class StateAdapter implements gStates
{
    @Override
    public gStates quit() { return this; }
}