#include <iostream>
#include <vector>
using namespace std;

class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

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

        bool f() {
            vector<int> gEntranti(numNodi, 0);
            vector<int> gUscenti(numNodi, 0);

            for (int i = 0; i < numNodi; i++) {
                for (int j = 0; j < numNodi; j++) {
                    if (adj[i][j]) {
                        if (i == j) return false; 
                        gEntranti[j]++;
                        gUscenti[i]++;
                    }
                }
            }

            int cont = 0;
            for (int v : gEntranti) {
                if (v <= 1) cont++;
            }

            for (int i = 0; i < numNodi; i++) {
                if (gUscenti[i] >= cont) return false;
            }

            if (numArchi % 2 != 0) return false;

            return true;
        }

};

int main() {

    Grafo g(4);

    g.aggiungiArco(0, 1);
    g.aggiungiArco(1, 2);
    g.aggiungiArco(1, 3);

    cout << "Numero nodi: " << g.n() << endl;
    cout << "Numero archi: " << g.m() << endl;

    if (g.f()) {
        cout << "Il grafo soddisfa tutte le condizioni" << endl;
    } else {
        cout << "Il grafo NON soddisfa le condizioni" << endl;
    }

    return 0;
}
