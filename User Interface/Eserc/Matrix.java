package Eserc;

import java.util.Scanner;
public class Matrix {
    public static void main(String[] args){
        Scanner n = new Scanner(System.in);
        int l = n.nextInt();
        int[][] m = new int[l][l];
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                m[i][j] = n.nextInt();
            }
        }
        int somma = 0, cont = 0;
        double media = 0;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                somma += m[i][j];
                cont += 1;
            }
        }
        media = somma/cont;
        System.out.print("La somma degli elementi della matrice è: " + somma + " " + "La media tra gli elementi è: " + media);
    }
}
