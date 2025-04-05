#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Grafo{
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

        bool hasCycle() {
            vector<bool> visitato(n, false);
            stack<int> pila;
            for(int i = 0; i < n; i++){
                visitato[i] = true;
                pila.push(i);
                while(!pila.empty()){
                    int nodo = pila.top();
                    pila.pop();
                    for(int adiacente : grafo[nodo]){
                        if(adiacente >= n){
                            return false;
                        }else{
                            if(!visitato[adiacente]){
                                visitato[adiacente] = true;
                                pila.push(adiacente);
                            }
                            else if(visitato[adiacente]){
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        }


        void stampaGrafo(){
            for(int i = 0; i < n; i++){
                cout << "Nodo " << i << ": ";
                for(int j : grafo[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int n, m;
    cout << "Inserisci il numero di nodi e archi: ";
    cin >> n >> m;
    Grafo g(n);
    cout << "Inserisci gli archi (u v):" << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.aggiungiArco(u, v);
    }
    
    cout << "\nStruttura del grafo:" << endl;
    g.stampaGrafo();

    cout << "\nIl grafo contiene un ciclo? " << (g.hasCycle() ? "Si" : "No") << endl;
    return 0;
}
