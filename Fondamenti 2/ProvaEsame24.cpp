#include <iostream>
#include <vector>
using namespace std;


//es1-
template <typename t>
class VettoreDinamico{
    private:
        int maxSize;
        int size;
        t* vect;
    
    public:
        VettoreDinamico(){
            this->maxSize = 100;
            this->size = 0;
            this->vect = new t[this->maxSize];
        }

        ~VettoreDinamico(){
            delete[] this->vect;
        }

        void aggiungiElemento(t& elem){
            if(size == 0){
                vect[0] = elem;
                size++;
                return;
            }
            vect[size] = elem;
            size++;
        }
        void rimuoviElemento(t& elem){
            for(int i = 0; i < size; i++){
                if(vect[i] == elem){
                    for(int j = i; j < size; i++){
                        vect[i] = vect[i+1];
                    }
                }
            }
            size--;
        }

        int dimensione(){
            return size;
        }

        t& operator[](int index){
            return vect[index];
        }
};


//es2
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

        bool hasCycle(int p, vector<bool>& visitato, vector<bool>& inRicorsione, vector<vector<int>>& grafo) {
            visitato[p] = true;
            inRicorsione[p] = true;

            for (int v : grafo[p]) {
                if (inRicorsione[v]) return true; // ciclo rilevato
                if (!visitato[v] && hasCycle(v, visitato, inRicorsione, grafo)) return true;
            }

            inRicorsione[p] = false;
            return false;
        }
};
