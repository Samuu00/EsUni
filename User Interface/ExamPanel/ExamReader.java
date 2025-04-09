package ExamPanel;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class ExamReader {
    public static List<Questions> loadFromFile(File file) {
        List<Questions> questions = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String questionText;
            while ((questionText = br.readLine()) != null) {
                String optionsLine = br.readLine();
                String correctOptionText = br.readLine();

                if (optionsLine == null || correctOptionText == null) {
                    System.out.println("Errore: formato del file non valido.");
                    break;
                }

                List<String> options = List.of(optionsLine.split(";"));
                int correctIndex = options.indexOf(correctOptionText);

                if (correctIndex == -1) {
                    System.out.println("Errore: la risposta corretta non è presente tra le opzioni.");
                    continue;
                }

                questions.add(new Questions(questionText, options, correctIndex));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return questions;
    }
}
