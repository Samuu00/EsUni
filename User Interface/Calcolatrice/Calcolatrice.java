package Calcolatrice;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calcolatrice extends JFrame implements ActionListener {
    private JTextField display;
    private String operazione = "";
    private double numero1, numero2;
    private boolean nuovoNumero = true;

    public Calcolatrice() {
        setTitle("Calcolatrice");
        setSize(500, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        int screenWidth = (int) screenSize.getWidth();
        int screenHeight = (int) screenSize.getHeight();
        int frameWidth = getWidth();
        int frameHeight = getHeight();
        int x = (screenWidth - frameWidth) / 2;
        int y = (screenHeight - frameHeight) / 2;
        setLocation(x, y);
        setLayout(new BorderLayout());

        // Display
        display = new JTextField();
        display.setBackground(Color.BLACK);
        display.setForeground(Color.WHITE); // Testo bianco
        display.setFont(new Font("Arial", Font.BOLD, 50));
        display.setHorizontalAlignment(JTextField.RIGHT);
        display.setEditable(false);
        add(display, BorderLayout.NORTH);

        // Pannello pulsanti
        JPanel pannello = new JPanel();
        pannello.setLayout(new GridLayout(4, 4, 5, 5));
        pannello.setBackground(Color.BLACK);

        // Pulsanti numerici e operazioni
        String[] bottoni = {
                "7", "8", "9", "÷",
                "4", "5", "6", "x",
                "1", "2", "3", "-",
                "C", "0", "=", "+"
        };

        for (String testo : bottoni) {
            RoundedButton bottone = new RoundedButton(testo);
            bottone.setBackground(Color.LIGHT_GRAY);
            if (testo.matches("[0-9]")) {
                bottone.setBackground(Color.ORANGE);// Numeri in arancione
            }
            else if (testo == "C"){
                bottone.setBackground(Color.DARK_GRAY);
            }
            bottone.setFont(new Font("Arial", Font.BOLD, 16));
            bottone.setForeground(Color.BLACK);
            bottone.addActionListener(this);
            pannello.add(bottone);
        }

        add(pannello, BorderLayout.CENTER);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String comando = e.getActionCommand();

        if (comando.matches("[0-9]")) { // Se è un numero
            if (nuovoNumero) {
                display.setText(comando);
                nuovoNumero = false;
            } else {
                display.setText(display.getText() + comando);
            }
        } else if (comando.matches("[+\\-x÷]")) { // Se è un'operazione
            numero1 = Double.parseDouble(display.getText());
            operazione = comando;
            nuovoNumero = true;
        } else if (comando.equals("=")) { // Calcolo
            numero2 = Double.parseDouble(display.getText());
            Operazioni operazioneCorrente = null;
            double risultato = 0;

            switch (operazione) {
                case "+":
                    operazioneCorrente = new Somma(numero1, numero2);
                    risultato = operazioneCorrente.Calcola();
                    display.setText(String.valueOf(risultato));
                    break;
                case "-":
                    operazioneCorrente = new Sottrazione(numero1, numero2);
                    risultato = operazioneCorrente.Calcola();
                    display.setText(String.valueOf(risultato));
                    break;
                case "x":
                    operazioneCorrente = new Moltiplicazione(numero1, numero2);
                    risultato = operazioneCorrente.Calcola();
                    display.setText(String.valueOf(risultato));
                    break;
                case "÷":
                    try {
                        operazioneCorrente = new Divisione(numero1, numero2);
                        risultato = operazioneCorrente.Calcola();
                        display.setText(String.valueOf(risultato));
                    } catch (ArithmeticException ex) {
                        display.setText("STRONZONE");
                    }
                    break;
            }
            nuovoNumero = true;
        } else if (comando.equals("C")) { // Cancella tutto
            display.setText("");
            numero1 = numero2 = 0;
            operazione = "";
            nuovoNumero = true;
        }
    }
}
