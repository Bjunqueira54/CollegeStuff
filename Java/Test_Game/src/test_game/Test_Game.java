package test_game;

import java.awt.Color;
import java.awt.Component;
import javax.swing.JPanel;
import java.awt.EventQueue;
import javax.swing.JFrame;

public class Test_Game
{
    JFrame frame;
    
    public Test_Game()
    {
	frame = new JFrame();
	
	frame.setLocationRelativeTo(null);
	frame.setBackground(Color.BLACK);
	frame.setVisible(true);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(800, 600);
    }
    
    private void addPanel()
    {
	JPanel panel = new JPanel();
	frame.add(panel);
	
	panel.setVisible(true);
	panel.setBackground(Color.BLACK);
    }
    
    private Component getPanelHandle()
    {
	return frame.getComponent(0);
    }
    
    private void drawPixel()
    {
	
    }
    
    public static void main(String[] args)
    {
	Test_Game game = new Test_Game();
	game.addPanel();
	
	game.drawPixel();
	
	int i = 0;
	
	Color carray[] = {Color.BLACK, Color.BLUE, 
	    Color.CYAN, Color.GREEN,
	    Color.RED, Color.ORANGE,
	    Color.YELLOW, Color.PINK,
	    Color.WHITE, Color.MAGENTA};
	
	while(true)
	{
	    game.frame.setBackground(carray[i/100]);
	    i++;
	    if(i >= 1000)
		i = 0;
	}
    }
}