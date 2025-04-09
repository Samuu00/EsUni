package ExamPanel;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.util.Enumeration;

public class ExamPanel extends JPanel {
    private JLabel questionLabel;
    private ButtonGroup optionsGroup;
    private JPanel optionsPanel;
    private JButton checkButton, nextButton;
    private JLabel feedbackLabel;

    public ExamPanel() {
        setLayout(new BorderLayout());

        questionLabel = new JLabel("Domanda");
        questionLabel.setFont(new Font("Arial", Font.BOLD, 16));
        add(questionLabel, BorderLayout.NORTH);

        optionsPanel = new JPanel();
        optionsPanel.setLayout(new BoxLayout(optionsPanel, BoxLayout.Y_AXIS));
        add(optionsPanel, BorderLayout.CENTER);

        JPanel bottomPanel = new JPanel(new GridLayout(2, 1));

        feedbackLabel = new JLabel("");
        feedbackLabel.setHorizontalAlignment(SwingConstants.CENTER);
        bottomPanel.add(feedbackLabel);

        JPanel buttonsPanel = new JPanel();
        checkButton = new JButton("Controlla");
        nextButton = new JButton("Prossima");
        nextButton.setEnabled(false);

        buttonsPanel.add(checkButton);
        buttonsPanel.add(nextButton);
        bottomPanel.add(buttonsPanel);

        add(bottomPanel, BorderLayout.SOUTH);

        checkButton.addActionListener(this::checkAnswer);
        nextButton.addActionListener(e -> {
            ExamTest.getInstance().nextQuestion();
            showQuestion();
        });
    }

    public void showQuestion() {
        Questions question = ExamTest.getInstance().getCurrentQuestion();
        questionLabel.setText(question.question());

        optionsPanel.removeAll();
        optionsGroup = new ButtonGroup();

        for (int i = 0; i < question.options().size(); i++) {
            JRadioButton option = new JRadioButton(question.options().get(i));
            option.setActionCommand(String.valueOf(i));
            optionsGroup.add(option);
            optionsPanel.add(option);
        }

        feedbackLabel.setText("");
        checkButton.setEnabled(true);
        nextButton.setEnabled(false);

        revalidate();
        repaint();
    }

    private void checkAnswer(ActionEvent e) {
        Enumeration<AbstractButton> buttons = optionsGroup.getElements();
        while (buttons.hasMoreElements()) {
            AbstractButton button = buttons.nextElement();
            if (button.isSelected()) {
                int userChoice = Integer.parseInt(button.getActionCommand());
                boolean correct = ExamTest.getInstance().checkAnswer(userChoice);
                feedbackLabel.setText(correct ? "✅ Corretto!" : "❌ Sbagliato!");
                checkButton.setEnabled(false);
                nextButton.setEnabled(ExamTest.getInstance().hasNextQuestion());

                if (!ExamTest.getInstance().hasNextQuestion()) {
                    nextButton.setText("Fine");
                    nextButton.addActionListener(ev -> showFinalScore());
                }

                return;
            }
        }

        JOptionPane.showMessageDialog(this, "Seleziona una risposta.");
    }

    private void showFinalScore() {
        int correct = 0;
        for (Questions q : ExamTest.getInstance().getAllQuestions()) {
            // qui puoi implementare una struttura per salvare le risposte e calcolare il punteggio
        }
        JOptionPane.showMessageDialog(this, "Hai completato l'esame!");
    }
}
