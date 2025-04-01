#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Grafo {
    private:
        unsigned n;
        vector<vector<unsigned>> grafo;

    public:
        Grafo(unsigned n) {
            this->n = n;
            grafo.resize(n);
        }

        void aggiungiArco(unsigned u, unsigned v) {
            grafo[u].push_back(v);
        }

        unsigned contaNodi() {
            return n;
        }

        unsigned contaArchi() {
            unsigned cont = 0;
            for (unsigned i = 0; i < n; i++) {
                cont += grafo[i].size();
            }
            return cont;
        }

        void stampaGrafo() {
            for (unsigned i = 0; i < n; i++) {
                cout << i << ": ";
                for (unsigned j = 0; j < grafo[i].size(); j++) {
                    cout << grafo[i][j] << " ";
                }
                cout << endl;
            }
        }

        bool SoloInX(vector<unsigned>& X, vector<unsigned>& Y, unsigned z) {  
            vector<bool> visitato(n, false);
            unordered_set<unsigned> X_set(X.begin(), X.end());
            unordered_set<unsigned> Y_set(Y.begin(), Y.end());
            stack<unsigned> s;
            unsigned cont = 0;

            s.push(z);
            visitato[z] = true;

            while (!s.empty()) {
                unsigned u = s.top();
                s.pop();

                for (unsigned v : grafo[u]) {
                    if (!visitato[v]) {
                        visitato[v] = true;
                        s.push(v);

                        if (Y_set.count(v)) {
                            return false;  
                        }

                        if (X_set.count(v)) {
                            cont++;
                            if (cont == X_set.size()) {
                                return true;  
                            }
                        }
                    }
                }
            }
            return false;
        }
};

int main() {
    int n, m;
    cout << "Inserire il numero di nodi del grafo: ";
    cin >> n;
    cout << "Inserire il numero di archi del grafo: ";
    cin >> m;
    Grafo g(n);

    for(int i = 0; i < m; i++){
        unsigned u, v;
        cout << "Inserire l'arco " << i+1 << ": ";
        cin >> u >> v;
        g.aggiungiArco(u, v);
    }
    
    g.stampaGrafo();

    int l, k;
    cout << "Inserire il numero di elementi di X: ";
    cin >> l;
    cout << "Inserire il numero di elementi di Y: ";
    cin >> k;
    vector<unsigned> X(l), Y(k);  
    for(int i = 0; i < l; i++){
        cout << "Inserire l'elemento " << i+1 << " di X: ";
        cin >> X[i];
    }
    for(int i = 0; i < k; i++){
        cout << "Inserire l'elemento " << i+1 << " di Y: ";
        cin >> Y[i];
    }
    unsigned z;
    cout << "Inserire il nodo di partenza z: ";
    cin >> z;

    cout << (g.SoloInX(X, Y, z) ? "True" : "False") << endl;

    return 0;
}
