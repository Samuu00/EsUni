package ExamPanel;

import java.util.List;

public record Questions(String question, List<String> options, int correctIndex) {
    public boolean isCorrect(int userChoice) {
        return userChoice == correctIndex;
    }
}
