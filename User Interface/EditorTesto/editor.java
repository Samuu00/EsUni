package EditorTesto;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.FileChooser;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class editor extends Application {
    private TextArea text = new TextArea();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primarystage){
        Button newButton = new Button("New");
        Button openButton = new Button("Open");
        Button saveButton = new Button("Save");

        newButton.setOnAction(e -> text.clear());
        openButton.setOnAction(e -> {
            FileChooser fc = new FileChooser();
            File f = fc.showOpenDialog(primarystage);
            if(f != null){
                try(BufferedReader bf = new BufferedReader(new FileReader(f))){
                    text.clear();
                    String line;
                    while((line = bf.readLine()) != null){
                        text.appendText(line + "\n");
                    }
                } catch (FileNotFoundException ex) {
                    throw new RuntimeException(ex);
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
        });
        saveButton.setOnAction(e ->{
            FileChooser fc = new FileChooser();
            File f = fc.showSaveDialog(primarystage);
            if(f != null){
                try(BufferedWriter bw = new BufferedWriter(new FileWriter(f))){
                    bw.write(text.getText());
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }

            }
        });

        HBox buttorbar = new HBox(10, newButton, saveButton, openButton);
        VBox root = new VBox(10, buttorbar, text);

        Scene scene = new Scene(root, 800, 800);
        text.setPrefSize(600, 800);
        scene.getStylesheets().add(getClass().getResource("style.css").toExternalForm());
        primarystage.setTitle("Text editor");
        primarystage.setScene(scene);
        primarystage.show();
    }
}
