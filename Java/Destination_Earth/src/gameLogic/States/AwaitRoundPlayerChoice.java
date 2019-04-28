package gameLogic.States;

import gameLogic.Crew.*;
import gameLogic.Exceptions.*;
import gameLogic.GameData;
import gameLogic.Tokens.*;

public class AwaitRoundPlayerChoice extends StateAdapter
{
    public AwaitRoundPlayerChoice(GameData gamedata) { super(gamedata); }
    
    @Override
    public States Attack(CrewMembers cm, int room) throws InvalidRoomException, NoAliensToAttackException
    {
        getGameData().CrewMemberAttack(cm, room);
        
        return CheckNextGameState();
    }

    @Override
    public States PlaceOrganicDetonator(CrewMembers cm) throws NoOrganicDetonatorsException
    {
        getGameData().PlaceOrganicDetonator(cm.getCurrentPosition());
        
        return CheckNextGameState();
    }

    @Override
    public States PlaceParticleDispenser(CrewMembers cm) throws NoParticleDispensersException
    {
        getGameData().PlaceParticleDispencers(cm.getCurrentPosition());
        
        return CheckNextGameState();
    }   

    @Override
    public States SealRool(int room) throws NoSealRoomTokensExceptions, RoomAlreadySealedException
    {
        getGameData().SealRoom(room);
        
        return CheckNextGameState();
    }
    
    @Override
    public States ActivateTrap(int room)
    {
        return CheckNextGameState();
    }
    
    private States CheckNextGameState()
    {
        if(getGameData().getAP() > 0)
            return this;
        else
        {
            getGameData().nextRound();
            
            if(getGameData().getRound(getGameData().getRoundNumber()).length() == 1)
                return new AwaitRestingPlayerChoice(getGameData());
            else
                return this;
        }
    }

    @Override
    public States quitgame()
    {
        return new MainMenu(new GameData());
    }
}