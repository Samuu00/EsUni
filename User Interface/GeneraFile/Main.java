package GeneraFile;

import java.util.Scanner;

public class Main extends GeneraFile {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        String fileName = "text.txt";
        GeneraFile(fileName);

        System.out.println("Contenuto del file:\n");
        leggiFile(fileName);
        System.out.println("\n");


        System.out.println("Linee numeriche:\n");
        stampaLineeNumeriche(fileName);
        System.out.println("\n");


        System.out.println("Linee con almeno un numero:\n");
        stampaLineeConNumero(fileName);
        System.out.println("\n");


        System.out.println("Linee con caratteri pari(Inserisci un carattere):\n");
        char c;
        c = s.next().charAt(0);
        stampaLineeConCharPari(fileName, c);
        System.out.println("\n");

        System.out.println("Linee con caratteri uguali(Inserisci due caratteri):\n");
        char c1, c2;
        c1 = s.next().charAt(0);
        c2 = s.next().charAt(0);
        stampaLineeConCaratteriUguali(fileName, c1, c2);
        System.out.println("\n");

    }
}
