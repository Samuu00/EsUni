#include <iostream>
#include <map>
#include <vector>
using namespace std;


//es1
struct spedizione{
    string destinatario;
    string tipo;
    unsigned distanza;
    bool completata;
};
class centroConsegne{
    private:
        int maxSize;
        int size;
        spedizione* consegne;

    public:
        centroConsegne(){
            this->maxSize = 100;
            this->size = 0;
            this->consegne = new spedizione[this->maxSize];
        }  
        ~centroConsegne(){
            delete[] consegne;
        }

        void registra(string destinatario, string tipo, unsigned distanza, bool completata){
            if(size == maxSize){
                maxSize += 100;
                spedizione* nuovoConsegne = new spedizione[maxSize];
                for(int i = 0; i < size; i++){
                    nuovoConsegne[i] = consegne[i];
                }
                delete[] consegne;
                consegne = nuovoConsegne;
            }
            consegne[size] = spedizione(destinatario, tipo, distanza, completata);
            size++;
        }

        map<string, double> mediaDistanzaPerTipoCompl(){
            map<string, double> media;
            map<string, int> freq;
            for(int i = 0; i < size; i++){
                if(consegne[i].completata){
                    media[consegne[i].tipo] += consegne[i].distanza;
                    freq[consegne[i].tipo]++;
                }
            }
            for(auto& it : media){
                it.second /= freq[it.first];
            }
            return media;
        }

        vector<string> destinatariConPiuKM(unsigned soglia){
            vector<string> destinatari;
            map<string, double> distanze;
            for(int i = 0; i < size; i++){
                distanze[consegne[i].destinatarip] += consegne[i].distanza;
            }
            for(auto& it : distanze){
                if(it.second > soglia){
                    destinatari.push_back(it.first);
                }
            }
            return destinatari;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void riempiMap(nodo* root, int livello, map<int, int>& somme){
    if(root == nullptr) return;

    if((root->sinistro == nullptr && root->destro == nullptr) && livello % 2 == 0){
        somme[livello] += root->val;
    }

    sommaValoriFoglieLivelloPari(root->sinistro, livello + 1, somme);
    sommaValoriFoglieLivelloPari(root->destro, livello + 1, somme);
}

map<int, int> sommaValoriFoglieLivelloPari(nodo* root){
    map<int, int> somme;
    riempiMap(root, 0, somme);
    return somme;
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

        int camminiConMultipliDiK(int p, int a, int k, vector<bool>& visitato, int cont){
            if(p == a && cont == k) return 1;
            int cammini = 0;
            visitato[p] = true;
            for(int v : grafo[p]){
                if(visitato[v] || v % k != 0) continue;
                cammini += camminiConMultipliDiK(v, a, k, visitato, cont + 1);
            }
            visitato[p] = false;
            return cammini;
        }
};

