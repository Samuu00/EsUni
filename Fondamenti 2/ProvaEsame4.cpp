#include <iostream>
#include <vector>
using namespace std;

//es1
class Elemento(){
    private:
        string nome;
        int priorita;
    public:
        getNome() const{
            return nome;
        };
        getPriorita() const{
            return priorita;
        };
}
class codaPrioritaria{
    private:
        vector<Elemento> elementi;
    public:
        void inserisci(Elemento& e){
            elementi.push_back(e);
        }
        Elemento estrai(){
            if(elementi.empty()) return Elemento();
            int max = 0;
            for(int i = 0; i < elementi.size(); i++){
                if(elementi[i].getPriorita() > elementi[max].getPriorita()){
                    max = i;
                }
            }
            elementi.erase(elementi.begin() + max);
            return elementi[max];
        }
        bool vuota(){
            if(elementi.empty()) return true;
            return false;
        }
}


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
}

int contaFoglie(nodo* root){
    if(root == nullptr) return 0;
    if(root->sinistro == nullptr && root->destro == nullptr) return 1;
    return contaFogli(root->sinistro) + contaFogli(root->destro);
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

        bool controllaSeDiretto(int i, int j){
            for(int vicino : grafo[i]){
                if(vicino == j){
                    return true;
                }
            }
            return false;
        }

        bool controllaPercorsoCrescente(int u, int v, vector<int>& pesi, vector<bool>& visitato){
            if(u == v) return true;
            visitato[u] = true;
            for(int vicino : grafo[u]){
                if(!visitato[vicino] && pesi[vicino] > pesi[u]){
                    if(controllaPercorsoCrescente(vicino, v, pesi, visitato)){
                        return true;
                    }
                }
            }
            visitato[u] = false;
            return false;
        }
}