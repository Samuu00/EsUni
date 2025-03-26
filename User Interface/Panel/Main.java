package Panel;

import javax.swing.*;
import java.awt.*;

public class Main extends JFrame {
    public static void main(String[] args) {
        JFrame frame = new JFrame("App");
        frame.setBackground(Color.BLACK);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 600);

        JPanel mainPanel = new JPanel(new GridLayout(4, 4, 1, 1));
        JPanel sidePanel = new JPanel(new GridLayout(3, 1, 1, 1));
        sidePanel.setBackground(Color.DARK_GRAY);



        for (int i = 0; i < 16; i++) {
            if(i == 5){
                JPanel panelwithoutform = new JPanel();
                mainPanel.add(panelwithoutform);
            }
            else if (i == 6 || i == 9 || i == 10){
                JPanel panelwithoutform = new JPanel();
                mainPanel.add(panelwithoutform);
                panelwithoutform.setBackground(Color.DARK_GRAY);
            }
            else {
                ClassPanel panel = new ClassPanel();
                mainPanel.add(panel);
            }
        }

        for (int i = 0; i < 3; i++) {
            if(i == 0) {
                IconPanelOval iconPanel1 = new IconPanelOval();
                iconPanel1.setPreferredSize(new Dimension(100, 200));
                iconPanel1.setBackground(Color.GRAY);
                sidePanel.add(iconPanel1);
            }
            else if (i == 1) {
                IconPanelSquare iconPanel2 = new IconPanelSquare();
                iconPanel2.setPreferredSize(new Dimension(100, 200));
                iconPanel2.setBackground(Color.GRAY);
                sidePanel.add(iconPanel2);
            }
            else if (i == 2){
                IconPanelRect iconPanel3 = new IconPanelRect();
                iconPanel3.setPreferredSize(new Dimension(100, 200));
                iconPanel3.setBackground(Color.GRAY);
                sidePanel.add(iconPanel3);
            }
        }

        frame.setLayout(new BorderLayout());
        frame.add(sidePanel, BorderLayout.WEST);
        frame.add(mainPanel, BorderLayout.CENTER);

        frame.setVisible(true);
    }
}
