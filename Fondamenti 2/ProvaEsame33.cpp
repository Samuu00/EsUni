#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;


//es1
class archivioFilm{
    private:
        map<pair<string, string>, vector<int>> film;
    
    public:
        void aggiungi(string titolo, string regista, int voto){
            film[{titolo, regista}].push_back(voto);
        }
        double mediaVoti(string& titolo, string& regista){
            double media = 0.0;
            if(film.find({titolo, regista}) != film.end()){
                media += accumulate(film[{titolo, regista}].begin(), film[{titolo, regista}].end());
            }
            return media / film[{titolo, regista}].size();
        }
        vector<string> mediaSopraSoglia(double soglia){
            vector<string> filmSopraSoglia;
            for(auto& [titolo, regista] : film){
                double media = mediaVoti(titolo, regista);
                if(media > soglia){
                    filmSopraSoglia.push_back(titolo);
                }
            }
            return filmSopraSoglia;
        }

};


//es2
struct nodo{
    string par;
    nodo* sinistro;
    nodo* destro;

    nodo(string p): par(p), sinistro(nullptr), destro(nullptr){}
};

void accumulaParole(nodo* root, vector<string>& parole){
    if(root == nullptr) return;

    parole.push_back(root->par);

    accumulaParole(root->sinistro, parole);
    accumulaParole(root->destro, parole);
}

int contaPref(nodo* root, string pref){
    int conta = 0;
    vector<string> par;
    accumulaParole(root, par);
    for(auto& p : par){
        if(p.size() >= pref.size() && p.substr(0, pref.size()) == pref) conta++;
    }
    return conta;
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
        bool percorsoConNodi(int p, vector<bool>& visitato, vector<int>& richiesti, unordered_set<int>& SetRichiesti, int& cont){
            if(cont == richiesti.size()) return true;
            visitato[p] = true;
            if(SetRichiesti.count(p)) cont++;
            for(auto& v : grafo[p]){
                if(visitato[v]) continue;
                if(percorsoConNodi(v, visitato, richiesti, SetRichiesti, cont)) return true;
            }
            visitato[p] = false;
            if(SetRichiesti.count(p)) cont--;
            return false;
        }

};