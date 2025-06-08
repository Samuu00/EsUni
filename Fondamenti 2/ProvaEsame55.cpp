#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


//es1
struct accesso{
    string utente;
    string ruolo;
    int ora;
    bool successo;

    accesso(string u, string r, int o, bool s) : utente(u), ruolo(r), ora(o), successo(s) {}
};
class sistemaAccessi{
    private:
        int maxSize;
        int size;
        accesso* sistema;
    
    public:
        sistemaAccessi(){
            this->maxSize = 100;
            this->size = 0;
            this->sistema = new accesso[this->maxSize];
        }

        void registraAccesso(string u, string r, int o, bool s){
            if(size == maxSize){
                maxSize += 100;
                accesso* newSistema = new accesso[maxSize];
                for(int i = 0; i < size; i++){
                    newSistema[i] = sistema[i];
                }
                delete[] sistema;
                sistema = newSistema;
            }
            sistema[size] = accesso(u, r, o, s);
            size++;
        }
        
        set<string> utentiFalliti(int ora1, int ora2){
            set<string> falliti;
            for(int i = 0; i < size; i++){
                if(!sistema[i].successo && (sistema[i].ora >= ora1 && sistema[i].ora <= ora2)){
                    falliti.insert(sistema[i].utente);
                } 
            }
            return falliti;
        } 

        map<string, int> tentativiPerRuolo(){
            map<string, int> tentativi;
            for(int i = 0; i < size; i++){
                tentativi[sistema[i].ruolo]++;
            }
            return tentativi;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void foglieAlb(nodo* root, vector<int>& foglie){
    if(root == nullptr) return;

    if(root->sinistro == nullptr && root->destro == nullptr){
        foglie.push_back(root->val);
    }

    foglieAlb(root->sinistro, foglie);
    foglieAlb(root->destro, foglie);
}

vector<int> foglieDecr(nodo* root){
    vector<int> foglie;
    foglieAlb(root, foglie);
    sort(foglie.begin(), foglie.end()[](int a, int b){
        return a > b;
    });
    return foglie;
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

        int camminoMassimoDispari(int p, int a, vector<bool>& visitato, int somma){
            if(p == a) return somma;
            visitato[p] = true;
            int ris = -1;
            for(pair<int, int> v : grafo[p]){
                int nodo = v.first;
                int peso = v.second;
                if(visitato[nodo] || nodo % 2 == 0) continue;
                int nuovoMassimo = camminoMassimoDispari(nodo, a, visitato, somma + peso);
                ris = max(ris, nuovoMassimo);
            }
            visitato[p] = false;
            return ris;
        }
};



