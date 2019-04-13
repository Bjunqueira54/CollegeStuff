package gameLogic;

public class GameBoard 
{
    String rooms[] = {
        "Room Name",
        "Bridge",
        "Sick Bay",
        "Bric",
        "Crew Quarters",
        "Conference Room",
        "Shuttle Bay",
        "Weapons Bay",
        "Mess Hall",
        "Engineering",
        "Astrometrics",
        "Holodeck",
        "Hydroponics",
    };
    int doors[][];
    
    public String getRoom(int index) {return rooms[index];}
}
