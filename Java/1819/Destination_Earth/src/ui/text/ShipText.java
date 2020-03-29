package ui.text;

public class ShipText 
{
    String room_names[] = {
        "Bridge",           //0
        "Sick Bay",         //1
        "Bric",             //2
        "Crew Quarters",    //3
        "Conference Room",  //4
        "Shuttle Bay",      //5
        "Weapons Bay",      //6
        "Mess Hall",        //7
        "Engineering",      //8
        "Astrometrics",     //9
        "Holodeck",         //10
        "Hydroponics",      //11
    };

    //ui de texto usa o index real
    public String getRoom_names(int index) {return room_names[index-1];}
}