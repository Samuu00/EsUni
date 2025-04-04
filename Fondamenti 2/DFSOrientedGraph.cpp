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

        void dfs(int n){
            vector<bool> visitato(n, false);
            stack<int> pila;
            visitato[n] = true;
            pila.push(n);

            while(!pila.empty()){
                int nodo = pila.top();
                pila.pop();
                for(int i : grafo[nodo]){
                    if(!visitato[i]){
                        visitato[i] = true;
                        pila.push(i);
                    }
                }
                cout << nodo << " ";
            }
            cout << endl;
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
    cout << "Inserire il numero di nodi e di archi: ";
    cin >> n >> m;
    Grafo g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.aggiungiArco(u, v);
    }
    g.stampaGrafo();
    int nodo;
    cout << "Inserire il nodo da cui iniziare la visita: ";
    cin >> nodo;
    g.dfs(nodo);
    return 0;
}
