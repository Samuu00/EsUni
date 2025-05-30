package Panel;

import javax.swing.*;
import java.awt.*;

class IconPanelOval extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);
        int size = Math.min(getWidth(), getHeight()) / 2;
        g.fillOval(getWidth() / 2 - size / 2, getHeight() / 2 - size / 2, size, size);
    }
}
