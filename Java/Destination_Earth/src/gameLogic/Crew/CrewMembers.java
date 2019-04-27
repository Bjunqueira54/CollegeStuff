package gameLogic.Crew;

public abstract class CrewMembers 
{
    int CurPos;
    int movement;
    int dice; //D6
    
    public CrewMembers()
    {
        CurPos = -1;
        movement = 1;
        dice = 1;
    }
    
    public int getMovement() { return movement; }
    public int getCurrentPosition() { return CurPos; }
    public int getDiceNumber() { return dice; }
    public int getDieRoll() { return (1 + (int) (Math.random() * (6 * dice) ) ); }
    
    public void upgradeMovement() { movement++; }
    public void upgradeDice() { dice += ((dice < 3) ? 1 : 0); }
    public void setNewPosition(int room) { CurPos = room; }
    
    @Override
    public abstract String toString();
}