package GameLogic.States;

import GameLogic.Exceptions.*;
import GameLogic.GameData;

public class gStateAdapter implements gState
{
    public gStateAdapter()
    {
        
    }

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