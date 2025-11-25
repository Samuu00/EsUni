#include <iostream>
#include <vector>
using namespace std;

//es2
class Rotcev : private vector<int> {
    public:
        Rotcev(): vector<int>() {}

        int& operator[](int i){
            return vector<int>::at(this->size() - i - 1);
        }

        void push_back(int value){
            vector<int>::push_back(value);
        }

        int front() const {
            return vector<int>::back();
        }

        int back() const {
            return vector<int>::front();
        }

        unsigned size() const {
            return vector<int>::size();
        }
};


//es3
class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

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

        bool dfs(int x, int p, vector<bool>& visitati){
            visitati[x] = true;

            if(adj[x][p]) return true;

            for(int i = 0; i < n(); i++){

                if(adj[x][i] && !visitati[i]){

                    if(dfs(i, p, visitati)) return true;
                }
            }

            return false;
        }


        bool camminoX(int x){
            vector<bool> visitati(n(), false);

            if(dfs(x, x, visitati)) return true;

            return false;
        }
};
