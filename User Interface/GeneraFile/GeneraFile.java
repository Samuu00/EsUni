package GeneraFile;

import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.Random;

public class GeneraFile {
    public static void GeneraFile(String nameFile){
        Random random = new Random();
        String chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnoqrstuvwxyz0123456789";
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(nameFile))){
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < 20; i++) {
                for (int j = 0; j < random.nextInt(10) + 5; j++) {
                    sb.append(chars.charAt(random.nextInt(chars.length())));
                }
                writer.write(sb.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public static List<String> leggiFile(String nameFile){
        List<String> righe = new ArrayList<>();
        try{
            righe = Files.readAllLines(Paths.get(nameFile));
            for(String riga: righe){
                System.out.print(riga);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return righe;
    }

    public static void stampaLineeNumeriche(String nameFile){
        List<String> righe = leggiFile(nameFile);
        for(String riga: righe){
            if(riga.matches(".*\\d.*")){
                System.out.print(riga);
            }
        }
    }
    public static void stampaLineeConNumero(String nameFile){
        stampaLineeNumeriche(nameFile);
    }
    public static void stampaLineeConCharPari(String nameFile, char l){
        List<String> righe = leggiFile(nameFile);
        String pattern = l + "" + l;
        for(String riga : righe){
            if(riga.contains(pattern)){
                System.out.print(riga);
            }
        }
    }
    public static void stampaLineeConCaratteriUguali(String nameFile, char l1, char l2){
        List<String> righe = leggiFile(nameFile);
        for(String riga : righe){
            long count1 = riga.chars().filter(ch -> ch == l1).count();
            long count2 = riga.chars().filter(ch -> ch == l2).count();
            if(count1 == count2 && count1 > 0){
                System.out.print(riga);
            }
        }
    }
}
