package Snake;

import java.awt.*;
import java.util.Random;

public class Food {
    private Point position;
    private Random r;

    public Food(int width, int height){
        r = new Random();
        SpawnNew(width, height);
    }
    public void SpawnNew(int width, int height){
        position = new Point(r.nextInt(width), r.nextInt(height));
    }

    public Point getPosition() {
        return position;
    }
}
