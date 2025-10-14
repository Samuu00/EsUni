#include <iostream>
#include <vector>
using namespace std;

class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n, vector<int> p) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

        int n() const {
            return numNodi;
        }
        int m() const {
            return numArchi;
        }

        void aggiungiArco(int i, int j) {
            if (i < 0 || j < 0 || i >= numNodi || j >= numNodi) throw out_of_range("Indice nodo non valido");
            if (!adj[i][j]) {
                adj[i][j] = true;
                adj[j][i] = true;
                numArchi++;
            }
        }

        double media(int num, int qua){
            if(qua == 0) return 0; 
            return static_cast<double>(num) / qua;
        }       

        int esercizio3(const vector<int>& potenziali){
            vector<int> sommaPotenzialiUscenti(n(), 0);
            vector<int> uscenti(n(), 0);
            vector<int> stato(n(), 0);
            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(adj[i][j]){
                        uscenti[i]++;
                        sommaPotenzialiUscenti[i] += potenziali[j]; 
                    }
                }
            }

            for(int i = 0; i < n(); i++){
                if(potenziali[i] > media(sommaPotenzialiUscenti[i], uscenti[i])){
                    stato[i] = 1;
                }
            }
            int maxIndex = -1;
            int maxPot = -1;
            for(int i = 0; i < n(); i++){
                if(stato[i] == 1 && potenziali[i] > maxPot){
                    maxPot = potenziali[i];
                    maxIndex = i;
                }
            }
            return maxIndex;
       }
};