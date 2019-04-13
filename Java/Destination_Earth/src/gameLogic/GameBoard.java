package gameLogic;

public class GameBoard 
{
    //todas as salas tem id-1
    String rooms[] = {
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
    //primeiro numero do array é o id-1 da sala 
    int doors[][] = {
        {0,4,7},    //0 - Bridge
        {1,6,7},    //1 - Sick Bay
        {2,4,8},    //2 - Bric
        {3,7,10},   //3 - Crew Quarters
        {4,0,2,7,9},//4 - Conference Room
        {5,1,9},    //5 - Shuttle Bay
        {6,1,10},   //6 - Weapons Bay
        {7,0,3,4,1},//7 - Mess Hall
        {8,2,11},   //8 - Engineering
        {9,4,5,11}, //9 - Astrometrics
        {10,3,6},   //10 - Holodeck
        {11,8,9}    //11 - Hydroponics
    };
            
    public GameBoard()
    {
        
    }
    
    public String getRoom(int index) {return rooms[index];}
    
    //public List<Integer> getRoomDoors(int room) {return doors[room];}
}
