#include <iostream>
#include <vector>
using namespace std;

//es1
class Contenitore{
    public: 
        virtual void aggiungi(int n) = 0;
        virtual int estrai(int n) = 0;
        virtual ~Contenitore(){}
};

class Pila : public virtual Contenitore{
    private:
        int n;
        vector<int> pila;
    public:
        Pila(int n){
            this->n = n;
            pila.resize(n);
        }
        void aggiungi(int n) override{
            pila.push_back(n);
        }
        int estrai(int n) override{
            int estrai = 0;
            for(int i : pila){
                if(i == n){
                    estrai = i;
                    pila.erase(pila.begin() + i);
                    return estrai;
                }
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
        bool esistePercorso3Archi(int u, int v, vector<bool>& visitato, int cont){
            if(u == v && cont == 3) return true;
            visitato[u] = true;
            for(int i : grafo[u]){
                if(visitato[i]) continue;
                if(esistePercorso3Archi(i, v, visitato, cont + 1)) return true;
            }
            visitato[u] = false;
            return false;
        }
};
