#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//es1
class Libro{
    private:
        string titolo, autore;
        int anno;
    public:
        Libro(string t, string a, int an) : titolo(t), autore(a), anno(an) {}
        string getTitolo() const {
            return titolo;
        };
        string getAutore() const {
            return autore;
        };
        int getAnno() const {
            return anno;
        };
};
class Archivio{
    private:
        vector<Libro> libri;
    public:
        void aggiungi(const Libro& l){
            libri.push_back(l);
        }
        vector<Libro> cercaPerAutore(const string& autore){
            vector<Libro> risultati;
            for(auto libro : libri){
                if(libro.getAutore() == autore){
                    risultati.push_back(libro);
                }
            }
            return risultati;
        }
        Libro piuVecchio(){
            Libro piuVecchio = libri[0];
            for(auto libro : libri){
                if(libro.getAnno() < piuVecchio.getAnno()){
                    piuVecchio = libro;
                }
            }
            return piuVecchio;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

int sommaLivello(nodo* root, int l){
    if(root == nullptr) return 0;
    if(l == 0) return root->val;
    return sommaLivello(root->sinistro, l-1) + sommaLivello(root->destro, l-1);
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
        int camminoMassimo(int u, int v, vector<bool>& visitato, int maxCammino){
            if(u == v) return maxCammino + 1;
            visitato[u] = true;
            int maxLunghezza = 0;
            for(int vicino : grafo[u]){
                if(!visitato[vicino]){
                    int lunghezza = camminoMassimo(vicino, v, visitato, maxCammino + 1);
                    maxLunghezza = max(maxLunghezza, lunghezza);
                }
            }
            visitato[u] = false;
            return maxLunghezza;
        }
};
