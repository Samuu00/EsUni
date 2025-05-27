#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
using namespace std;


//es1
struct lettura{
    int id;
    double valore;
};
class archivioSensori{
    private:
        int maxSize;
        int size;
        lettura* dati;

    public:
        archivioSensori(){
            this->maxSize = 100;
            this->size = 0;
            this->dati = new lettura[this->maxSize];
        }

        void aggiungiLetture(lettura& l){
            if(size == maxSize) throw runtime_error("Archivio pieno");
            if(size == 0){
                dati[0] = l;
                size++;
                return;
            }
            dati[size] = l;
            size++;
        }

        double mediaLetture(int id){
            double media = 0.0;
            int cont = 0;
            for(int i = 0; i < size; i++){
                if(dati[i].id == id){
                    media += dati[i].valore;
                    cont++;
                }
            }
            if(cont != 0){
                media /= cont;
            }else{
                throw runtime_error("Id non trovato");
            }
            return media;
        }

        int idPiuLetture(){
            map<int, int> idLetture;
            for(int i = 0; i < size; i++){
                idLetture[dati[i].id]++;
            }
            int id = -1;
            int max = 0;
            for(auto& l : idLetture){
                if(l.second > max){
                    max = l.second;
                    id = l.first;
                }
            }
            return id;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool camminoAlternato(nodo* root, int livello){
    if(root == nullptr) return false;

    if(root->val % 2 != 0 && livello % 2 == 0) return false;
    if(root->val % 2 == 0 && livello % 2 != 0) return false;

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return camminoAlternato(root->sinistro, livello + 1) || camminoAlternato(root->destro, livello + 1);

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
            grafo[u].push_back(make_pair(v, peso));
        }

        bool camminoCrescente(int p, int a, int pesoPrec){
            if(p == a) return true;
            for(pair<int, int> coppia : grafo[p]){
                int v = coppia.first;
                int peso = coppia.second;
                if(peso > pesoPrec){
                    if(camminoCrescente(v, a, peso)) return true;
                }
            }
            return false;
        }
};
