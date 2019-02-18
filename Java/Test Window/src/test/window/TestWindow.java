package test.window;

import java.awt.Color;
import java.awt.EventQueue;
import javax.swing.JFrame;

public class TestWindow
{
    
    
    public static void main(String[] args)
    {
	JFrame frame = new JFrame("Test");
    
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(800, 600);
	frame.getContentPane().setBackground(Color.BLACK);
	frame.setVisible(true);
    }
    
}
