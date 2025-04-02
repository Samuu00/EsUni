package Snake;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Game extends JFrame {
    public static void main(String[] args){
        JFrame frame = new JFrame("Snake");
        GamePanel game = new GamePanel();
        frame.add(game);
        game.addKeyListener(new Controller(game));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        game.requestFocusInWindow();
    }
}
