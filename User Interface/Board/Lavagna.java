package Board;

import javax.swing.*;
import java.awt.*;
import java.util.List;

public class Lavagna extends JPanel {
    private StrokeHandler model;

    public Lavagna(StrokeHandler model) {
        this.model = model;
        setBackground(Color.WHITE);
        setPreferredSize(new Dimension(800, 800));
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);

        List<Point> points = model.getPoints();
        for (int i = 1; i < points.size(); i++) {
            Point p1 = points.get(i - 1);
            Point p2 = points.get(i);
            g.drawLine(p1.x, p1.y, p2.x, p2.y);
        }
    }
}
