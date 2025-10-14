#include <iostream>
#include <vector>
using namespace std;

struct nodo{
    float val;
    nodo* sinistro;
    nodo* destro;

    nodo(float v) : val(v), sin(nullptr), destro(nullptr) {}
};

void racc(nodo* root, float& racc){
    if(root == nullptr) return 0;

    float valore = root->val;

    if(root->sinistro != nullptr){
        root->sinistro->val += valore / 2;
    }else{
        racc += valore / 2;
    }
    if(root->destro != nullptr){
        root->destro->val += valore / 2;
        
    }else{
        racc += valore / 2;
    }

    root->val = 0;

    racc(root->sinistro, racc);
    racc(root->destro, racc);
}
float raccolta(nodo* root){
    float racc = 0;
    racc(root, racc);
    return racc;
}


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

        void stampaPercorsoCiclo(int p, vector<bool>& visitato, vector<int> currentPath){
            currentPath.push_back(p);
            visitato[p] = true;
            for(int v : grafo[p]){
                if(currentPath.size() > 1 && v == currentPath[0]){
                for(int i : currentPath){
                    cout<< i <<;
                }
                return;
            }
                if(visitato[v]) continue;
                stampaPercorsoCiclo(v, visitato, currentPath);
            }
            currentPath.pop_back();
            visitato[p] = false;
        }
};