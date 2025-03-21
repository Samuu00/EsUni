package Veicolo;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Inserisci quanti veicoli vuoi inserire: ");
        int n = s.nextInt();
        s.nextLine();

        Veicolo[] veicoli = new Veicolo[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Inserisci tipo veicolo (auto/moto): ");
            String tipo = s.nextLine();

            System.out.print("Inserisci marca veicolo: ");
            String marca = s.nextLine();

            System.out.print("Inserisci modello veicolo: ");
            String modello = s.nextLine();

            System.out.print("Inserisci anno produzione veicolo: ");
            int annoProd = s.nextInt();
            s.nextLine();

            if (tipo.equals("auto")) {
                System.out.print("Inserisci numero porte: ");
                int numeroPorte = s.nextInt();
                s.nextLine();
                veicoli[i] = new Auto(marca, modello, annoProd, numeroPorte);
            } else if (tipo.equals("moto")) {
                System.out.print("La moto ha un sidecar? (true/false): ");
                boolean hasSideCar = Boolean.parseBoolean(s.nextLine());

                System.out.print("Inserisci cilindrata: ");
                int cc = s.nextInt();
                s.nextLine();
                veicoli[i] = new Moto(marca, modello, annoProd, cc, hasSideCar);
            }
        }
        System.out.println("\nVeicoli inseriti:");
        for (Veicolo v : veicoli) {
            System.out.println(v);
        }

        String ts;
        System.out.println("\nInserisci se far transitare i veicoli in Autostrada o Stradasecondaria(a/s):");
        ts = s.nextLine();
        if(ts.equals("a")) {
            Percorribile strada = new Autostrada() {
                @Override
                public void Viaggia() {
                }
            };
            System.out.println("Proviamo a far viaggiare i veicoli:");
            for (Veicolo v : veicoli) {
                v.Viaggia(strada);
            }
        } else if(ts.equals("s")){
            Percorribile strada = new Stradasecondaria() {
                @Override
                public void Viaggia() {
                }
            };
            System.out.println("Proviamo a far viaggiare i veicoli:");
            for (Veicolo v : veicoli) {
                v.Viaggia(strada);
            }
        }


    }
}
