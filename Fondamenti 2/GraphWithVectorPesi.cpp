#include <iostream>
#include <vector>
#include <chrono>
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

        bool esercizio3(vector<int>& w){
            vector<int> sommaEntranti(n(), 0);
            vector<int> sommaUscenti(n(), 0);
            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(adj[i][j] == true){
                        sommaEntranti[j] += w[i];
                        sommaUscenti[i] += w[j];
                    }
                }
            }
            for(int i = 0; i < n(); i++){
                if(sommaUscenti[i] < sommaEntranti[i]) return false;
            }
            return true;
        }
};

int main() {
    const int numNodi = 5000;
    Grafo g(numNodi);

    for (int i = 0; i < numNodi - 1; ++i) {
        g.aggiungiArco(i, i + 1);
    }
    g.aggiungiArco(numNodi - 1, 0);

    vector<int> pesi(numNodi, 2);

    auto start = chrono::high_resolution_clock::now();
    bool risultato = g.esercizio3(pesi);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    if (risultato) {
        cout << "E' possibile" << std::endl;
    } else {
        cout << "Errore" << std::endl;
    }

    cout << "\nTempo di esecuzione di 'esercizio3': " << elapsed.count() << " ms" << std::endl;

    return 0;
}