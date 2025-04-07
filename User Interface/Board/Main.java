package Board;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Lavagna con linee");
        StrokeHandler model = new StrokeHandler();
        Lavagna lavagna = new Lavagna(model);
        Controller controller = new Controller(model, lavagna);

        lavagna.addMouseMotionListener(controller);

        frame.add(lavagna);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
