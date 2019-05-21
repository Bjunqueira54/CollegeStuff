package GameLogic.States;

import GameLogic.GameData;
import GameLogic.CrewMembers.*;
import GameLogic.Exceptions.CrewMemberAlreadySelectedException;
import GameLogic.Exceptions.InvalidCrewMemberException;

public class ChooseCrew extends gStateAdapter
{
    private GameData data;
    
    public ChooseCrew(GameData data)
    {
        this.data = data;
    }

    @Override
    public String toString()
    {
        return "ChooseCrew";
    }

    /*
    Adds a new crew member.
    Accepted names (not case sensitive):
    Captain
    Commander
    CommsOfficer
    Doctor
    Engineer
    MoralOfficer
    NavigationOfficer
    RedShirt
    ScienceOfficer
    SecurityOfficer
    ShuttlePilot
    TransporterChief
    */
    @Override
    public gState ChooseCrewMember(String name) throws InvalidCrewMemberException, CrewMemberAlreadySelectedException
    {
        if(name.equalsIgnoreCase("Captain"))
            data.addCrewMember(new Captain());
        else if(name.equalsIgnoreCase("Commander"))
            data.addCrewMember(new Commander());
        else if(name.equalsIgnoreCase("CommsOfficer"))
            data.addCrewMember(new CommsOfficer());
        else if(name.equalsIgnoreCase("Doctor"))
            data.addCrewMember(new Doctor());
        else if(name.equalsIgnoreCase("Engineer"))
            data.addCrewMember(new Engineer());
        else if(name.equalsIgnoreCase("MoralOfficer"))
            data.addCrewMember(new MoralOfficer());
        else if(name.equalsIgnoreCase("NavigationOfficer"))
            data.addCrewMember(new NavigationOfficer());
        else if(name.equalsIgnoreCase("RedShirt"))
            data.addCrewMember(new RedShirt());
        else if(name.equalsIgnoreCase("ScienceOfficer"))
            data.addCrewMember(new ScienceOfficer());
        else if(name.equalsIgnoreCase("SecurityOfficer"))
            data.addCrewMember(new SecurityOfficer());
        else if(name.equalsIgnoreCase("ShuttlePilot"))
            data.addCrewMember(new ShuttlePilot());
        else if(name.equalsIgnoreCase("TransporterChief"))
            data.addCrewMember(new TransporterChief());
        else
            throw new InvalidCrewMemberException();
        
        if(data.isCrewComplete())
            return new MainMenu(data);
        else
            return this;
    }
}