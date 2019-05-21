package GameLogic.States;

import GameLogic.Exceptions.*;

public interface gState
{
    public gState ChooseCrewMember(String name) throws InvalidCrewMemberException, CrewMemberAlreadySelectedException;
    public gState ChooseRound(String round) throws InvalidRoundException;
}