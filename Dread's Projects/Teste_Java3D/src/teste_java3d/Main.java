package teste_java3d;

import java.awt.*;
import java.awt.event.*;
import javax.swing.text.BadLocationException;
import javax.swing.text.Position;
import javax.swing.text.View;

public class Main extends Frame
{
    public static void main(String[] args)
    {
        new Main();
    }
    
    public Main()
    {
        super("Teste Java 3D");
        setSize(640, 480);
        
        Canvas myCanvas = new Canvas(null);
        add("Center", myCanvas);
        
        setVisible(true);
        
        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                dispose();
                System.exit(0);
            }
        });
    }
}