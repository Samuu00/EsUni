#include <iostream>
#include <map>
#include <vector>
#include <unorderd_set>
#include <algorithm>
using namespace std;


//es1
struct prenotazione{
    string utente;
    string servizio;
    unsigned durata;
    bool completata;

    prenotazione(string u, string s, unsigned d, bool c){} : utente(u), servizio(s), durata(d), completata(c){}
};
class archivioPrenotazioni{
    private:
        int maxSize;
        int size;
        prenotazione* prenotazioni;

    public:
        archivioPrenotazioni(){
            this->maxSize = 100;
            this->size = 0;
            this->prenotazioni = new prenotazione[this->maxSize];
        }  
        ~archivioPrenotazioni(){
            delete[] prenotazioni;
        }

        void aggiungi(string utente, string servizio, unsigned durata, bool completata){
            if(size == maxSize){
                maxSize += 100;
                prenotazione* newPrenotazioni = new prenotazione[maxSize];
                for(int i = 0; i < size; i++){
                    newPrenotazioni[i] = prenotazioni[i];
                }
                delete[] prenotazioni;
                prenotazioni = newPrenotazioni;
            }
            prenotazioni[size] = prenotazione(utente, servizio, durata, completata);
            size++;
        }

        map<string, double> durataMediaServizio(){
            map<string, double> media;
            map<string, int> freq;
            for(int i = 0; i < size; i++){
                if(prenotazioni[i].completata){
                    freq[prenotazioni[i].servizio]++;
                    media[prenotazioni[i].servizio] += prenotazioni[i].durata;
                }
            }
            for(auto& it : freq){
                media[it.first] /= it.second;
            }
            return media;
        }

        vector<string> utentiConServNonCompl(unsigned soglia){
            vector<string> utenti;
            for(int i = 0; i < size; i++){
                if(!prenotazioni[i].completata && prenotazioni[i].durata > soglia){
                    utenti.push_back(prenotazioni[i].utente);
                }
            }
            return utenti;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void riempiMap(nodo* root, map<int, vector<int>>& val, int livello){
    if(root == nullptr) return;

    if(livello % 3 == 0) val[livello].push_back(root->val);

    riempiMap(root->sinistro, val, livello + 1);
    riempiMap(root->destro, val, livello + 1);
}

map<int, int> trovaMinimoLivello(nodo* root){
    map<int, vector<int>> val;
    riempiMap(root, val, 0);
    map<int, int> minPerLiv;
    for(auto& it : val){
        int min = INT_MAX;
        for(int i : it.second){
            if(i < min) min = i;
        }
        minPerLiv[it.first] = min;
    }
    return minPerLiv;
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

        int maxRaccoltoConBlocchi(int p, int a, const unordered_set<int>& bloccati, vector<bool>& visitato, int max){
            if(bloccati.count(p)) return -1;
            if(p == a) return max;
            visitato[p] = true;
            int risultato = -1;
            for(pair<int, int> s : grafo[p]){
                int salto = s.first;
                for(pair<int, int> v : grafo[salto]){
                    int nodo = v.first;
                    int peso = v.second;
                    if(visitato[nodo]) continue;
                    int nuovoMax = max(peso, max);
                    int res = maxRaccoltoConBlocchi(nodo, a, bloccati, visitato, nuovoMax);
                    risultato = max(risultato, res);
                }
            }
            visitato[p] = false;
            return risultato;
        }
};