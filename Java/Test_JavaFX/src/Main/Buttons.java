package Main;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Buttons extends Application
{
    @Override
    public void start(Stage PrimaryStage)
    {
        VBox root = new VBox();
        Button b1 = new Button("Change the color");
        Button b2 = new Button("GoodBye");
        b1.setOnAction(new ColorChangeHandler(root));
        b2.setOnAction(new GoodbyeHandler());
        
        Label label = new Label("Hello there :)");
        HBox box1 = new HBox();
        
        root.getChildren().addAll(b1, b2, box1, label);
        
        Scene scene = new Scene(root, 300, 200);
        PrimaryStage.setTitle("Buttons");
        PrimaryStage.setScene(scene);
        PrimaryStage.show();
    }
    
    private class GoodbyeHandler implements EventHandler<ActionEvent>
    {
        @Override
        public void handle(ActionEvent event)
        {
            System.exit(0);
        }
    }
    
    private class ColorChangeHandler implements EventHandler<ActionEvent>
    {
        private VBox root;
        private Scene scene;
        
        public ColorChangeHandler(VBox root)
        {
            this.root = root;
        }
        
        @Override
        public void handle(ActionEvent event)
        {
            int red = (int) (Math.random() * 256);
            int green = (int) (Math.random() * 256);
            int blue = (int) (Math.random() * 256);

            Color color = Color.rgb(red, green, blue);
        }
    }
}