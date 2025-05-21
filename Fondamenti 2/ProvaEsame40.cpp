#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;


//es1
class registroPagamenti{
    private:
        map<string, vector<pair<string, double>>> registroSpesa;

    public:
        void aggiungiPagamento(string& cliente, string& categ, double& prezzo){
            registroSpesa[cliente].push_back(make_pair(categ, prezzo));
        }
        double totaleUtente(string& cliente){
            double tot = 0;
            for(auto& s : registroSpesa[cliente]){
                tot += s.second;
            }
            return tot;
        }
        map<string, double> spesaPerCateg(){
            map<string, double> spesaPerCategoria;
            for(auto& utente : registroSpesa){
                for(auto& s : utente.second){
                    spesaPerCategoria[s.first] += s.second;
                }
            }
            return spesaPerCategoria;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool esistePercorsoSommaAlternata(nodo* root, int sommaPari, int sommaDispari, int livello){
    if(root == nullptr) return false;

    if(livello % 2 == 0) sommaPari += root->val;
    if(livello % 2 != 0) sommaDispari += root->val;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return sommaPari == sommaDispari;
    }

    return esistePercorsoSommaAlternata(root->sinistro, sommaPari, sommaDispari, livello + 1) || esistePercorsoSommaAlternata(root->destro, sommaPari, sommaDispari, livello + 1);
}


//es3
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;
    
    public:
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }  

        bool esistePercorsoLungoKconObblSenzaViet(int p, int a, int k, unordered_set<int>& vietati, unordered_set<int>& obbl, vector<bool>& visitato, int cont){
            if(vietati.count(p)) return false;
            if(obbl.count(p)) cont++;
            if(p == a && k == 0){
                if(cont == obbl.size()) return true;
            }
            visitato[p] = true;
            for(int v : grafo[p]){
                if(visitato[v]) continue;
                if(esistePercorsoLungoKconObblSenzaViet(v, a, k - 1, vietati, obbl, visitato, cont)) return true;
            }
            visitato[p] = false;
            if(obbl.count(p)) cont--;
            return false;
        }
};