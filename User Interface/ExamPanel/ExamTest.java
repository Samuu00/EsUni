package ExamPanel;

import java.io.File;
import java.util.List;

public class ExamTest {
    private static ExamTest instance;
    private List<Questions> questions;
    private int currentQuestionIndex = 0;

    public void loadExamFromFile(File file) {
        questions = ExamReader.loadFromFile(file);
        currentQuestionIndex = 0;
    }

    public static ExamTest getInstance() {
        if (instance == null) {
            instance = new ExamTest();
        }
        return instance;
    }

    public Questions getCurrentQuestion() {
        return questions.get(currentQuestionIndex);
    }

    public boolean checkAnswer(int userChoice) {
        return getCurrentQuestion().isCorrect(userChoice);
    }

    public boolean hasNextQuestion() {
        return currentQuestionIndex < questions.size() - 1;
    }

    public void nextQuestion() {
        if (hasNextQuestion()) {
            currentQuestionIndex++;
        }
    }

    public void resetTest() {
        currentQuestionIndex = 0;
    }

    public List<Questions> getAllQuestions() {
        return questions;
    }
}
