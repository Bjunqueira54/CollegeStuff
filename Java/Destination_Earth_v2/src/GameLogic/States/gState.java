package GameLogic.States;

import GameLogic.Exceptions.*;

public interface gState
{
    public gState AwaitsPlayerChoice(String name);
    public gState ChooseCrewMember(String name) throws InvalidCrewMemberException, CrewMemberAlreadySelectedException;
    public gState ChooseRound(String round) throws InvalidRoundException;
    public gState setDefaultAdventure();
    public gState clearAdventure();
}