package Snake;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class GamePanel extends JPanel{
    private final int title_size = 25;
    private final int width = 20, height = 20;
    private Snake snake;
    private Food food;
    private boolean running = false;
    private Timer timer;

    public GamePanel() {
        this.setPreferredSize(new Dimension(width * title_size, height * title_size));
        this.setBackground(Color.WHITE);
        this.setFocusable(true);
        this.requestFocusInWindow();
        StartGame();
        timer = new Timer(100, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                move();
                repaint();
            }
        });
        timer.start();

    }

    public void StartGame() {
        snake = new Snake(width, height);
        food = new Food(width, height);
        running = true;
    }

    private void move() {
        if (!running) return;
        snake.move(food);
        if (snake.hasCollided(width, height)) {
            running = false;
            timer.stop();
        }

    }
    public Snake getSnake() {
        return snake;
    }


    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        g.setColor(Color.GREEN);
        g.drawRect(0, 0, getWidth(), getHeight());
        g.drawRect(1, 1, getWidth(), getHeight());
        g.drawRect(2, 2, getWidth(), getHeight());
        g.drawRect(3, 3, getWidth(), getHeight());
        g.drawRect(4, 4, getWidth(), getHeight());
        g.drawRect(-0, -0, getWidth(), getHeight());
        g.drawRect(-1, -1, getWidth(), getHeight());
        g.drawRect(-2, -2, getWidth(), getHeight());
        g.drawRect(-3, -3, getWidth(), getHeight());
        g.drawRect(-4, -4, getWidth(), getHeight());

        if (running) {
            g.setColor(Color.BLACK);
            g.fillRect(food.getPosition().x * title_size, food.getPosition().y * title_size, title_size, title_size);

            g.setColor(Color.RED);
            for (Point p : snake.getBody()) {
                g.fillRect(p.x * title_size, p.y * title_size, title_size, title_size);
            }
        } else {
            g.setColor(Color.BLACK);
            g.setFont(new Font("Arial", Font.BOLD, 40));
            g.drawString("GAME OVER!!", (width * title_size / 2) / 2, height * title_size / 2);
            g.setFont(new Font("Arial", Font.BOLD, 20));
            g.drawString("Score: " + snake.getScore(), (width * title_size / 2) / 2 + 80, height * title_size / 2 + 50);
        }
    }


}