package gameLogic.States;

import gameLogic.Crew.*;
import gameLogic.Exceptions.*;
import gameLogic.GameData;

public class ChooseCrewState extends StateAdapter
{

    public ChooseCrewState(GameData g)
    {
        super(g);
        gamedata.ClearCrew();
    }

    @Override
    public States ChooseCrew(CrewMembers cm)
    {
        try
        {
            getGameData().AddCrewMember(cm);
        }
        catch(CrewMemberAlreadyPresentException ex)
        {
            try
            {
                throw new CrewMemberAlreadyPresentException();
            }
            catch (CrewMemberAlreadyPresentException ex1) {}
        }
        
        if(gamedata.CompleteCrew())
            return new MainMenu(gamedata);
        else
            return this;
    }
}