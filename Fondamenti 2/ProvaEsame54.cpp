#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


//es1
struct letture{
    string nomeSens;
    string ambiente;
    double valore;
    bool anomalia;

    letture(string nS, string amb, double val, bool an) : nomeSens(nS), ambiente(amb), valore(val), anomalia(an) {};
};
class monitoraggioSensori{
    private:
        int maxSize;
        int size;
        letture* dati;
    
    public:
        monitoraggioSensori(){
            this->maxSize = 100;
            this->size = 0;
            this->dati = new letture[this->maxSize];
        }

        void aggiungiLett(string nomeSens, string ambiente, double valore, bool anomalia){
            if(size == maxSize){
                maxSize += 100;
                letture* nuovo = new letture[maxSize];
                for(int i = 0; i < size; i++){
                    nuovo[i] = dati[i];
                }
                delete[] dati;
                dati = nuovo;
            }
            dati[size] = letture(nomeSens, ambiente, valore, anomalia);
            size++;
        }

        map<string, double> mediaValoriAmbiente(){
            map<string, double> mediaAmb;
            map<string, int> freq;
            for(int i = 0; i < size; i++){
                if(!dati[i].anomalia){
                    freq[dati[i].ambiente]++;
                    mediaAmb[dati[i].ambiente] += dati[i].valore;
                }
            }
            for(auto& it : media){
                media[it.first] = media[it.first] / freq[it.first];
            }
            return mediaAmb;
        }

        vector<string> sensoriNanomalie(int n){
            vector<string> sensori;
            map<string, int> freqAnom;
            for(int i = 0; i < size; i++){
                if(dati[i].anomalia){
                    freqAnom[dati[i].nomeSens]++;
                }
            }
            for(auto& it : freqAnom){
                if(it.second > n){
                    sensori.push_back(it.first);
                }
            }
            return sensori;
        }
};

//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void riempiVett(nodo* root, vector<int>& somme, int somma, bool sinistro){
    if(root == nullptr) return;
    
    somma += root->val;

    if(root->sinistro == nullptr && root->destro == nullptr){
        if(sinistro){
            somme[0] += somma;
        }else{
            somme[1] += somma;
        }
    }

    riempiVett(root->sinistro, somme, somma, sinistro);
    riempiVett(root->destro, somme, somma, sinistro);
}

vector<int> sommaSinDest(nodo* root){
    vector<int> somme(2, 0);
    if(root->sinistro) riempiVett(root->sinistro, somme, 0, true);
    if(root->destro) riempiVett(root->destro, somme, 0, false);

    return somme;
}


//es3
class Grafo{
    private:
        int n;
        vector<vector<pair<int, int>>> grafo;

    public:
        Grafo(int n){
            this->n = n;
            grafo.resize(n);
        }
        void aggiungiArco(int u, int v, int peso){
            grafo[u].push_back({v, peso});
        }

        void findPaths(int p, int a, vector<bool>& visitato, int somma, int& mass, int m){
            if(p == a) mass = max(mass, somma);
            visitato[p] = true;
            for(pair<int, int> v: grafo[p]){
                int nodo = v.first;
                int peso = v.second;
                if(visitato[nodo] || peso % m != 0) continue;
                findPaths(nodo, a, visitato, somma + peso, mass, m);
            }
            visitato[p] = false;
        }

        int maxOttenibileM(int p, int a, int m){
            vector<bool> visitato(n, false);
            int massimo = -1;
            findPaths(p, a, visitato, 0, massimo, m);
            return massimo;
        }
};



