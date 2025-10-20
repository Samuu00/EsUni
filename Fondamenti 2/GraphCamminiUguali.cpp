#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
        
        int bfs(int p, int a){ 
            vector<bool> visitati(n(), false);
            vector<int> lunghCamm(n(), 0);
            queue<int> q;

            q.push(p);
            visitati[p] = true; 

            while(!q.empty()){
                int curr = q.front(); q.pop();

                if(curr == a) return lunghCamm[curr];

                for(int v : adj[curr]){
                    if(visitati[v]) continue;
                    lunghCamm[v] = lunghCamm[curr] + 1;
                    visitati[v] = true;
                    q.push(v);
                }
            }
            return -1;
        }

        vector<int> bfsMinPath(int p, int a){
            map<int, vector<int>> paths;
            vector<bool> visitati(n(), false);
            queue<int> q;

            q.push(p);
            visitati[p] = true;
            paths[p].push_back(p);

            while(!q.empty()){
                int curr = q.front(); q.pop();

                if(curr == a) return paths[a];

                for(int v : adj[curr]){
                    if(visitati[v]) continue;
                    paths[v] = paths[curr];
                    paths[v].push_back(v);
                    visitati[v] = true;
                    q.push(v);
                }
            }
            return {};
        }

        vector<int> esercizio3(int u, int v){
            vector<int> nodi;
            for(int i = 0; i < n(); i++){
                int a = bfs(u, i);
                int b = bfs(i, v);
                if(a == b && (a != -1 && b != -1)) nodi.push_back(i);
            }
            return nodi;
        }
};