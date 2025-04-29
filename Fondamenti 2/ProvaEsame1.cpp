#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 
using namespace std;

//es2
template <typename T>
class Archivio {
    private:
        T* elements; 
        unsigned maxSize; 
        unsigned size; 
    public:
        Archivio(){
            this->maxSize = 100; 
            this->size = 0;
            this->elements = new T[this->maxSize];
        };
        ~Archivio(){
            delete[] this->elements;
        };
        void aggiungi(const T& x){
            if (size < maxSize) {
                elements[size] = x;
                size++;
            } else {
                cout << "Archivio pieno!" << endl;
            }
        };
        void rimuovi(const T& x){
            for(size_t i = 0; i < size; i++){
                if(elements[i] == x){
                    for(size_t j = i; j < size - 1; j++){
                        elements[j] = elements[j + 1];
                    }
                    size--;
                    return;
                }
            }
        };   
        unsigned size() const{
            return size;
        };
        T& operator[](int i){
            return elements[i];
        };
};


//es3
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

bool sottoAlbero(nodo* root, nodo* subRoot){
    if(root == nullptr && subRoot == nullptr) return true;
    if(root == nullptr || subRoot == nullptr) return false;
    if(root->val != subRoot->val) return false;
    return sottoAlbero(root->sinistro, subRoot->sinistro) && sottoAlbero(root->destro, subRoot->destro);
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

        bool esisteArco(int u, int v){
            for(int vicino : grafo[u]){
                if(vicino == v) return true;
            }
            return false;
        }

        int costoMinimo(int partenza, int arrivo, const vector<int>& costo) {
            vector<int> dist(n, INT_MAX);
            queue<int> q;
    
            dist[partenza] = costo[partenza];  
            q.push(partenza);
    
            while (!q.empty()) {
                int nodo = q.front();
                q.pop();
    
                for (int vicino : grafo[nodo]) {
                    int nuovoCosto = dist[nodo] + costo[vicino];
                    if (nuovoCosto < dist[vicino]) {
                        dist[vicino] = nuovoCosto;
                        q.push(vicino);
                    }
                }
            }
            return dist[arrivo]; 
        }
};

