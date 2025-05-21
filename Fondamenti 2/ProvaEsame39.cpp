#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;


//es1
class sistemaPrenotazioni{
    private:
        map<pair<string, string>, pair<int, pair<unsigned, unsigned>>> prenotazioni;
    
    public: 
        void aggiungiPrenotazione(string& cliente, string& sala, int& giorno, unsigned& oraArrivo, unsigned& oraSloggio){
            prenotazioni[{cliente, sala}] = {giorno, {oraArrivo, oraSloggio}};
        }

        bool salaLibera(string& sala, int& giorno, unsigned& inizio, unsigned& fine){
            for(auto& prenotazione : prenotazioni){
                if(prenotazione.first.second == sala && prenotazione.second.first == giorno && prenotazione.second.second.first >= inizio && prenotazione.second.second.second <= fine) return false;
            }
            return true;
        }

        map<string, unsigned> oraPerCliente(){
            map<string, unsigned> oraCliente;
            for(auto& prenotazione : prenotazioni){
                oraCliente[prenotazione.first.first] = prenotazione.second.second.second - prenotazione.second.second.first;
            }
            return oraCliente;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool percorsoMultipliAlterni(nodo* root, int prec){
    if(root == nullptr) return false;

    if(root->val % 2 == 0){
        if(prec % 2 == 0) return false;
    }
    if(root->val % 3 == 0){
        if(prec % 3 == 0) return false;
    }

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return percorsoMultipliAlterni(root->sinistro, root->val) || percorsoMultipliAlterni(root->destro, root->val);
};


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

        bool percorsoLungoKconIntermedi(int p, int a, int k, vector<bool>& visitato, unordered_set<int>& intermedi, int cont){
            if(intermedi.count(p)) cont++;
            if(p == a){
                if(k == 0 && cont == intermedi.size()) return true;
            }
            visitato[p] = true;
            for(auto& v : grafo[p]){
                if(visitato[v]) continue;
                if(percorsoLungoKconIntermedi(v, a, k - 1, visitato, intermedi, cont)) return true;
            }
            visitato[p] = false;
            if(intermedi.count(p)) cont--;
            return false;
        }
};