#include <iostream>
#include <vector>
using namespace std;

class Grafo{
    private:
        vector<vector<int>> grafo;
    public:
        Grafo(int n){
            grafo.resize(n);
        }
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        void stampaGrafo(){
            for(size_t i = 0; i < grafo.size(); i++){
                cout << "Nodo " << i << "-> ";
                for(size_t j = 0; j < grafo[i].size(); j++){
                    cout << grafo[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int n;
    cout << "Quanti nodi vuoi inserire?: " << endl;
    cin >> n;
    Grafo g(n);
    int m;
    cout << "Quanti archi vuoi inserire?: " << endl;
    cin >> m;
    for(int i = 0; i < m; i++){
        int n, m;
        cout << "Inserisci il vertice di partenza e il vertice di arrivo: " << endl;
        cin >> n >> m;
        g.aggiungiArco(n, m);
    }
    g.stampaGrafo();
    return 0;
}
