package gameLogic.States;

import gameLogic.Crew.CrewMembers;
import gameLogic.Exceptions.CrewMemberAlreadyPresentException;
import gameLogic.GameData;
import gameLogic.Tokens.Token;

public class StateAdapter implements States
{
    GameData gamedata;
    
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
    public States ChooseCrew(CrewMembers cm) { return this; }

    @Override
    public States startgame() { return this; }

    @Override
    public States PlaceToken(Token token, int room) { return this; }

    @Override
    public States Attack() { return this; }

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