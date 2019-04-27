package gameLogic.States;

import gameLogic.Crew.*;
import gameLogic.Exceptions.*;
import gameLogic.GameData;

public class ChooseCrewState extends StateAdapter
{

    public ChooseCrewState(GameData g)
    {
        super(g);
        getGameData().ClearCrew();
    }

    @Override
    public States ChooseCrew(CrewMembers cm) throws CrewMemberAlreadyPresentException
    {
        try
        {
            getGameData().AddCrewMember(cm);
        }
        catch(CrewMemberAlreadyPresentException ex)
        {
            throw new CrewMemberAlreadyPresentException();
        }
        
        if(getGameData().CompleteCrew())
            return new MainMenu(getGameData());
        else
            return this;
    }
}