#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <unordered_set>
using namespace std;

//es1
struct oggetto{
    string nome;
    string categoria;
    double peso;
    bool stato;
};
class storicoOgg{
    private:
        int maxSize;
        int size; 
        oggetto* storico;
    
    public:
        storicoOgg(){
            this->maxSize = 100;
            this->size = 0;
            this->storico = new oggetto[this->maxSize];
        }
        ~storicoOgg(){
            delete[] storico;
        }

        void aggiungiOgg(string nome, string categoria, double peso){
            if(size == maxSize){
                maxSize += 100;
                oggetto* newStorico = new oggetto[maxSize];
                for(int i = 0; i < size; i++){
                    newStorico[i] = storico[i];
                }
                delete[] storico;
                storico = newStorico;
            }

            storico[size].nome = nome;
            storico[size].categoria = categoria;
            storico[size].peso = peso;
            storico[size].stato = true;
            size++;
        }

        void rimuoviOgg(string nome){
            for(int i = 0; i < size; i++){
                if(storico[i].nome == nome) storico[i].stato = false;
            }
        }

        double pesoAttiviCat(string categoria){
            double pesoCat = 0.0;
            for(int i = 0; i < size; i++){
                if(storico[i].categoria == categoria && storico[i].stato == true) pesoCat += storico[i].peso;
            }
            return pesoCat;
        }

        map<string, int> conteggioAttCat(){
            map<string, int> conteggio;
            for(int i = 0; i < size; i++){
                if(storico[i].stato == true) conteggio[storico[i].categoria]++;
            }
            return conteggio;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool sommaPercorsoFincheZero(nodo* root, int sommaRichiesta){
    if(root == nullptr) return false;

    sommaRichiesta -= root->val;

    if(root->val == 0){
        return sommaRichiesta == 0;
    }

    return sommaPercorsoFincheZero(root->sinistro, sommaRichiesta) || sommaPercorsoFincheZero(root->destro, sommaRichiesta);
}

int sommaMassimiPercorso(nodo* root, int maxCorrente, bool valido){
    if(root == nullptr) return 0;

    if(root->val > maxCorrente) maxCorrente = root->val;

    if(root->val % 2 != 0) valido = false;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return valido ? maxCorrente : 0;
    };

    return sommaMassimiPercorso(root->sinistro, maxCorrente, valido) + sommaMassimiPercorso(root->destro, maxCorrente valido);
}

//
bool findPaths(nodo* root, int val, vector<nodo*>& path){
    if(root == nullptr) return false;

    path.push_back(root);
    if(root->val == val) return true;

    if(root->sinistro != nullptr && findPaths(root->sinistro, val, path) || root->destro != nullptr && findPaths(root->destro, val, path)) return true;

    path.pop_back();
    return false;
}

nodo* LCA(nodo* root, int a, int b){
    vector<nodo*> path1, path2;

    if(!findPaths(root, a, path1) || !findPaths(root, b, path2)) return nullptr;

    int i = 0;
    while(i < path1.size() && i < path2.size() && path1[i] == path2[i]){
        i++;
    }
    return path1[i-1];
}
//

int maxDiffTraFoglieSimm(nodo* root1, nodo* root2){
    if(root1 == nullptr || root2 == nullptr) return 0;

    if(root1->sinistro == nullptr && root1->destro == nullptr && root2->sinistro == nullptr && root2->destro == nullptr){
        return (abs(root1->val - root2->val));
    }

    int diffSin = 0, diffDest = 0;

    if(root1->sinistro != nullptr && root2->destro != nullptr){
        diffSin = maxDiffTraFoglieSimm(root1->sinistro, root2->destro);
    }
    if(root1->destro != nullptr && root2->sinistro != nullptr){
        diffDest = maxDiffTraFoglieSimm(root1->destro, root2->sinistro);
    }

    return max(diffSin, diffDest);
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

        bool camminoAlternatoObbl(int p, int a, const unordered_set<int>& obbl, int cont, vector<bool>& visitato){
            if(obbl.count(p)) cont++;
            if(p == a){
                if(cont == obbl.size()) return true;
            }
            visitato[p] = true;
            for(int s : grafo[p]){
                for(int v : grafo[s]){
                    if(visitato[v]) continue;
                    if(camminoAlternatoObbl(v, a, obbl, cont, visitato)) return true;
                }
            }
            if(obbl.count(p)) cont--;
            visitato[p] = false;
            return false;
        }
};