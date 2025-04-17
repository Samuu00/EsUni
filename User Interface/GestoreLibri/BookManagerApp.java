package GestoreLibri;

import javafx.application.Application;
import javafx.geometry.*;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class BookManagerApp extends Application {

    private Stage primaryStage;
    private String currentUser;
    private VBox bookListVBox;
    private boolean darkTheme = false;
    private final String USERS_FILE = "src/GestoreLibri/users.txt";
    private final String BOOKS_FILE = "src/GestoreLibri/books.txt";

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        this.primaryStage = primaryStage;
        primaryStage.setTitle("Book Manager");
        showLoginScene();
    }

    private void showLoginScene() {
        Label userLabel = new Label("Username:");
        TextField usernameField = new TextField();
        Label passLabel = new Label("Password:");
        PasswordField passwordField = new PasswordField();
        Button loginButton = new Button("Login");
        Label messageLabel = new Label();

        loginButton.setOnAction(e -> {
            String user = usernameField.getText();
            String pass = passwordField.getText();
            if (checkCredentials(user, pass)) {
                currentUser = user;
                showBookScene();
            } else {
                messageLabel.setText("Credenziali errate.");
            }
        });

        VBox loginLayout = new VBox(10, userLabel, usernameField, passLabel, passwordField, loginButton, messageLabel);
        loginLayout.getStyleClass().add("login-layout");  // Aggiungi la classe CSS
        loginLayout.setAlignment(Pos.CENTER);
        Scene loginScene = new Scene(loginLayout, 300, 250);
        applyTheme(loginScene);
        primaryStage.setScene(loginScene);
        primaryStage.show();
    }


    private boolean checkCredentials(String username, String password) {
        try {
            List<String> lines = Files.readAllLines(Paths.get(USERS_FILE));
            for (String line : lines) {
                String[] parts = line.split(",");
                if (parts.length == 2 && parts[0].equals(username) && parts[1].equals(password)) {
                    return true;
                }
            }
        } catch (IOException e) {
            System.out.println("Errore nel file users.txt");
        }
        return false;
    }

    private void showBookScene() {
        bookListVBox = new VBox(10);
        updateBookList();

        Button addBookBtn = new Button("Add Book");
        Button themeBtn = new Button("Set light/dark theme");
        Button logoutBtn = new Button("Logout");

        addBookBtn.setOnAction(e -> showAddBookDialog());
        themeBtn.setOnAction(e -> {
            darkTheme = !darkTheme;
            showBookScene();
        });
        logoutBtn.setOnAction(e -> showLoginScene());

        VBox layout = new VBox(15, bookListVBox, addBookBtn, themeBtn, logoutBtn);
        layout.getStyleClass().add("book-layout");  // Aggiungi la classe CSS
        layout.setPadding(new Insets(20));
        Scene bookScene = new Scene(layout, 400, 400);
        applyTheme(bookScene);
        primaryStage.setScene(bookScene);
        primaryStage.show();
    }


    private void updateBookList() {
        bookListVBox.getChildren().clear();
        try {
            List<String> lines = Files.readAllLines(Paths.get(BOOKS_FILE));
            for (String line : lines) {
                String[] parts = line.split(",");
                if (parts.length >= 3 && parts[0].equals(currentUser)) {
                    Label bookLabel = new Label("Titolo: " + parts[1] + " | Autore: " + parts[2]);
                    bookListVBox.getChildren().add(bookLabel);
                }
            }
        } catch (IOException e) {
            System.out.println("Errore nel file books.txt");
        }
    }

    private void showAddBookDialog() {
        Dialog<Void> dialog = new Dialog<>();
        dialog.setTitle("Aggiungi Libro");

        Label titleLabel = new Label("Titolo:");
        TextField titleField = new TextField();
        Label authorLabel = new Label("Autore:");
        TextField authorField = new TextField();

        GridPane grid = new GridPane();
        grid.setVgap(10);
        grid.setHgap(10);
        grid.add(titleLabel, 0, 0);
        grid.add(titleField, 1, 0);
        grid.add(authorLabel, 0, 1);
        grid.add(authorField, 1, 1);

        ButtonType addButtonType = new ButtonType("Aggiungi", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(addButtonType, ButtonType.CANCEL);
        dialog.getDialogPane().setContent(grid);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == addButtonType) {
                addBook(titleField.getText(), authorField.getText());
                updateBookList();
            }
            return null;
        });

        dialog.showAndWait();
    }

    private void addBook(String title, String author) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(BOOKS_FILE, true))) {
            writer.write(currentUser + "," + title + "," + author);
            writer.newLine();
        } catch (IOException e) {
            System.out.println("Errore scrivendo in books.txt");
        }
    }

    private void applyTheme(Scene scene) {
        String theme = darkTheme ? "dark-theme" : "light-theme";
        scene.getStylesheets().clear();
        scene.getStylesheets().add(getClass().getResource("/GestoreLibri/style.css").toExternalForm());
        scene.getRoot().getStyleClass().add(theme);
    }

}

