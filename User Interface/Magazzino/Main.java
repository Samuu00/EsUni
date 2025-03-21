package Magazzino;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Magazzino magazzino = new Magazzino();
        Scanner s = new Scanner(System.in);

        System.out.println("Inserisci quanti prodotti vuoi aggiungere: ");
        int n = s.nextInt();
        s.nextLine();

        for(int i = 0; i < n; i++){
            System.out.println("Inserisci ID: ");
            String id = s.nextLine();
            System.out.println("Inserisci tipologia: ");
            String tp = s.nextLine();
            System.out.println("Inserisci marca: ");
            String ma = s.nextLine();
            System.out.println("Inserisci modello: ");
            String mo = s.nextLine();
            System.out.println("Inserisci anno di produzione: ");
            int ap = s.nextInt();
            System.out.println("Inserisci prezzo: ");
            double pr = s.nextDouble();
            s.nextLine();

            magazzino.aggiungiProdotti(id, tp, ma, mo, ap, pr);
        }

        String prezzo;
        System.out.println("Inserisci (crescente/decrescente) in base a come vuoi ordinare il prezzo: ");
        prezzo = s.nextLine();
        switch (prezzo){
            case "crescente":
                magazzino.prezzoCrescente();
                break;
            case "decrescente":
                magazzino.prezzoDecrescente();
                break;
        }

        System.out.println("Inserisci ID del prodotto da rimuovere (o lascia vuoto per saltare): ");
        String idR = s.nextLine();
        magazzino.rimuoviProdotti(idR);

        System.out.println("Vuoi cercare un prodotto? (marca/modello/tipologia/no): ");
        String ricerca = s.nextLine().toLowerCase();

        switch (ricerca) {
            case "marca":
                System.out.println("Inserisci la marca da cercare: ");
                String marca = s.nextLine();
                magazzino.cercaPerMarca(marca);
                break;
            case "modello":
                System.out.println("Inserisci il modello da cercare: ");
                String modello = s.nextLine();
                magazzino.cercaPerModello(modello);
                break;
            case "tipologia":
                System.out.println("Inserisci la tipologia da cercare: ");
                String tipo = s.nextLine();
                magazzino.cercaPerTipologia(tipo);
                break;
        }

    }
}
