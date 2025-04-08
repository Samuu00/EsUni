#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Grafo {
    private:
        int n;
        vector<vector<int>> grafo;
    public:
        Grafo(int n){
            this->n = n;
            grafo.resize(n);
        }

        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }

        bool controllaSeDiretto(int i, int j){
            for(int vicino : grafo[i]){
                if(vicino == j){
                    return true;
                }
            }
            return false;
        }

        void stampaGrafo(){
            for(int i = 0; i < n; i++){
                cout << " Nodo " << i << ": ";
                for(int j : grafo[i]){
                    cout << j << " ";
                }
                cout<<endl;
            }
        }
};
int main(){
    int n;
    cout << "Inserisci numero nodi del grafo: " << endl;
    cin >> n;
    Grafo g(n);
    int m;
    cout << "Inserisci numero archi del grafo: " << endl;
    cin >> m;
    cout << "Inserisci gli archi del grafo (u v): " << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.aggiungiArco(u, v);
    }
    cout << "Grafo creato: " << endl;
    g.stampaGrafo();
    int i, j;
    cout << "Inserisci due nodi per controllare se l'arco esiste: " << endl;
    cin >> i >> j;
    if(g.controllaSeDiretto(i, j)){
        cout << "L'arco esiste." << endl;
    } else {
        cout << "L'arco non esiste." << endl;
    }
    return 0;
}