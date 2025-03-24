package Panel;

import javax.swing.*;
import java.awt.*;
import java.util.List;

public class MyFrame extends JFrame {

    public MyFrame(String titolo) {
        super(titolo);
    }
    public void MyDialogFrame() {
        int scelta = JOptionPane.showConfirmDialog(
                this, "Vuoi ingrandire la finestra?", "Selezionare un'opzione",
                JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE);

        if (scelta == JOptionPane.YES_OPTION) {
            setExtendedState(JFrame.MAXIMIZED_BOTH);
        }
    }
    public void ColorSelector(){
        java.util.List<String> colors = List.of("Rosso", "Verde", "Blu");

        // Mostra un menu a tendina per selezionare un colore
        String chosen = (String) JOptionPane.showInputDialog(
                null,
                "Seleziona il tuo colore preferito:",
                "Selettore colori",
                JOptionPane.PLAIN_MESSAGE,
                null,
                colors.toArray(new String[0]), // Converte la lista in array
                colors.get(0) // Valore predefinito
        );

        // Controlla se l'utente ha selezionato un'opzione valida
        if (chosen != null) {
            System.out.println("Colore selezionato: " + chosen);
        } else {
            System.out.println("Nessun colore selezionato.");
        }

        // Chiede all'utente di inserire un colore manualmente
        String inserted = JOptionPane.showInputDialog("Inserisci il tuo colore preferito:");

        if (inserted != null && !inserted.trim().isEmpty()) {
            System.out.println("Colore inserito manualmente: " + inserted);
        } else {
            System.out.println("Nessun colore inserito.");
        }
    }

    public static void main(String[] args) {
        MyFrame f = new MyFrame("Minecraft");
        f.setSize(900, 600);
        f.setLayout(new BorderLayout());

        // Creazione e impostazione dei colori dei pannelli
        JPanel sopra = new JPanel();
        sopra.setBackground(Color.BLACK);

        JPanel sinistra = new JPanel();
        sinistra.setBackground(Color.WHITE);

        JPanel centro = new JPanel();
        centro.setBackground(Color.GRAY);

        JPanel destra = new JPanel();
        destra.setBackground(Color.DARK_GRAY);

        JPanel sotto = new JPanel();
        sotto.setBackground(Color.LIGHT_GRAY);

        // Aggiunta dei pannelli al frame con BorderLayout
        f.add(sopra, BorderLayout.PAGE_START);
        f.add(sinistra, BorderLayout.LINE_START);
        f.add(centro, BorderLayout.CENTER);
        f.add(destra, BorderLayout.LINE_END);
        f.add(sotto, BorderLayout.PAGE_END);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Imposta l'azione di chiusura
        f.setVisible(true);
        f.MyDialogFrame();
        f.ColorSelector();

    }


}
