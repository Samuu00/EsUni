#include <iostream>
#include <vector>
using namespace std;


class vettorePazzo : protected vector<unsigned>{
    private:
        unsigned nPazzo;
    
    public:
        vettorePazzo(int n){
            nPazzo = n;
        }

        void addNumber(unsigned n){
            if(n == nPazzo || n % nPazzo == 0) return;

            this->push_back(n);
        }

        unsigned operator[](int index){
            if(this->size() % nPazzo == 0) return 0;
            
            if(index < 0){
                if(abs(index) > this->size()) return this->at(0);
                if(abs(index) < this->size()) return this->at(this->size() - index);
                if(abs(index) > this->size()) return this->at(index);
                if(abs(index) > this->size()) return this->at(this->size());
            }

            return this->at(index);
        }

        bool operator==(vettorePazzo& other){
            return true;
        }

        bool operator<(vettorePazzo& other){
            if(nPazzo < other.nPazzo) return true;
            return false;
        }
};

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

        vector<pair<int, int>> is_Sovrapp(){
            vector<pair<int, int>> nodi;

            for(int i = 0; i < n(); i++){
                for(int j = i + 1; j < n(); j++){
                    
                    bool yes = true;
                    for(int k = 0; k < n(); k++){
                        if(adj[k][i] != adj[k][j]){
                            yes = false;
                            break;
                        }
                    }

                    if(yes){
                        for(int k = 0; k < n(); k++){
                            if(adj[i][k] != adj[j][k]){
                                yes = false;
                                break;
                            }
                        }
                    }

                    if(yes) nodi.push_back({i, j});
                }
            }
            return nodi;
        }
};