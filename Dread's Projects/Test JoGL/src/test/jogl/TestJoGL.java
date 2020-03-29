package test.jogl;

import com.jogamp.opengl.*;

public class TestJoGL
{
    public static void main (String args[])
    {
        try
        {
            System.loadLibrary("jogl");
            System.out.println("Hello World! (The native libraries are installed.)");
            GLCapabilities caps = new GLCapabilities(null);
            System.out.println("Hello JOGL! (The jar appears to be available.)");
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
    }
}