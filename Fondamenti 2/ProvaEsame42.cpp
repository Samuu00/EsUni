#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;


//es1
class centroConsegne{
    private:
        map<string , vector<pair<string, unsigned>> consegne;
    
    public:
        void registraConsegns(string& corriere, string& citta, unsigned& kmPerc){
            consegne[corriere].push_back(make_pair(citta, kmPerc));
        }
        unsigned totKmCorr(string& corriere){
            unsigned tot = 0;
            for(auto& c : consegne[corriere]){
                tot += c.second;
            }
            return tot;
        }
        map<string, unsigned> kmPerCitta(){
            map<string, unsigned> kmCorr;
            for(auto& c : consegne){
                unsigned kmCorrMedia = 0
                for(auto& cons : c.second){
                    kmCorrMedia += cons.second;
                }
                kmCorrMedia /= c.second.size();
                kmCorr[c.first] = kmCorrMedia;
            }
            return kmCorr;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v): val(v), sinistro(nullptr), destro(nullptr){}
};

bool camminoPariMult5(nodo* root, int prec, int somma){
    if(root == nullptr) return false;

    somma += root->val;
    if(root->val % 2 != 0) return false;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return somma % 5 == 0;
    }

    return camminoPariMult5(root->sinistro, prec, somma) || camminoPariMult5(root->destro, prec, somma);
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
        bool camminoKconObbl(int p, int a, int k, int m, unordered_set<int> obbl, int cont){
            if(obbl.count(p)) cont++;
            if(u == v){
                if(k == 0 && cont >= m) return true;
            }
            for(int v : grafo[p]){
                if(camminoKconObbl(v, a, k-1, m, obbl, cont))
            }
            return false;
        }
};