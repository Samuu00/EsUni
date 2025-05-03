#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//es1
template <typename T>
class Rubrica{
    private:
        vector<T> contatti;
    public:
        void aggiungiContatto(T& contatto){
            contatti.push_back(contatto);
        }

        bool cerca(T& contatto){
            for (auto c : contatti){
                if(c == contatto){
                    return true;
                }
            }
            return false;
        }

        void stampaTutti(){
            for(auto c : contatti){
                cout << c << endl;
            }
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

bool esistePercorsoSomma(nodo* root, int somma){
    if(root == nullptr) return somma == 0;
    somma -= root->val;
    if(root->sinistro == nullptr && root->destro == nullptr){
        return somma == 0;
    }
    return esistePercorsoSomma(root->sinistro, somma) || esistePercorsoSomma(root->destro, somma);
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
    
        int ContaPercorsi(int u, int v){
            if(u == v) return 1;
            int cont = 0;
            for(int vicino : grafo[u]){
                cont += ContaPercorsi(vicino, v);
            }
            return cont;
        }
};

int main(){
    //es3
    Grafo g(5);
    g.aggiungiArco(0, 1);
    g.aggiungiArco(0, 2);
    g.aggiungiArco(1, 3);
    g.aggiungiArco(2, 3);
    g.aggiungiArco(3, 4);
    g.aggiungiArco(4, 1);
    cout << g.ContaPercorsi(0, 1) << endl;  
}
