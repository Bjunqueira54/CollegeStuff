package ficha2.Ex1;

public class GameLogic
{
    private final String[] wordpool = { "Testing", "Football", "Gaming", "Playing", "Music",
                                        "Computer", "Coding", "Laptop", "Technology", "Education",
                                        "Dictionary", "Keyboard", "Mouse", "Graphics", "Processor",
                                        "Memory", "Input", "Output", "Interface", "Tower",
                                        "Blackboard", "Whiteboard", "Motherboard", "Kernel", "Projector"};
    private int word;
    private int lives;
    private StringBuffer strb;
    private char[] usedLetters;
    private String PlayerName;
    private int PlayerScore;
    
    public GameLogic()
    {
        this("Player");
    }
    
    public GameLogic(String name)
    {
        this.PlayerName = name;
    }
    
    private void setGame()
    {
        PlayerScore += (lives > 0) ? lives : 0;
        word = (int) (Math.random() * 10) + 1;
        strb = new StringBuffer(wordpool[word]);
        removeLetters();
        lives = 5;
        usedLetters = new char[26];
    }
    
    public void setPlayerName(String n) { this.PlayerName = n; }
    
    public String getGameWord() { return strb.toString(); }
    public int getLives() { return lives; }
    public boolean isGameOver() { return (lives <= 0) || checkVictory(); }
    public final String getPlayerName() { return PlayerName; }
    public final int getPlayerScore() { return PlayerScore; }
    
    public final String getUsedLetters()
    {
        StringBuffer temp = new StringBuffer();
        
        for(int i = 0; i < usedLetters.length; i++)
            temp.append(usedLetters[i]);
        
        return temp.toString();
    }
    
    public void newGame()
    {
        setGame();
    }
    
    private void removeLetters()
    {
        for(int i = 0; i < strb.length(); i++)
            strb.setCharAt(i, '*');
    }
    
    /*
    Return the index of the character if it exists.
    Else it returns -1
    */
    public void checkInput(String input)
    {
        if(!isGameOver())
        {
            if(input.length() > 1)
                if(wordpool[word].compareToIgnoreCase(input) == 0)
                    strb = new StringBuffer(input);
                else
                    lives = 0;
            else
                checkLetter(input.charAt(0));
            
        }
    }
    
    private void checkLetter(char c)
    {
        if(charAlreadyUsed(c))
            return;

        int index = checkLetterPrivate(c, 0);

        if(index >= 0)
        {
            do
            {
                strb.setCharAt(index, c);
                index = checkLetterPrivate(c, index + 1);
            }
            while(index != -1);
        }
        else
            lives--;
        
        addToUsedLetters(c);
    }
    
    private int checkLetterPrivate(char c, int i)
    {
        for(; i < wordpool[word].length(); i++)
            if(Character.compare(Character.toLowerCase(c), Character.toLowerCase(wordpool[word].charAt(i))) == 0)
                return i;

        return -1;
    }
    
    private boolean charAlreadyUsed(char c)
    {
        for(int i = 0; i < usedLetters.length; i++)
            if(Character.compare(Character.toLowerCase(c), Character.toLowerCase(usedLetters[i])) == 0)
                return true;
        return false;
    }
    
    private boolean checkVictory()
    {
        for(int i = 0; i < strb.length(); i++)
            if(strb.charAt(i) == '*')
                return false;
        return true;
    }
    
    private void addToUsedLetters(char c)
    {
        for(int i = 0; i < usedLetters.length; i++)
            if(usedLetters[i] == '\0')
            {
                usedLetters[i] = c;
                return;
            }
    }
}