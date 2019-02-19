package testwindowdrawing;

import java.awt.image.BufferedImage;
import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class TestWindowDrawing
{
    private BufferedImage draw;
    
    public TestWindowDrawing()
    {
	draw = new BufferedImage(800, 600, BufferedImage.TYPE_INT_ARGB);
	
	for(int x=0; x<draw.getWidth(); x++)
	    for(int y=0; y<draw.getHeight(); y++)
		draw.setRGB(x, y, 0);
    }
    
    public static void main(String[] args)
    {
	JFrame win = new JFrame("Test Window Drawing");
	
	TestWindowDrawing panel = new TestWindowDrawing();

	win.setBackground(Color.BLACK);
	win.pack();
	win.setVisible(true);
	win.setResizable(false);
	win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
