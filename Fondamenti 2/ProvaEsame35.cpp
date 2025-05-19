#include <iostream>
#include <map>
#include <vector>
using namespace std;


//es1
class centroVaccinale{
    private:
        map<string, vector<pair<string, unsigned>>> registro;

    public:
        void registraVaccinazione(string& cf, string& vaccino, unsigned& data){
            registro[cf].push_back({vaccino, data});
        }
        vector<string> vaccinoSomministrati(string& cf){
            vector<string> somm;
            for(auto& v : registro[cf]){
                somm.push_back(v.first);
            }
            return somm;
        }
        string ultimoSomm(string& cf){
            unsigned dataRec = 0;
            string ult = "";
            for(auto& v : registro[cf]){
                if(v.second > dataRec){
                    dataRec = v.second;
                    ult = v.first;
                }
            }
            return ult;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

int altAlb(nodo* root){
    if(root == nullptr) return 0;

    return 1 + (max(altAlb(root->sinistro), altAlb(root->destro)));
}

bool bilanciato(nodo* root){
    if(root == nullptr) return true;

    int altSin = altAlb(root->sinistro);
    int altDest = altAlb(root->destro);

    if(abs(altSin - altDest) > 1) return false;
    return bilanciato(root->sinistro) && bilanciato(root->destro);
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

        bool raggiungibiliInOrdine(int p, vector<bool>& visitato, vector<int>& percorsi, unsigned i){
            if(i == percorsi.size() - 1) return true;
            visitato[p] = true;
            for(int v : grafo[p]){
                if(visitato[v]) continue;
                if(v == percorsi[i]){
                    if(raggiungibiliInOrdine(v, visitato, percorsi, i + 1)) return true;
                }
            }
            visitato[p] = false;
            return false;
        }
};


