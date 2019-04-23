package gameLogic;

import gameLogic.Crew.CrewMembers;

public class Player
{
    static int DEFAULT_HP = 8;
    static int DEFAULT_IP = 0;
    int ACTION_POINTS = 5; //pode ser alterado
    int HP;
    int IP;
    int Current_AP;
    
    CrewMembers PCs[];

    public Player()
    {
        PCs = new CrewMembers[2];
        pickMyCrew();
        
        this.HP = DEFAULT_HP;
        this.IP = DEFAULT_IP;
        this.Current_AP = ACTION_POINTS;
    }
    
    public void pickMyCrew()
    {
        PCs[0] = new CrewMembers();
        PCs[1] = new CrewMembers(PCs[0].getOption());
    }
    
    //incremetar o AP nao substituilo
    public void setAP(int AP) {this.ACTION_POINTS += AP;}
    
    public void setHP(int HP) {this.HP = HP;}

    public void setIP(int IP) {this.IP = IP;}
    
    public int getCurrentAP() {return Current_AP;}
    
    public int getHP() {return HP;}

    public int getIP() {return IP;}
}