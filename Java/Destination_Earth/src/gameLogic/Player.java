package gameLogic;

import gameLogic.Crew.CrewMembers;

public class Player
{
    int ACTION_POINTS = 5; //pode ser alterado
    int DEFAULT_HP = 8;
    int DEFAULT_IP = 0;
    int HP;
    int IP;
    int Current_AP;
    
    CrewMembers PCs[];

    public Player()
    {
        PCs = new CrewMembers[2];
        
        this.HP = DEFAULT_HP;
        this.IP = DEFAULT_IP;
        //this.Current_AP = setActionPoints();
    }
    
    //incremetar o AP nao substituilo
    public void setAP(int AP) {this.ACTION_POINTS += AP;}
    
    public void setHP(int HP) {this.HP = HP;}

    public void setIP(int IP) {this.IP = IP;}
    
    public int getCurrentAP() {return Current_AP;}
    
    public int getHP() {return HP;}

    public int getIP() {return IP;}
}