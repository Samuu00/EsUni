package ExamPanel;

import javax.swing.*;
import java.awt.event.*;
import java.io.File;

public class ExamFrame extends JFrame {
    private static ExamFrame instance;

    private ExamFrame() {
        setSize(800, 800);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setJMenuBar(createMenuBar());
    }

    public static ExamFrame getInstance() {
        if (instance == null) {
            instance = new ExamFrame();
        }
        return instance;
    }
    public void showExamPanel() {
        setContentPane(new ExamPanel());
        revalidate();
    }


    public JMenuBar createMenuBar() {
        JMenuBar menuBar = new JMenuBar();

        // File menu
        JMenu fileMenu = new JMenu("File");
        JMenuItem newExam = new JMenuItem("New Exam");
        newExam.addActionListener(e -> {
            if (ExamTest.getInstance().getAllQuestions() != null) {
                ExamTest.getInstance().resetTest();
                ExamFrame.getInstance().showExamPanel();
                ((ExamPanel) getContentPane()).showQuestion();
            } else {
                JOptionPane.showMessageDialog(null, "Carica prima un esame!");
            }
        });

        JMenuItem loadExam = new JMenuItem("Load Exam");
        loadExam.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showOpenDialog(null);
            if (result == JFileChooser.APPROVE_OPTION) {
                File file = fileChooser.getSelectedFile();
                ExamTest.getInstance().loadExamFromFile(file);
                JOptionPane.showMessageDialog(null, "Esame caricato con successo!");
            }
        });

        fileMenu.add(newExam);
        fileMenu.add(loadExam);
        menuBar.add(fileMenu);

        // Exam menu
        JMenu examMenu = new JMenu("Exam");
        JMenuItem examSuggestions = new JMenuItem("Exam Suggestions");
        JMenuItem checkAnswer = new JMenuItem("Check Answer");
        examMenu.add(examSuggestions);
        examMenu.add(checkAnswer);
        menuBar.add(examMenu);

        // Help menu
        JMenu helpMenu = new JMenu("Help");
        JMenuItem about = new JMenuItem("About");
        helpMenu.add(about);
        menuBar.add(helpMenu);

        return menuBar;
    }
}
