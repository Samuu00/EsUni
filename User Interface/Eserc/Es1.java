package Eserc;

import java.util.Scanner;
public class Es1 {
    public static void main(String[] args) {
        Scanner n = new Scanner(System.in);
        int[] a = new int[10];
        System.out.print("Inserisci 10 numeri da inserire nell'array: ");
        int somma = 0;
        for (int i = 0; i <= 9; i++) {
            a[i] = n.nextInt();
            somma += a[i];
        }
        double media = somma/10;
        for (int x : a) {
            System.out.print(x + " ");
        }
        int max = 0, min = a[0];
        for (int i : a){
            if (a[i] > max) {
                max = a[i];
            }
            if (a[i] < min){
                min = a[i];
            }

        }
        System.out.print("Numero massimo: " + max + " " + "Numero minimo: " + min + " " + "Media: " + media);
    }
}