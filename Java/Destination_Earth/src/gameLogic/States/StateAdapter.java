package gameLogic.States;

import gameLogic.Crew.CrewMembers;
import gameLogic.Exceptions.*;
import gameLogic.GameData;
import gameLogic.Tokens.Token;

public class StateAdapter implements States
{
    private GameData gamedata;
    
    public StateAdapter(GameData g)
    {
        this.gamedata = g;
    }
    
    public GameData getGameData() { return gamedata; }

    @Override
    public States ChooseAdventure(String round) { return this; }

    @Override
    public States ChooseDefaultAdventure() { return this; }

    @Override
    public States ChooseCrew(CrewMembers cm) throws CrewMemberAlreadyPresentException { return this; }

    @Override
    public States startgame() { return this; }

    @Override
    public States PlaceOrganicDetonator(CrewMembers cm) throws NoOrganicDetonatorsException { return this; }

    @Override
    public States PlaceParticleDispenser(CrewMembers cm) throws NoParticleDispensersException { return this; }

    @Override
    public States SealRool(int room) throws NoSealRoomTokensExceptions, RoomAlreadySealedException { return this; }
    
    @Override
    public States ActivateTrap(int room) { return this; }
    
    @Override
    public States Attack(CrewMembers cm, int room) throws InvalidRoomException, NoAliensToAttackException { return this; }

    @Override
    public States Move(CrewMembers cm, int room) throws InvalidRoomException { return this; }

    @Override
    public States Heal() { return this; }

    @Override
    public States Repair() { return this; }
    
    @Override
    public States UpgradeMovement(CrewMembers cm) { return this; }

    @Override
    public States UpgradeAttack(CrewMembers cm) { return this; }

    @Override
    public States AddSingleDamageToAttack(CrewMembers cm) { return this; }

    @Override
    public States AddHealth() { return this; }

    @Override
    public States RepairHull() { return this; }

    @Override
    public States BuildOrganicDetonator() { return this; }

    @Override
    public States BuildParticleDispenser() { return this; }

    @Override
    public States BuildSealedRoomToken() { return this; }

    @Override
    public States quitgame() { return this; }
}