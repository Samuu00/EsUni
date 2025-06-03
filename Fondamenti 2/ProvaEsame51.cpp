#include <iostream>
#include <map>
#include <vector>
using namespace std;


//es1
struct appello{
    string matricola;
    string nome;
    unsigned voto;
    bool passato;
};
class registroAppelli{
    private:
        int maxSize;
        int size;
        appello* registro;
    
    public:
        registroAppelli(){
            this->maxSize = 50;
            this->size = 0;
            this->registro = new appello[this->maxSize];
        }
        ~registroAppelli(){
            delete[] registro;
        }

        void registraAppello(string mat, string nome, unsigned voto){
            if(size == maxSize){
                maxSize += 50;
                appello* nuovo = new appello[maxSize];
                for(int i = 0; i < size; i++){
                    nuovo[i] = registro[i];
                }
                delete[] registro;
                registro = nuovo;
            }

            registro[size].matricola = mat;
            registro[size].nome = nome;
            registro[size].voto = voto;
            if(voto >= 18){
                registro[size].passato = true;
            }else{
                registro[size].passato = false;
            }
            size++;
        }

        map<string, double> mediaEsamiSuperati(){
            map<string, double> media;
            map<string, int> freqPass;
            for(int i = 0; i < size; i++){
                if(registro[i].passato){
                    freqPass[registro[i].esame]++;
                    media[registro[i].esame] += registro[i].voto;
                }
            }
            for(auto& it : media){
                it.second = it.second / freqPass[it.first];
            }
            return media;
        }

        vector<string> studentiBocc(){
            vector<string> bocc;
            for(int i = 0; i < size; i++){
                if(!registro[i].passato) bocc.push_back(registro[i].matricola);
            }
            return bocc;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void contaValoriPerProfondita(nodo* root, map<int, int>& conta, int livello){
    if(root == nullptr) return;

    conta[livello]++;

    contaValoriPerProfondita(root->sinistro, conta, livello + 1);
    contaValoriPerProfondita(root->destro, conta, livello + 1);
}

map<int, int> ritornaMap(nodo* root){
    map<int, int> contaPerLiv;
    contaValoriPerProfondita(root, contaPerLiv, 0);
    return contaPerLiv;
}

void foglieSommaPercorso(nodo* root, map<int, vector<int>>& somme, int somma){
    if(root == nullptr) return;

    somma += root->val;

    if(root->sinistro == nullptr && root->destro == nullptr){
        somme[somma].push_back(root->val);
    }

    foglieSommaPercorso(root->sinistro, somme, somma);
    foglieSommaPercorso(root->destro, somme, somma);
}

map<int, vector<int>> popolaMap(nodo* root){
    map<int, vector<int>> sommaPerc;
    foglieSommaPercorso(root, sommaPerc, 0);
    return sommaPerc;
} 

//es3
class Grafo{
    private:
        int n;
        vector<vector<pair<int, int>>> grafo;
    
    public:
        void aggiungiArco(int u, int v, int p){
            grafo[u].push_back({v, p});
        }  

        int maxValorePercorso(int p, int a, int max, int maxPassi, vector<bool>& visitato){
            if(p == a) return max;
            if(maxPassi == 0) return -1;

            visitato[p] = true;
            for(pair<int, int> v : grafo[p]){
                int nodo = v.first;
                int peso = v.second;
                if(visitato[nodo]) continue;
                int nuovoMax = max(max, peso);
                int valore = maxValorePercorso(nodo, a, nuovoMax, maxPassi - 1, visitato);
            }
            if(valore != -1){
                risultato = max(risultato, valore);
            }
            visitato[p] = false;
            return -1;
        }

        int numPercorsiDecr(int p, int a, int prec){
            if(p == a) return 1;
            int cont = 0;
            for(pair<int, int> v : grafo[p]){
                int nodo = v.first;
                int peso = v.second;
                if(peso < prec) cont += numPercorsiDecr(nodo, a, peso);
            }
            return cont;
        }
};


