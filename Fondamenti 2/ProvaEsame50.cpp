#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


//es1
struct pacco{
    string dest;
    string citta;
    double peso;
    unsigned cod;
};
class archivioPacchi{
    private:
        int maxSize;
        int size;
        pacco* archivio;

    public:
        archivioPacchi(){
            this->maxSize = 100;
            this->size = 0;
            this->archivio = new pacco[this->maxSize];
        } 

        void aggiungiPacco(string dest, string citta, double peso, unsigned cod){
            if(size = maxSize){
                maxSize += 100;
                pacco* nuovoArchivio = new pacco[maxSize];
                for(int i = 0; i < size; i++){
                    nuovoArchivio[i] = archivio[i];
                }
                delete[] archivio;
                archivio = nuovoArchivio;
            }
            archivio[size] = pacco(dest, citta, peso, cod);
        }

        double pesoCitta(string citta){
            double pesoTot = 0;
            for(int i = 0; i < size; i++){
                if(archivio[i].citta == citta) pesoTot += archivio[i].peso;
            }
            return pesoTot;
        }

        unsigned codMaxPesoCitta(string citta){
            unsigned codMax = 0;
            double pesoMax = 0;
            for(int i = 0; i < size; i++){
                if(archivio[i].citta == citta && archivio[i].peso > pesoMax){
                    pesoMax = archivio[i].peso;
                    codMax = archivio[i].cod;
                }
            }
            return codMax;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

int sommaFoglieDestreMaxProf(nodo* root, bool isRight, int prof, int maxProf){
    if(root == nullptr) return 0;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return (isRight && prof == maxProf) ? root->val : 0;
    }

    int sommaSin = sommaFoglieDestreMaxProf(root->sinistro, false, prof + 1, maxProf);
    int sommaDes = sommaFoglieDestreMaxProf(root->destro, true, prof + 1, maxProf);

    return sommaSin + sommaDes;
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

        void findPaths(int u, int a, vector<bool>& visited, vector<int>& path, vector<vector<int>>& allPaths, const unordered_set<int>& obbl, unordered_set<int> obb_trov) {
            if(obbl.count(u)) obb_trov.insert(u);
            visited[u] = true;
            path.push_back(u);
            
            if(u == a) {
                if(obb_trov.size() == obbl.size()) allPaths.push_back(path);
            }
            for (int v : grafo[u]) {
                if (!visited[v]) {
                    findPaths(v, a, visited, path, allPaths, obbl, obb_trov);
                }
            }
            
            path.pop_back();
            visited[u] = false;
        }

        int sommaMinima(vector<vector<int>>& allPaths, vector<int>& pesi){
            vector<int> somme;
            int somma = 0;
            for(auto& path : allPaths){
                for(int nodo : path){
                    somma += pesi[nodo];
                }
                somme.push_back(somma);
                somma = 0;
            }
            sort(somme.begin(), somme.end());
            return somme[0];
        }  
};
