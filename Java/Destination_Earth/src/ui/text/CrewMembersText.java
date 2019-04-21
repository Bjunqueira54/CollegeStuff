package ui.text;

import java.util.Scanner;

public class CrewMembersText
{
    Scanner s = new Scanner(System.in);
    
    public CrewMembersText() {}
    
    public void showCrewOptions()
    {
        //mostrar as opções
    }
    
    public int pickCrewMember() {return s.nextInt();}
    
    /*public (int index)
    {
        switch(index)
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
        }
    }*/
}