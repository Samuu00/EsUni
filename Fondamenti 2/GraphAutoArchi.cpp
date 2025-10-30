#include <iostream>
#include <vector>
#include <queue>
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
                numArchi++;
            }
        }


        bool f(){
            if(g.m() % 2 != 0) return false;

            vector<int> gUscente(n(), 0);
            vector<int> nEntranti(n(), 0);
            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(adj[i][j]){
                        if(i == j) return false;
                        gUscente[i]++;
                        nEntranti[j]++;
                    }
                }
            }

            int nMax1 = 0;
            for(int i = 0; i < n(); i++){
                if(nEntranti[i] <= 1) nMax1++;
            }

            for(int i = 0; i < n(); i++){
                if(gUscente[i] >= nMax1) return false;
            }
            return true;
        }
}