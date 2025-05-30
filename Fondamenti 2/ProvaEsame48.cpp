#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
using namespace std;

//es1
struct messaggio{
    string mittente;
    string tipo;
    unsigned priorita;
};
class gestioneMessaggi{
    private:
        int maxSize;
        int size;
        messaggio* gestoreMess;
    
    public:
        gestioneMessaggi(){
            this->maxSize = 100;
            this->size = 0;
            this->gestoreMess = new messaggio[this->maxSize];
        }  
        ~gestioneMessaggi(){
            delete[] gestoreMess;
        }

        void aggiungiMessaggio(string& mittente, string& tipo, unsigned priorita){
            if(size == maxSize) throw runtime_error("Lista piena");

            gestoreMess[size].mittente = mittente;
            gestoreMess[size].tipo = tipo;
            gestoreMess[size].priorita = priorita;
            size++;
        }

        unsigned sommaPrioritaMittente(string& mittente){
            unsigned somma = 0;
            for(int i = 0; i < size; i++){
                if(gestoreMess[i].mittente == mittente) somma += gestoreMess[i].priorita;
            }
            return somma;
        }

        map<string, double> mediaPerTipo(){
            map<string, double> media;
            map<string, int> freq;
            for(int i = 0; i < size; i++){
                freq[gestoreMess[i].tipo]++;
                media[gestoreMess[i].tipo] += gestoreMess[i].priorita;
            }
            for(auto& it : media){
                media[it.first] /= freq[it.first];
            }
            return media;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool percorsoDecreMult3(nodo* root, int prec){
    if(root == nullptr) return false;

    if(root->val >= prec || root->val % 3 != 0) return false;

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return percorsoDecreMult3(root->sinistro, root->val) || percorsoDecreMult3(root->destro, root->val);
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

        bool camminoKcrescente(int p, int a, int k, int pesoPrec){
            if(p == a) return k == 0;
            for(pair<int, int> v : grafo[p]){
                int n = v.first;
                int p = v.second;
                if(p > pesoPrec){
                    if(camminoKcrescente(n, a, k-1, p)) return true;
                }
            }
            return false;
        }
};