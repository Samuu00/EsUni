#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;


//es1
class gestioneProgetti{
    private:
        map<string, vector<pair<string, unsigned>>> progetti;
    
    public:
        void assegnaProg(string& dipendente, string& progetto, unsigned& ore){
            progetti[progetto].push_back(make_pair(dipendente, ore));
        }
        unsigned oreDipendente(string& dipendente){
            unsigned oreDip = 0;
            for(auto& progetto : progetti){
                for(auto& dip : progetto.second){
                    if(dip.first == dipendente) oreDip += dip.second;
                }
            }
            return oreDip;
        }
        map<string, unsigned> oreDipendentiProgetto(){
            map<string, unsigned> orepProg;
            for(auto& progetto : progetti){
                auto& it = progetto.first;
                for(auto& dip : progetto.second){
                    orepProg[it] += dip.second;
                }
            }
            return orepProg;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool percorsoDecrePari(nodo* root, int prec, int somma){
    if(root == nullptr) return false;

    somma += root->val;

    if(root->val >= prec) return false;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return somma % 2 == 0;
    }

    return percorsoDecrePari(root->sinistro, root->val, somma) || percorsoDecrePari(root->destro, root->val, somma);
}


//es3
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
        bool camminoVincolato(int p, int a, int maxPassi, unordered_set<int>& obbl, unsigned cont){
            if(obbl.count(p)) cont++;
            if(p == a){
                if(cont == obbl.size() && maxPassi == 0) return true;
            }
            for(int v : grafo[p]){
                if(camminoVincolato(v, a, maxPassi - 1, obbl, cont)) return true;
            }
            return false;
        }
};