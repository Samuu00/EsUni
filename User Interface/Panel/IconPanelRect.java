package Panel;

import javax.swing.*;
import java.awt.*;


class IconPanelRect extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);
        int size = Math.min(getWidth(), getHeight()) / 2;
        int x = getWidth() / 2 - size / 2;
        int y = getHeight() / 2 - size / 2;
        g.fillRect(x, y, size, size / 2);
    }
}
