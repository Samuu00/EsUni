package Snake;

import java.awt.*;
import java.awt.event.*;
import java.awt.event.KeyListener;

public class Direction {
    private static final int UP = 0;
    private static final int DOWN = 1;
    private static final int LEFT = 2;
    private static final int RIGHT = 3;
    private int currentDirection;

    public Direction(int initialDirection){
        this.currentDirection = initialDirection;
    }

    public void changeDirection(int KeyCode){
        switch(KeyCode){
            case KeyEvent.VK_UP -> { if (currentDirection != DOWN) currentDirection = UP; }
            case KeyEvent.VK_DOWN -> { if (currentDirection != UP) currentDirection = DOWN; }
            case KeyEvent.VK_LEFT -> { if (currentDirection != RIGHT) currentDirection = LEFT; }
            case KeyEvent.VK_RIGHT -> { if (currentDirection != LEFT) currentDirection = RIGHT; }

        }
    }
    public Point move(Point head){
        return switch (currentDirection){
            case UP -> new Point(head.x, head.y - 1);
            case DOWN -> new Point(head.x, head.y + 1);
            case LEFT -> new Point(head.x - 1, head.y);
            case RIGHT -> new Point(head.x + 1, head.y);
            default -> head;
        };
    }

    public static int getUP() {
        return UP;
    }

    public static int getDOWN() {
        return DOWN;
    }

    public static int getLEFT() {
        return LEFT;
    }

    public static int getRIGHT() {
        return RIGHT;
    }
}
