#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
using namespace std;

//es2
class NocList : private list<int> {
    public:
        NocList(): list<int>() {}

        void add(int value){
            auto it = list<int>::begin();
            while(it != list<int>::end()){

                if((*it) == value) return;

                it++;
            }

            it = list<int>::begin();
            while(it != list<int>::end() && (*it) < value){

                it++;
            }

            list<int>::insert(it, value);
        }

        int pop_max(){
            if(list<int>::empty()) throw runtime_error("Lista vuota");

            auto val = list<int>::back();
            list<int>::pop_back();

            return val;
        }

        int peek_min(){
            if(list<int>::empty()) throw runtime_error("Lista vuota");

            auto it = list<int>::begin();

            return (*it);
        }

        unsigned count(){
            return list<int>::size();
        }

        void print(){
            auto it = list<int>::begin();
            while(it != list<int>::end()){

                cout<< (*it) << " ";
                it++;
            }
        }
};

//es3
enum Direzione { SIN, DES };
class AlberoB {
    private:
        int info;  
        AlberoB* p;          
        AlberoB* sx;          
        AlberoB* dx;                 

    public:
        
        AlberoB(int valore) : info(valore),  p(nullptr), sx(nullptr), dx(nullptr) {}

        ~AlberoB() {
            delete sx; 
            delete dx;
        }

        AlberoB* figlio(Direzione dir) {
            if (dir == SIN) {
                return this->sx;
            }
            return this->dx;
        }

        AlberoB* padre() {
            return this->p;
        }

        int radice() {
            return this->info;
        }
 
        bool foglia() {
            return (this->sx == nullptr && this->dx == nullptr);
        }

        static bool nullo(AlberoB* a) {
            return a == nullptr;
        }

        bool zigZagSomma(AlberoB* a, int s, string dir){
            if(nullo(a)) return false;

            if(s <= 0) return false;
            
            int valore = s - a->radice();

            if(a->foglia() && s == 0) return true;

            if(dir == "start" || dir == "sin") if(zigZagSomma(a->figlio(DES), valore, "des")) return true;
            if(dir == "start" || dir == "des") if(zigZagSomma(a->figlio(SIN), valore, "sin")) return true;

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

        bool isSicuro(int u, vector<bool>& scelti){
            for(int i = 0; i < n(); i++){
                
                if(adj[u][i] && scelti[i]) return false;
            }

            return true;
        }

        bool costruisci(const vector<int>& costi, int budget, int k, int index, vector<bool>& scelti){
            if(k <= 0) return true;

            if(index == n()) return false;

            if(costi[index] <= budget && isSicuro(index, scelti)){

                scelti[index] = true;
                if(costruisci(costi, budget - costi[index], k - 1, index + 1, scelti)) return true;
                scelti[index] = false;
            }

            if(costruisci(costi, budget, k, index + 1, scelti)) return true; 

            return false;
        }

        bool costruisciSiti(const vector<int>& costi, int budget, int k){
            vector<bool> scelti(n(), false);

            if(costruisci(costi, budget, k, 0, scelti)) return true;
    
            cout<< "IMPOSSIBILE";
            return false;
        }
};
