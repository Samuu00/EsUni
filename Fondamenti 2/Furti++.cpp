#include <iostream>
#include <vector>
using namespace std;

class Grafo {
    private:
        int n;
        vector<vector<int>> adj;

    public:
        Grafo(int n){
            this->n = n;
            adj.resize(n);
        }
        void aggiungiArco(int u, int v){
            adj[u].push_back(v);
        }

        int Nodi(){
            return n;
        }

        bool isPossible(const vector<int>& bottini, vector<bool>& visitati, int k, int s, int w, int& tot){
            visitati[s] = true;
            tot += bottini[s];
            if(tot == w && k == 0) return true;

            for(int v : adj[s]){
                if(visitati[v]) continue;
                if(isPossible(bottini, visitati, k - 1, v, w, tot)) return true;
            }
            return false;
        }
};

int main(){
    Grafo g(6);

    g.aggiungiArco(0, 1);
    g.aggiungiArco(1, 2);
    g.aggiungiArco(2, 3);
    g.aggiungiArco(3, 5);

    vector<int> bottini = {2, 3, 6, 12, 5, 8};
    vector<bool> visitati(g.Nodi(), false);
    int k = 2, s = 0, w = 11, tot = 0;
    if(g.isPossible(bottini, visitati, k, s, w, tot)){
        cout<<"E' possibile";
    }else{
        cout<<"Errore";
    }

    return 0;
}