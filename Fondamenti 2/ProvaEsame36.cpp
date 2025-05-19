#include <iostream>
#include <map>
#include <vector>
using namespace std;


//es1
class bibliotecaDigitale{
    private:
        map<string, vector<pair<string, int>>> biblioteca;
    
    public:
        void aggiungiArt(string& autore, string& tit, int& anno){
            biblioteca[autore].push_back({tit, anno});
        }
        vector<string> artAut(string& autore){
            vector<string> art;
            for(auto& art : biblioteca[autore]){
                art.push_back(art.first);.
            }
        }
        string artPiuRec(){
            string titRec = "";
            int rec = 0;
            for(auto& b : biblioteca){
                for(auto& art : art.second){
                    if(art.second > rec){
                        rec = art.second;
                        titRec = art.first;
                    }
                }
            }
            return titRec;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool contieneSomma(nodo* root, int somma){
    if(root == nullptr) return false;

    somma -= root->val;
    if(root->sinistro == nullptr && root->destro == nullptr){
        return somma == 0;
    }

    return contieneSomma(root->sinistro, somma) || contieneSomma(root->destro, somma);
}

//es2alt
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool fogliePari(nodo* root){
    if(root == nullptr) return true;

    if(root->sinistro == nullptr && root->destro == nullptr){
        if(root->val % 2 != 0) return false;
    }

    return fogliePari(root->sinistro) && fogliePari(root->destro);
}

//es2alt1
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool esistePercorsoStrettCresc(nodo* root, int prec){
    if(root == nullptr) return true;

    if(root->val < prec) return false;

    return esistePercorsoStrettCresc(root->sinistro, root->val) || esistePercorsoStrettCresc(root->destro, root->val);
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

        bool esisteCamminoConSalto(vector<bool>& visitato, int u, int a, int k){
            if(u == v) return true;
            visitato[u] = true;
            for(int v : grafo[u]){
                if(visitato[u]) k - 1;
                if(k == 0) visitato[v] continue;
                if(esisteCamminoConSalto(visitato, v, a, k)) return true;
            }
            return false;
        }
};