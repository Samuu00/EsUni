#include <iostream>
#include <map>
#include <vector>
using namespace std;

//es2
class Prodotto {
    private:
        string nomeProdotto;
        string categoriaProdotto;
        unsigned quantitàProdotto;
    public:
        string nome() const{
            return nomeProdotto;
        };
        string categoria() const{
            return categoriaProdotto;
        };
        unsigned quantità() const{
            return quantitàProdotto;
        };
};
class Magazzino{
    private:
        map<string, vector<Prodotto>> prodotti;
    public:
        void aggiungiProdotto(const Prodotto& p){
            string categoria = p.categoria();
            prodotti[categoria].push_back(p);
        };
        Prodotto estraiProdotto(string categoria){
            Prodotto prodottoDaEstrarre;
            for(prodotto : prodotti[categoria]){
                if(prodotto.quantità() > prodottoDaEstrarre.quantità()){
                    prodottoDaEstrarre = prodotto;
                }
            }
            return prodottoDaEstrarre;
        }
        int SommaQuantita(string categoria){
            unsigned somma = 0;
            for(Prodotto prodotto : prodotti[categoria]){
                somma += prodotto.quantità();
            }
            return somma;
        }      
};


//es3
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

int Altezza(nodo* root){
    if(root == nullptr) return 0;
    return 1 + max(Altezza(root->sinistro), Altezza(root->destro));
}

bool bilanciato(nodo* root){
    if(root == nullptr) return true;
    int hLeft = Altezza(root->sinistro);
    int hRight = Altezza(root->destro);
    if(abs(hLeft - hRight) > 1) return false;
    return bilanciato(root->sinistro) && bilanciato(root->destro);
}


//es4
class Grafo{
    private:
        vector<vector<int>> grafo;
        int n;
    public:
        Grafo(int n){
            this->n = n;
            grafo.resize(n);
        };
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        };

        bool camminoLunghezzaK(int partenza, int arrivo, int k){
            queue<pair<int, int>> coda;
            coda.push({partenza, 0});
            while(!coda.empty()){
                int nodo = coda.front().first;
                int lunghezza = coda.front().second;
                coda.pop();
                if(nodo == arrivo && lunghezza == k) return true;
                if(lunghezza < k){
                    for(int vicino : grafo[nodo]){
                        coda.push({vicino, lunghezza + 1});
                    }
                }
            }
            return false;
        }
};