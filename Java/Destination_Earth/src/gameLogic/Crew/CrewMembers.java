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
        //cada uma com um numero
        int opt = readOption();
        addCrewMember(opt);
        switch(opt)
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