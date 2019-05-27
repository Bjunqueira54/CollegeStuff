package GameLogic.States;

import GameLogic.Exceptions.*;
import GameLogic.GameData;

public class gStateAdapter implements gState
{
    public gStateAdapter()
    {}

    @Override
    public gState clearCrew() { return this; }
    
    @Override
    public gState StartGame() { return this; }

    @Override 
    public gState AwaitPlayerChoice(String name) { return this; }
    
    @Override
    public gState AwaitRestingPlayerChoice(String name) { return this; }
    
    @Override
    public gState ChooseCrewMember(String name) throws InvalidCrewMemberException, CrewMemberAlreadySelectedException
    { return this; }

    @Override
    public gState ChooseRound(String round) throws InvalidRoundException
    { return this; }

    @Override
    public gState setDefaultAdventure() { return this; }

    @Override
    public gState clearAdventure() { return this; }
}