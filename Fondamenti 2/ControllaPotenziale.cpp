#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Grafo {
    private:
        int n;
        vector<vector<int>> grafo;
    public:
        Grafo(int n) {
            this->n = n;
            grafo.resize(n);
        }
    
        void aggiungiArco(int u, int v) {
            grafo[u].push_back(v);
            grafo[v].push_back(u); 
        }
    
        bool controllaSeDiretto(int i, int j) {
            for (int vicino : grafo[i]) {
                if (vicino == j) {
                    return true;
                }
            }
            return false;
        }
    
        int controllaStato(vector<int>& p, int nodo) {
            int somma = 0;
            int count = 0;
    
            for (int vicino : grafo[nodo]) {
                somma += p[vicino];
                count++;
            }
    
            if (count == 0) return 0;

            double media = (double)somma / count;
            return (p[nodo] > media) ? 1 : 0;
        }
    
        int cercaPotenzialeConStato1(vector<int>& p) {
            int maxPotenziale = 0;
            int nodoConMaxPotenziale = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (controllaSeDiretto(i, j)) {  
                        if (controllaStato(p, i) == 1) {
                            if (p[i] > maxPotenziale) {
                                maxPotenziale = p[i];
                                nodoConMaxPotenziale = i;
                            }
                        }
                    }
                }
            }
            return nodoConMaxPotenziale;
        }
    
        void stampaGrafo() {
            for (int i = 0; i < n; i++) {
                cout << "Nodo " << i << ": ";
                for (int j : grafo[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};
int main() {
    Grafo g(5);
    g.aggiungiArco(0, 2);
    g.aggiungiArco(1, 2);
    g.aggiungiArco(0, 3);
    g.aggiungiArco(0, 4);

    vector<int> pot = {5, 1, 6, 3, 2};

    int risultato = g.cercaPotenzialeConStato1(pot);
    cout << "Nodo con stato 1 e massimo potenziale: " << risultato << endl;

    return 0;
}
    