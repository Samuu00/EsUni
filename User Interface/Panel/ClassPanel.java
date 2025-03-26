package Panel;

import javax.swing.*;
import java.awt.*;

public class ClassPanel extends JPanel {
    public ClassPanel(){
        setBackground(Color.LIGHT_GRAY);
    }
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);

        for (int i = 0; i < 5; i++) {
            int size = (int) (Math.random() * 20) + 5;
            int x = (int) (Math.random() * getWidth());
            int y = (int) (Math.random() * getHeight());
            if (Math.random() > 0.5)
                g.fillRect(x, y, size, size);
            else
                g.fillOval(x, y, size, size);
        }
    }
}
