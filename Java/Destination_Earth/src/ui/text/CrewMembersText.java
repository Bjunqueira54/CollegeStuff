package ui.text;

public class CrewMembersText
{
    static int CREW_MEMBER_PAGE_1 = 10;
    static int CREW_MEMBER_PAGE_2 = 4;
    
    String[] crew_names_page1 = {
        "Captain",
        "Commander",
        "Commns Officer",
        "Doctor",
        "Engineer",
        "Moral Officer",
        "Navigation Officer",
        "Red Shirt",
        "Science Officer"
    };
    
    String[] crew_names_page2 = {
        "Security Officer",
        "Shuttle Pilot",
        "Transporter Chief",
    };
    
    public CrewMembersText() {}
    
    public void CrewOptions(int page)
    {
        System.out.println("Possible Options (Page " + page + "/2):");
        
        if(page == 1)
        {
            for (int i=1; i < CREW_MEMBER_PAGE_1; i++)
                System.out.println("" + i + " - " + crew_names_page1[i-1]);
            System.out.println("0 - Next...");
        }
        else if(page == 2)
        {
            for (int i=1; i < CREW_MEMBER_PAGE_2; i++)
                System.out.println("" + i + " - " + crew_names_page2[i-1]);  
            System.out.println("0 - Previous...");
        }
    }
}