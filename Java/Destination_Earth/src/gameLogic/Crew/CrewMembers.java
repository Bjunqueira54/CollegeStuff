package gameLogic.Crew;

import gameLogic.Player;
import ui.text.CrewMembersText;

public class CrewMembers 
{
    Player p;
    CrewMembersText out;
    int takenOptions[];
    int count = 0;
    
    public CrewMembers()
    {
        out = new CrewMembersText();
        takenOptions = new int[2];
        selectCrewMembers();
    }
    
    public void selectCrewMembers()
    {
        do {
            out.showCrewOptions();
            int opt = out.pickCrewMember();
            if(verifyOption(opt)) 
                addCrewMember(opt);
        } while(count != 2);
    }
    
    private boolean verifyOption(int opt)
    {
        if(opt >= 1 && opt <= 12) 
        {
            for (int i=0; i < takenOptions.length; i++)
                if (takenOptions[i] == opt)
                    return false;
            return true;
        }
        return false;
    }

    private void addCrewMember(int taken) {takenOptions[count++] = taken;}
    
    public int[] getMyCrew() {return takenOptions;}
}