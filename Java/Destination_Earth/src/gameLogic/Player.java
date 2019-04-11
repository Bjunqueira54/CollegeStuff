package gameLogic;

import gameLogic.Crew.CrewMembers;

public class Player
{
    static int MAX_POINTS = 12; //o maximo é sempre 12
    int ACTION_POINTS = 5; //pode ser alterado
    int HP;
    int IP;
    int Current_AP;
    
    CrewMembers PCs[];

    public Player(int HP, int IP)
    {
        PCs = new CrewMembers[2];
        
        this.HP = HP;
        this.IP = IP;
        //this.Current_AP = setActionPoints();
    }
    
    public void setHP(int HP) {this.HP = HP;}

    public void setIP(int IP) {this.IP = IP;}
    
    public int getCurrentAP() {return Current_AP;}
    
    public int getHP() {return HP;}

    public int getIP() {return IP;}
}