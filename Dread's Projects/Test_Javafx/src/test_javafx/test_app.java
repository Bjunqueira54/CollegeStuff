package test_javafx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class test_app extends Application
{
    @Override
    public void start(Stage primaryStage)
    {
        try
        {
        BorderPane root = new BorderPane();
        Scene scene = new Scene(root, 400, 400);
        scene.getStylesheets().add(getClass().getCanonicalName());
        primaryStage.setScene(scene);
        primaryStage.show();
        while(true) { }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    
    public static void main(String[] args)
    {
        launch(args);
    }
}