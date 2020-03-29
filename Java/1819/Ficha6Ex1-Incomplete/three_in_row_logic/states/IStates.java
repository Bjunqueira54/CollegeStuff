package three_in_row_logic.states;

/*
 * List of expected events when taking into account all the states.
 */
public interface IStates
{
   IStates setNumberPlayers(int num);
   IStates setName(int num, String name);
   IStates startGame();
   IStates placeToken(int line, int column);
   IStates returnToken(int line, int column);
   IStates quit();
}
