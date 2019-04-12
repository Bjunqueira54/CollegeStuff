package gameLogic.Crew;

import java.util.Scanner;

public class CrewMembers 
{
    int takenOptions[];
    int count = 0;
    
    public CrewMembers()
    {
        takenOptions = new int[2];
        //pickCrewMember();        
    }
    
    //ATENÇÂO: Apaguei uma função que tinhas aqui porque involvia ir buscar input
    //do jogador com um scanner. Isso está 100% extremamente errado.
    //Scanners e input gathering fazem-se nas classes do interface (texto ou gráfico)
    //e só depois é que chamamos as funções das classes relativas ao jogo.
    //Nunca ir buscar inputs diretamente as classes de lógica
    
    /*public int pickCrewMember()
    {
        //mostrar todas as hipoteses
        //cada uma com um numero (1 a 12)
        addCrewMember(opt);
        switch(opt)
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
            default: return 0;
        }
    }*/
    
    private boolean verifyOption(int opt)
    {
        if(opt >= 1 && opt <= 12) 
        {
            for (int i=0; i < takenOptions.length; i++)
                if (takenOptions[i] == opt)
                    return false;
            return true;
        }
        return false;
    }
    
    //public static int setActionPoints() {return 0;} 

    private void addCrewMember(int taken) {takenOptions[count++] = taken;}
}