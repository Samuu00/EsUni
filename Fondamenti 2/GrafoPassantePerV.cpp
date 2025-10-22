#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n, vector<int> p) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

        int n() const {
            return numNodi;
        }
        int m() const {
            return numArchi;
        }

        void aggiungiArco(int i, int j) {
            if (i < 0 || j < 0 || i >= numNodi || j >= numNodi) throw out_of_range("Indice nodo non valido");
            if (!adj[i][j]) {
                adj[i][j] = true;
                numArchi++;
            }
        }

        bool bfsMinPath(int p, int a, unordered_map<int, vector<int>>& paths){
            vector<bool> visitati(n(), false);
            queue<int> q;

            q.push(p);
            visitati[p] = true;
            paths[p].push_back(p);

            while(!q.empty()){
                int curr = q.front(); q.pop();

                for(int v : adj[curr]){
                    if(visitati[v]) continue;
                    paths[v] = paths[curr];
                    paths[v].push_back(v);
                    if(v == a) return true;
                    visitati[v] = true;
                    q.push(v);
                }
            }
            return false;
        }

        vector<int> esercizio4(int c, int v, int b){
            unordered_map<int, vector<int>> paths1;
            unordered_map<int, vector<int>>paths2;

            vector<int> pathcv;
            vector<int> pathvb;
            
            if(bfsMinPath(c, v, paths1)){
                pathcv = paths1[v];
            }else{
                return {};
            };

            if(bfsMinPath(v, b, paths2)){
                pathvb = paths2[b];
            }else{
                return {};
            };

            pathvb.erase(pathvb.begin());

            pathcv.insert(pathcv.end(), pathvb.begin(), pathvb.end());

            return pathcv;
        }
}