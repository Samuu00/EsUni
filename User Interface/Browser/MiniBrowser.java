package Browser;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;

public class MiniBrowser extends Application {

    @Override
    public void start(Stage primaryStage) {
        WebView webView = new WebView();
        WebEngine webEngine = webView.getEngine();

        TextField addressBar = new TextField("https://www.google.com");
        addressBar.setPrefWidth(1800);
        addressBar.setOnAction(e -> webEngine.load(addressBar.getText()));

        Button backButton = new Button("<-");
        backButton.setOnAction(e -> {
            if (webEngine.getHistory().getCurrentIndex() > 0) {
                webEngine.getHistory().go(-1);
            }
        });

        Button forwardButton = new Button("->");
        forwardButton.setOnAction(e -> {
            if (webEngine.getHistory().getCurrentIndex() < webEngine.getHistory().getEntries().size() - 1) {
                webEngine.getHistory().go(1);
            }
        });

        HBox toolBar = new HBox(10, backButton, forwardButton, addressBar);

        BorderPane root = new BorderPane();
        root.setTop(toolBar);
        root.setCenter(webView);

        webEngine.load(addressBar.getText());

        Scene scene = new Scene(root, 800, 600);
        scene.getStylesheets().add(getClass().getResource("style.css").toExternalForm());
        primaryStage.setTitle("Mini Browser");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
