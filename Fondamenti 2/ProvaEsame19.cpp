#include <iostream>
using namespace std;


//es1
class RegistraValori{
    private:
        int maxSize;
        int size;
        int* buffer;

    public:
        RegistraValori(){
            this->maxSize = 100;
            this->size = 0;
            this->buffer = new int[this->maxSize];
        }
        ~RegistraValori(){
            delete[] buffer;
        }

        void aggiungi(int& valore){
            if(size == 0){
                buffer[0] = valore;
                size++;
                return;
            }
            buffer[size] = valore;
            size++;
        }
        int massimo(){
            int mass = buffer[0];
            for(int i = 0; i < size; i++){
                if(buffer[i] > mass){
                    mass = buffer[i];
                }
            }
            return mass;
        }
        bool visto(int& valore){
            for(int i = 0; i < size; i++){
                if(buffer[i] == valore) return true;
            }
            return false;
        }

};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool camminoCrescente(nodo* root, int& preVal){
    if(root == nullptr) return true;
        
    if(root->val <= preVal) return false;

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return camminoCrescente(root->sinistro, root->val) || camminoCrescente(root->destro, root->val);
}


//es3
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;
    public:
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }

        bool esisteCamminoSenza(int s, int t, vector<bool>& visitato, int escluso){
            if(s == t) return true;
            if(s == escluso) return false;
            visitato[s] = true;
            for(int v : grafo[s]){
                if(visitato[v]) continue;
                if(esisteCamminoSenza(v, t, visitato, escluso)) return true;
            }
            visitato[s] = false;
            return false;
        }
}