#include <iostream>
#include <unordered_map>
using namespace std;


//es1
class Articolo{
    private:
        string nome;
        int quantita;
    public:
        void getNome(){
            return nome;
        }  
        void getQuantita(){
            return quantita;
        } 
};
class Magazzino{
    private:
        unordered_map<string, Articolo> inventario;
    public:
        void aggiungi(const Articolo& a){
            inventario[a.getNome()] = a;
        }
        bool rimuovi(const string& nome, int quantita){
            if(inventario.find(nome) != inventario.end()){
                if(inventario[nome].getQuantita() >= 0){
                    for(int i = 0; i < inventario[nome].getQuantita(); i++){
                        inventario.erase(nome);
                    }
                    return true;
                }
            }
            return false;
        }
        void stampa(){
            for(auto it = inventario.begin(); it != inventario.end(); it++){
                cout << "Articolo: " << it->first << it->second <<endl;
            }
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore): val(valore) sinistro(nullptr), destro(nullptr){};
};

int massimoValore(nodo* root){
    if(root == nullptr) return 0;
    int maxSinistro = massimoValore(root->sinistro);
    int maxDestro = massimoValore(root->destro);

    return max(root->valore, max(maxSinistro, maxDestro));
}


//es3
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;
    public:
        Grafo(int n){
            this->n;
            grafo.resize(n);
        }
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }
        bool camminoEscludendoNodo(int u, int v, int block, vector<bool>& visitato){
            if(u == block) return false;
            if(u == v) return true;
            visitato[u] == true;
            for(int vicino : grafo[u]){
                if(camminoEscludendoNodo(vicino, v, block, visitato)){
                    return true;
                }
            }
            return false;
        }
};