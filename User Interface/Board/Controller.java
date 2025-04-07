package Board;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class Controller extends MouseAdapter implements MouseMotionListener {
    private Lavagna view;
    private StrokeHandler model;

    public Controller(StrokeHandler model, Lavagna view) {
        this.model = model;
        this.view = view;
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        model.addPoint(e.getX(), e.getY());
        view.repaint();
    }
}
