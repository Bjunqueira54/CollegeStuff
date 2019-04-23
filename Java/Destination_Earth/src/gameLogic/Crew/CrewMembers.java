package gameLogic.Crew;

import gameLogic.Player;
import ui.text.CrewMembersText;

public class CrewMembers 
{
    Player p;
    CrewMembersText out;
    int DEFAULT_OPTION = 0;
    int takenOption;
    int option;
     int c = 0; 
    
    public CrewMembers()
    {
        out = new CrewMembersText();
        this.takenOption = DEFAULT_OPTION;
        selectCrewMember();
        //recruitCrewMember();
    }
    
    public CrewMembers(int taken)
    {
        out = new CrewMembersText();
        this.takenOption = taken;
        selectCrewMember();
        //recruitCrewMember();
    }
    
    public void selectCrewMember()
    {
        do {
            out.showCrewOptions(takenOption);
            option = out.pickCrewMember();
        } while(!verifyOption(option));
    }
    
    private boolean verifyOption(int opt)
    {
        if(opt >= 1 && opt <= 12) 
        {
            if(opt == takenOption)
                return false;
            else
                return true;
        }
        return false;
    }
    
    public boolean recruitCrewMember()
    {
        switch(option) //here
        {
            case 1: 
            case 2: 
            case 3: 
            case 4: 
            case 5: 
            case 6: 
            case 7: 
            case 8: 
            case 9: 
            case 10: 
            case 11: 
            case 12:
            default: return false;
        }
    }
    
    public int getOption() {return option;}
}