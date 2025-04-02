package Snake;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class Controller extends KeyAdapter {
    private GamePanel gamePanel;

    public Controller(GamePanel gamePanel) {
        this.gamePanel = gamePanel;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        gamePanel.getSnake().changeDirection(e.getKeyCode());

    }
}
