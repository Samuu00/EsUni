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
           grafo[v].push_back(u);
        }

        void controllaSeConnesso(){
           vector<bool> visitato(n, false);
           stack<int> s;
            for(int i = 0; i < n; i++){
                visitato[i] = true;
                s.push(i);
                while(!s.empty()){
                    int u = s.top();
                    s.pop();
                    for(int v : grafo[u]){
                        if(!visitato[v]){
                            visitato[v] = true;
                            s.push(v);
                            if(visitato[v] == true){
                                cout << "Il grafo e connesso" << endl;
                                return;
                            }
                        }
                    }
                }
            }
            cout << "Il grafo non e connesso" << endl;
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
    cout << "Inserire il numero di nodi: ";
    cin >> n;
    Grafo g(n);
    cout << "Inserire il numero di archi: ";
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cout<<"Inserire il nodo di partenza e il nodo di arrivo: ";
        cin >> u >> v;
        g.aggiungiArco(u, v);
    }
    g.stampaGrafo();
    g.controllaSeConnesso();
    return 0;
    
}
