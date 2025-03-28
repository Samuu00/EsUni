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

        void contaConnessioni(){
            vector<bool> visitato(n, false);
            int connessioni = 0;

            for(int i = 0; i < n; i++){
                if(!visitato[i]){
                    stack<int> s;
                    s.push(i);
                    visitato[i] = true;
                    while(!s.empty()){
                        int u = s.top();
                        s.pop();

                        for(int v : grafo[u]){  
                            if(!visitato[v]){ 
                                visitato[v] = true;
                                s.push(v);
                            }
                        }
                    }
                    connessioni++;
                }
            }
            cout << "Il grafo ha " << connessioni << " connessioni." << endl;
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
        cout << "Inserire l'arco " << i+1 << ": ";
        cin >> u >> v;
        g.aggiungiArco(u, v);
    }

    g.stampaGrafo();
    g.contaConnessioni();
    
    return 0;
}
