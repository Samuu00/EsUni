#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Grafo {
    private:
        int numNodi;
        vector<vector<int>> adj;

    public:
        Grafo(int n) : numNodi(n), adj(n) {}

        int n() const {
            return numNodi;
        }

        void aggiungiArco(int i, int j) {
            adj[i].push_back(j);
        }

        void dfs(int u, vector<bool>& visitati, vector<vector<int>>& grafo) {
            visitati[u] = true;
            for (int v : grafo[u]) {
                if (!visitati[v]) {
                    dfs(v, visitati, grafo);
                }
            }
        }

        int esercizio3() {
            vector<int> ragg(n(), 0);
            vector<vector<int>> gT(n());

            for(int i = 0; i < n(); i++){
                for(int v : adj[i]){
                    gT[v].push_back(i);
                }
            }

            for(int i = 0; i < n(); i++){
                vector<bool> visitati(n(), false);

                dfs(i, visitati, gT);
                
                int cont = 0;
                for(int j = 0; j < n(); j++){
                    if(visitati[j]) cont++;
                }
                ragg[i] = cont;
            }

            int mNode = INT_MAX;
            int node = -1;
            for(int i = 0; i < n(); i++){
                if(ragg[i] < mNode){
                    mNode = ragg[i];
                    node = i;
                }
                if(ragg[i] == mNode){
                    node = min(node, i);
                }
            }
            return node;
        }

};