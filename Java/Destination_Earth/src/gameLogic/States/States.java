package gameLogic.States;

import gameLogic.Crew.CrewMembers;
import gameLogic.Tokens.Token;

public interface States
{
    //Main Menu Functions
    public States ChooseAdventure(String round);
    public States ChooseDefaultAdventure();
    public States ChooseCrew(CrewMembers cm);
    public States startgame();
    
    //In-Game Round Functions
    public States PlaceToken(Token token, int room);
    public States Attack();
    
    //In-Game Resting Functions
    public States UpgradeMovement(CrewMembers cm);
    public States UpgradeAttack(CrewMembers cm);
    public States AddSingleDamageToAttack(CrewMembers cm);
    public States AddHealth();
    public States RepairHull();
    public States BuildOrganicDetonator();
    public States BuildParticleDispenser();
    public States BuildSealedRoomToken();
    
    public States quitgame();
}