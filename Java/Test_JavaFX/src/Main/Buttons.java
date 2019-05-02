package Main;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Buttons extends Application
{
    @Override
    public void start(Stage PrimaryStage)
    {
        VBox root = new VBox();
        Button b1 = new Button("Hello");
        Button b2 = new Button("GoodBye");
        
        Label label = new Label("Hello there :)");
        HBox box1 = new HBox();
        
        root.getChildren().addAll(b1, b2, box1, label);
        
        Scene scene = new Scene(root, 300, 200);
        PrimaryStage.setTitle("Buttons");
        PrimaryStage.setScene(scene);
        PrimaryStage.show();
    }
}