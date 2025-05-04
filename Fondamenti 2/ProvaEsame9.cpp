#include <iostream>
#include <vector>
using namespace std;

//es1
class Studente{
    private: 
        string nome;
        double media;
    public:
        void getNome(){
            return nome;
        }
        void getMedia(){
            return media;
        }
};
class Registro{
    private:
        vector<Studente> registro;
    public:
        void aggiungi(const Studente& s){
            registro.push_back(s);
        }
        bool promossi(){
            for(auto s : registro){
                if(s.getMedia() < 18) return false;
            }
            return true;
        }
        Studente migliore(){
            Studente sm = registro[0];
            for(auto s : registro){
                if(s.getMedia() > sm.getMedia()){
                    sm = s;
                }
            }
            return sm;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore): val(valore), sinistro(nullptr), destro(nullptr){}
};

int profonditaMassima(nodo* root){
    if(root == nullptr) return 0;
    int profSin = profonditaMassima(root->sinistro);
    int profDestra = profonditaMassima(root->destro);
    return max(profSin, profDestra) + 1;
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
        void aggiungi(int u, int v){
            grafo[u].push_back(v);
        }
        int contaCammini(int u, int v, vector<bool>& visitato){
            if(u == v) return 1;
            visitato[u] = true;
            for(int vicino : grafo[u]){
                if(!visitato[vicino]){
                    int ris += contaCammini(vicino, v, visitato);
                }
            }
            visitato[u] = false;
            return ris;
        }
};