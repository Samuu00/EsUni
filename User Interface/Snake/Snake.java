package Snake;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

public class Snake {
    private ArrayList<Point> body;
    private Direction direction;

    public Snake(int width, int height) {
        body = new ArrayList<>();
        body.add(new Point(width / 2, height / 2));
        direction = new Direction(Direction.getRIGHT());
    }

    public void move(Food food) {
        if (direction == null) {
            System.out.println("Errore: direction è null!");
            return;
        }

        Point head = body.get(0);
        Point newHead = direction.move(head);

        if (newHead.equals(food.getPosition())) {
            body.add(0, food.getPosition());
            food.SpawnNew(20, 20);
        } else {
            body.add(0, newHead);
            body.remove(body.size() - 1);
        }
    }

    public boolean hasCollided(int width, int height) {
        Point head = body.get(0);
        return head.x < 0 || head.x >= width || head.y < 0 || head.y >= height || body.subList(1, body.size()).contains(head);
    }

    public void changeDirection(int keyCode) {
        if (direction != null) {
            direction.changeDirection(keyCode);
        }
    }

    public ArrayList<Point> getBody() {
        return body;
    }
}
