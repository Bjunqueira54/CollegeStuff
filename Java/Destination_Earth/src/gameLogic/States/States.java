package gameLogic.States;

import gameLogic.Crew.CrewMembers;
import gameLogic.Exceptions.*;
import gameLogic.Tokens.Token;

public interface States
{
    //Main Menu Functions
    public States ChooseAdventure(String round);
    public States ChooseDefaultAdventure();
    public States ChooseCrew(CrewMembers cm) throws CrewMemberAlreadyPresentException;
    public States startgame();
    
    //In-Game Round Functions
    public States PlaceOrganicDetonator(CrewMembers cm) throws NoOrganicDetonatorsException;
    public States PlaceParticleDispenser(CrewMembers cm) throws NoParticleDispensersException;
    public States SealRool(int room) throws NoSealRoomTokensExceptions, RoomAlreadySealedException;
    public States ActivateTrap(int room);
    public States Attack(CrewMembers cm, int room) throws InvalidRoomException, NoAliensToAttackException;
    public States Move(CrewMembers cm, int room) throws InvalidRoomException;
    public States Heal();
    public States Repair();
    
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