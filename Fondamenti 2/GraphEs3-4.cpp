#include <iostream>
#include <vector>
#include <queue>
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
                adj[j][i] = true;
                numArchi++;
            }
        }

        pair<int, int> esercizio3(){
            float maxx = INT_MIN;
            pair<int, int> maxArco;
            vector<int> gNodi(n(), 0);

            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(adj[i][j]) gNodi[i]++;
                }
            }
            
            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(adj[i][j]){
                        float curr = ((w(i) * w(j)) / (gNodi[i] + gNodi[j]));
                        if(curr > maxx){
                            maxx = curr;
                            maxArco = {i, j};
                        }
                    }
                }
            }
            return maxArco;
        }
        
        //qui uso lista di adiacenza, più comodo
        bool dfs(int i, vector<bool>& visitato, int k){
            visitato[i] = true;
            if(i == g() - 1 && k == 0) return true;
            for(int v : grafo[i]){
                if(visitato[v]) continue;
                if(dfs(v, visitato, k - 1)) return true;
            }
            visitato[i] = false;
            return false;
        }

        bool esercizio4(int k){
            vector<bool> visitato(n(), false);
            if(dfs(0, visitato, k)){
                return true;
            }else{
                return false;
            }
        }
}; 