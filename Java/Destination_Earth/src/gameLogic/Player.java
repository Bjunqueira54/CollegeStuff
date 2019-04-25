package gameLogic;

import gameLogic.Crew.Captain;
import gameLogic.Crew.Commander;
import gameLogic.Crew.CommsOfficer;
import gameLogic.Crew.CrewMembers;
import gameLogic.Crew.Doctor;
import gameLogic.Crew.Engineer;
import gameLogic.Crew.MoralOfficer;
import gameLogic.Crew.NavigationOfficer;
import gameLogic.Crew.RedShirt;
import gameLogic.Crew.ScienceOfficer;
import gameLogic.Crew.SecurityOfficer;
import gameLogic.Crew.ShuttlePilot;
import gameLogic.Crew.TransporterChief;
import ui.text.CrewMembersText;

public class Player
{
    static int DEFAULT_HP = 8;
    static int DEFAULT_IP = 0;
    static int AP = 5; 
    int HP;
    int IP;
    int Current_AP;
    
    CrewMembers PCs[];
    CrewMembersText cout;
    int takenOption[] = {0,0};
    int count = 0;
    
    public Player()
    {
        PCs = new CrewMembers[2];
        cout = new CrewMembersText();
        pickMyCrew();
        assembleMyCrew();
        
        this.HP = DEFAULT_HP;
        this.IP = DEFAULT_IP;
        this.Current_AP = AP;
    }
    
    public void pickMyCrew()
    {
        int option;
        do {
            cout.showCrewOptions(takenOption);
            option = cout.pickCrewMember();
            takenOption[count++] = option;
        } while(!verifyOption(option) || count != 2);
    }
    
    private boolean verifyOption(int opt)
    {
        if(opt >= 1 && opt <= 12)
            for (int i=0; i < takenOption.length; i++)
                if(opt == takenOption[i])
                    return false;
                else
                    return true;
        return false;
    }
    
    public void assembleMyCrew()
    {
        for (int i=0; i < PCs.length; i++)
            switch(takenOption[i])
            {
                case 1: PCs[i] = new Captain();
                        break;
                case 2: PCs[i] = new Commander();
                        break;
                case 3: PCs[i] = new CommsOfficer();
                        break;
                case 4: PCs[i] = new Doctor();
                        break;
                case 5: PCs[i] = new Engineer();
                        break;
                case 6: PCs[i] = new MoralOfficer();
                        break;
                case 7: PCs[i] = new NavigationOfficer();
                        break;
                case 8: PCs[i] = new RedShirt();
                        break;
                case 9: PCs[i] = new ScienceOfficer();
                        break;
                case 10: PCs[i] = new SecurityOfficer();
                         break;
                case 11: PCs[i] = new ShuttlePilot();
                         break;
                case 12: PCs[i] = new TransporterChief();
                         break;
            }
    }
    
    public static void setAP(int change) {AP += change;}
    
    public void setHP(int HP) {this.HP = HP;}

    public void setIP(int IP) {this.IP = IP;}
    
    public int getCurrentAP() {return Current_AP;}
    
    public int getHP() {return HP;}

    public int getIP() {return IP;}
}