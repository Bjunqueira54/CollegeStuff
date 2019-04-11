package gameLogic.Crew;

import java.util.Scanner;

public class CrewMembers 
{
    Scanner s = new Scanner(System.in);
    int takenOptions[];
    int count = 0;
    
    public CrewMembers()
    {
        takenOptions = new int[2];
        pickCrewMember();        
    }

    public int pickCrewMember()
    {
        //mostrar todas as hipoteses
        //cada uma com um numero (1 a 12)
        int opt = readOption();
        addCrewMember(opt);
        switch(opt)
        {
            case 1: //doctor
            case 2: //comm's officer
            case 3: //red shirt
            case 4: //science officer
            case 5: //engineer
            case 6: //captain
            case 7: //commander
            case 8: //transporter chief
            case 9: //moral officer
            case 10: //security officer
            case 11: //navigation officer
            case 12: //shuttle pilot
            default: return 0;
        }
    }
    
    
    private int readOption()
    {
        int opt = 0;
        do
        {
            opt = s.nextInt();
        } while(verifyOption(opt));
        return opt;
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
    
    //public static int setActionPoints() {return 0;} 

    private void addCrewMember(int taken) {takenOptions[count++] = taken;}
}