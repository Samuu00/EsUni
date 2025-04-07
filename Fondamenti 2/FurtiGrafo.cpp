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
    }

    bool furti(vector<int>& v, int s, int k, int w) {
        vector<bool> visitato(n, false);
        stack<int> stack;
        stack.push(s);
        int sommaBottini = 0;
        int contk = 0;

        while (!stack.empty()) {
            int nodo = stack.top();
            stack.pop();

            for (int vicino : grafo[nodo]) {
                if (!visitato[vicino]) {
                    visitato[vicino] = true;
                    stack.push(vicino);
                    sommaBottini += v[nodo];
                    contk++;
                    if (contk >= k && sommaBottini == w) {
                        return true;
                    }
                }
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

int main() {
    int n, m;
    cout << "Inserisci numero nodi del grafo: " << endl;
    cin >> n;
    Grafo g(n);
    cout << "Inserisci numero archi: " << endl;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Inserisci nodo di partenza e arrivo: " << endl;
        cin >> u >> v;
        g.aggiungiArco(u, v);
    }
    vector<int> v(n);
    cout << "Leggi bottini: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int s, k, w;
    cout << "Leggi condizioni di s(partenza), k(numero furti), w(somma bottino): " << endl;
    cin >> s >> k >> w;

    g.stampaGrafo();
    cout << (g.furti(v, s, k, w) ? "True" : "False") << endl;

    return 0;
}
