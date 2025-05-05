#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//es1
template <typename T, typename U>
class Coppia {
    private:
        T primo;
        U secondo;

    public:
        Coppia(T p, U s) : primo(p), secondo(s) {}

        T getPrimo() const { 
            return primo; 
        }
        U getSecondo() const { 
            return secondo; 
        }

        bool operator==(const Coppia<T, U>& other) const {
            return (primo == other.primo && secondo == other.secondo);
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr){}
};

int altezza(nodo* root){
    if(root == nullptr) return 0;
    int altSin = altezza(root->sinistro);
    int altDest = altezza(root->destro);
    return 1 + max(altSin, altDest);
}

bool bilanciato(nodo* root){
    if(root == nullptr) return true;
    int altSin = altezza(root->sinistro);
    int altDest = altezza(root->destro);
    if(abs(altSin - altDest) > 1) return false;
    return bilanciato(root->sinistro) && bilanciato(root->destro);
}


//es3
#include <iostream>
#include <vector>
#include <queue>
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
    }

    vector<int> camminoPiuCosto(int u, vector<int>& pesi) {
        int n = pesi.size();
        queue<int> q;
        vector<bool> visitato(n, false);
        q.push(u);
        visitato[u] = true;
        vector<int> camminoMigliore;
        int costoMassimo = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int vicino : grafo[v]) {
                if (!visitato[vicino]) {
                    int pesoCammino = pesi[v] + pesi[vicino];
                    if (pesoCammino > costoMassimo) {
                        costoMassimo = pesoCammino;
                        camminoMigliore = {v, vicino};
                    }
                    visitato[vicino] = true;
                    q.push(vicino);
                }
            }
        }
        return camminoMigliore;
    }
};
int main() {
    int n = 5;  
    Grafo g(n);

    g.aggiungiArco(0, 1);
    g.aggiungiArco(0, 2);
    g.aggiungiArco(1, 3);
    g.aggiungiArco(2, 4);

    vector<int> pesi = {3, 5, 3, 12, 9};

    vector<int> cammino = g.camminoPiuCosto(0, pesi);

    if (!cammino.empty()) {
        cout << "Cammino con costo massimo: ";
        for (int nodo : cammino) {
            cout << nodo << " ";
        }
        cout << "\nCosto: " << pesi[cammino[0]] + pesi[cammino[1]] << endl;
    } else {
        cout << "Nessun cammino trovato." << endl;
    }

    return 0;
}