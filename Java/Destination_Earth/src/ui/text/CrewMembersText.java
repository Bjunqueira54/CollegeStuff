package ui.text;

import java.util.Scanner;

public class CrewMembersText
{
    Scanner s = new Scanner(System.in);
    
    static int CREW_MEMBER_TYPES = 12;
    String[] crew_names = {
        "Captain",
        "Commander",
        "Commns Officer",
        "Doctor",
        "Engineer",
        "Moral Officer",
        "Navigation Officer",
        "Red Shirt",
        "Science Officer",
        "Security Officer",
        "Shuttle Pilot",
        "Transporter Chief"
    };
    
    public CrewMembersText() {}
    
    public void showCrewOptions(int[] taken)
    {
        crewOptions(taken);
        System.out.print("Escolha\n-> ");
    }
    
    public void crewOptions(int[] taken)
    {
        System.out.println("Opcoes Possiveis:");
        for (int i=1; i < CREW_MEMBER_TYPES; i++)
            if(i != taken[0] && i != taken[1])
                System.out.println("" + i + " - " + crew_names[i]);
    }
    
    public int pickCrewMember() {return s.nextInt();}
    
    public String getCrewMemeberName(int index) {return crew_names[index];}
}