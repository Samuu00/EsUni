#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


//es1
struct appuntamento{
    string paziente;
    string giorno;
    unsigned orario;
    bool completato;

    appuntamento() : paziente(""), giorno(""), orario(0), completato(false) {}
    appuntamento(string p, string g, unsigned o, bool c) : paziente(p), giorno(g), orario(o), completato(c) {}
};
class agendaMedica{
    private:
        int maxSize;
        int size;
        appuntamento* appuntamenti;

    public:
        agendaMedica(){
            this->maxSize = 100;
            this->size = 0;
            this->appuntamenti = new appuntamento[this->maxSize];

            for(int i = 0; i < this->maxSize; i++){
                this->appuntamenti[i] = appuntamento("", "", 0, false);
            }
        }

        ~agendaMedica(){
            delete[] appuntamenti;
        }

        void registraAppunt(string paziente, string giorno, unsigned orario, bool completato){
            if(size == maxSize){
                maxSize += 100;
                appuntamento* newAppuntamenti = new appuntamento[maxSize];
                for(int i = 0; i < size; i++){
                    newAppuntamenti[i] = appuntamenti[i];
                }
                delete[] appuntamenti;
                appuntamenti = newAppuntamenti;
            }
            appuntamenti[size] = appuntamento(paziente, giorno, orario, completato);
            size++;
        }

        map<string, int> appuntComplPerGiorno(){
            map<string, int> complet;
            for(int i = 0; i < size; i++){
                if(appuntamenti[i].completato) complet[appuntamenti[i].giorno]++;
            }
            return complet;
        }

        set<string> pazientiConMancanze(){
            set<string> mancanze;
            for(int i = 0; i < size; i++){
                if(!appuntamenti[i].completato) mancanze.insert(appuntamenti[i].paziente);
            }
            return mancanze;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v): val(v), sinistro(nullptr), destro(nullptr) {}
};

bool PercorsoDecr(nodo* root, int prec, int somma, vector<int>& somme){
    if(root == nullptr) return false;

    somma += root->val;
    if(root->val >= prec) return false;

    if(root->sinistro == nullptr && root->destro == nullptr){
        somme.push_back(somma);
        return true;
    }

    return PercorsoDecr(root->sinistro, root->val, somma, somme) || PercorsoDecr(root->destro, root->val, somma, somme);
}

int sommaMaggPerc(nodo* root){
    vector<int> somme;
    int mass = -1;
    bool trovato = PercorsoDecr(root, 0, 0, somme);
    if(trovato){
        sort(somme.begin(), somme.end(), [](int a, int b){
            return a > b;
        });
        mass = somme[0];
        return mass;
    }
    return mass;
}


//es2b
struct nodo{
    char car;
    nodo* sinistro;
    nodo* destro;

    nodo(char c) : car(c), sinistro(nullptr), destro(nullptr) {}
};

void parolePercorso(nodo* root, string parola, vector<string>& parole){
    if(root == nullptr) return;

    parola += root->car;
    if(root->sinistro == nullptr && root->destro == nullptr){
        parole.push_back(parola);
    }

    parolePercorso(root->sinistro, parola, parole);
    parolePercorso(root->destro, parola, parole);
}

string paroleMaggPerc(nodo* root){
    vector<string> parole;
    string maxParole = "";
    parolePercorso(root, "", parole);

    if(!parole.empty()) return "";

    sort(parole.begin(), parole.end(), [](string a, string b){
        return a.length() > b.length();
    });
    maxParole = parole[0];
    return maxParole;
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

        void aggiungiArco(int u, int v, int p){
            grafo[u].push_back({v, p});
        }

        int percorsoMinimoPari(int p, int a, vector<bool>& visitato, int somma){
            if(p == a) return somma;
            visitato[p] = true;
            int ris = INT_MAX;
            for(pair<int, int> v : grafo[p]){
                int nodo = v.first;
                int peso = v.second;
                if(visitato[nodo] || nodo % 2 != 0) continue;
                int nuovoMin = percorsoMinimoPari(nodo, a, visitato, somma + peso);
                ris = min(ris, nuovoMin);
            }
            visitato[p] = false;
            return ris;
        }
        int percorsoMinimoDispari(int p, int a, vector<bool>& visitato, int somma){
            if(p == a) return somma;
            visitato[p] = true;
            int ris = INT_MAX;
            for(pair<int, int> v : grafo[p]){
                int nodo = v.first;
                int peso = v.second;
                if(visitato[nodo] || nodo % 2 == 0) continue;
                int nuovoMin = percorsoMinimoDispari(nodo, a, visitato, somma + peso);
                ris = min(ris, nuovoMin);
            }
            visitato[p] = false;
            return ris;
        }

        map<string, int> percorsi(){
            map<string, int> ris;
            vector<bool> visitato(n, false);
            int minPari = percorsoMinimoPari(0, n-1, visitato, 0);
            int minDisp = percorsoMinimoDispari(0, n-1, visitato, 0);
            if(minPari != INT_MAX) ris["Pari"] = minPari;
            if(minDisp != INT_MAX) ris["Dispari"] = minDisp;
            return ris;
        }
};
