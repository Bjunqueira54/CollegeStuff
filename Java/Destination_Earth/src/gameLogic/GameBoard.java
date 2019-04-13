package gameLogic;

import java.util.ArrayList;

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
    ArrayList<Integer> doors[];
    
    public String getRoom(int index) {return rooms[index];}
    public ArrayList<Integer> getRoomDoors(int room) {return doors[room];}
}
