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


//es4
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
                adj[j][i] = true;
                numArchi++;
            }
        }

        void controllaCitta(int& k, vector<bool>& citta){
            vector<vector<int>> controlli(n());
            vector<int> fazioneT;
            vector<int> fazioneF;

            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){

                    if(adj[i][j] && i != j){

                        if(citta[i] && !citta[j]){
                            controlli[i].push_back(j);
                            fazioneT.push_back(i);
                            fazioneF.push_back(j);
                        } 
                    }
                }
            }

            if(fazioneT.size() < k){
                cout<< "IMPOSSIBILE" << endl;
                return;
            } 


            vector<int> scelti;
            if(cercaCombin(0, k, scelti, fazioneT, fazioneF, controlli)){

                for(int s : scelti) cout<< s << " ";
                cout<< endl;

            }else{

                cout<< "IMPOSSIBILE";
            }
        }


        bool cercaCombin(int index, int k, vector<int>& scelti, vector<int>& fazioneT, vector<int>& fazioneF, vector<vector<int>> controlli){
            if(scelti.size() == k){

                vector<bool> visitati(n(), false);

                for(int pos : scelti){

                    for(int nemico : controlli[pos]){

                        visitati[nemico] = true;
                    }
                }

                for(int nemico : fazioneF){

                    if(!visitati[nemico]) return false;
                }

                return true;
            }


            if(index == fazioneT.size()) return false;

            scelti.push_back(fazioneT[index]);
            if(cercaCombin(index + 1, k, scelti, fazioneT, fazioneF, controlli)) return true;
            scelti.pop_back();

            if(cercaCombin(index + 1, k, scelti, fazioneT, fazioneF, controlli)) return true;


            return false;
        }
};
