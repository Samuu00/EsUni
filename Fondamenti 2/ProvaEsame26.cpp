#include <iostream>
using namespace std;

struct nodo{
    int val;
    nodo* sinistro;
    ­nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void inserisci(nodo* root, int v){
    if(root == nullptr) return new nodo(v);

    if(v < root->val){
        root->sinistro = inserisci(root->sinistro, v);
    }else if(v > root->val){
        root->destro = inserisci(root->destro, v);
    }
    return root;
}

bool cerca(nodo* root, int& v){
    if(root == nullptr) return false;

    if(root->val == v) return true;

    return cerca(root->sinistro, v) || cerca(root->destro, v);
}

int altezzaAlb(nodo* root){
    if(root == nullptr) return 0;

    return 1 + max(altezzaAlb(root->sinistro), altezzaAlb(root->destro));
}

int sommaFoglie(nodo* root){
    if(root == nullptr) return 0;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return root->val;
    }
    return sommaFoglie(root->sinistro) + sommaFoglie(root->destro);
}


class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;

    public:
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }
        bool esisteCammino(int u, int v, vector<bool>& visitato){
            if(u == v) return true;
            visitato[u] = true;
            for(int i : grafo[u]){
                if(visitato[i]) continue;
                if(esisteCammino(i, v, visitato)) return true;
            }
            return false;
        }
};