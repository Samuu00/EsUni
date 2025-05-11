#include <iostream>
#include <vector>
using namespace std;


//es1
template <typename t>
class Pila{
    private:
        int maxSize;
        int size;
        t* elementi;

    public:
        Pila(){
            this->maxSize = 100;
            this->size = 0;
            this->elementi = new t[this->maxSize];
        }

        int getSize(){
            return size;
        }

        void push(t& elem){
            if(size == 0){
                elementi[0] = elem;
                size++;
                return;
            }
            elementi[size] = elem;
            size++;    
        }
};
class PilaConMoltiplicazione : public Pila{
    public:
        void moltiplica(int& fattore){
            for(int i = 0; i < getSize(); i++){
                elementi[i] *= fattore;
            }
        }
};


//es2
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;

    public:
        Grafo(int n){
            this->n = n;
            grafo.resize(n);
        }
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }

        void camminoSenzaVietati(int p, int a, vector<bool>& visitato, vector<int>& vietati){
            for(int s : vietati){
                if(s == p) return false;
            }

            if(p == a) return true;

            visitato[p] = true;
            for(int v : grafo[p]){
                if(visitato[v]) continue;
                if(camminoSenzaVietati(v, a, visitato, vietati)) return true;
            }
            return false;
        }
};


