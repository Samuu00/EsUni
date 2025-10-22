#include <list>
#include <map>
#include <queue>

//es2
class LRUCache {
    private:
        int capacita;
        int size;
        list<pair<int, int>> cache;
        map<int, list<pair<int, int>>::iterator> memory;


    public:
        LRUCache(int c): capacita(c), size(0) {};

        int get(int& chiave){
            auto it = memory.find(chiave);

            if(it != memory.end()){
                auto it_list = it.second;
                cache.splice(cache.begin(), cache, it.second);
                return it_list->second;
            }
            return -1;
        }

        void put(int chiave, int valore){
            auto it = memory.find(chiave);

            if(it != memory.end()){
                auto it_list = it.second;

                it_list->second = valore;

                cache.splice(cache.begin(), cache, it_list);
            }

            if(memory.size() == capacita){
                pair<int, int> back = cache.back();

                memory.erase(back.first);
                cache.pop_back();
            }

            cache.push_front({chiave, valore});
            memory[chiave] = cache.begin();
        }
};


//es3
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

        int bfs(int p, int a, vector<bool>& visitati, vector<int>& dist){
            queue<int> q;

            visitati[p] = true;
            q.push(p);

            while(!q.empty()){
                int curr = q.front(); q.pop();

                for(int i = 0; i < n(); i++){
                    if(adj[curr][i] && !visitati[i]){
                        dist[i] = dist[curr] + 1;
                        visitati[i] = true;
                        q.push(i);
                        if(i == a) return dist[i];
                    }
                }
            }
            return -1;
        }

        vector<int> trovaNodiCamminoMin(int u, int v){
            vector<int> nodi;
            vector<bool> visitati(n(), false);
            vector<int> dist(n(), 0);

            int distTot = bfs(u, v, visitati, dist);

            for(int i = 0; i < n(); i++){
                vector<bool> visitati(n(), false);
                vector<int> dist(n(), 0);
                
                int ux = bfs(u, i, visitati, dist);

                vector<bool> visitati(n(), false);
                vector<int> dist(n(), 0);

                int xv = bfs(i, v, visitati, dist);

                if(distTot == ux + xv) nodi.push_back(i);

            }
            return nodi;
        }
}