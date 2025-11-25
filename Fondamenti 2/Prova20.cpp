#include <iostream>
#include <vector>
using namespace std;

//es2
class InsiemeOrdinato {
    private:
        int* data;      
        int size;      
        int capacity; 

        void resize(){
            int newCap = this->capacity * 2;
            this->capacity = newCap;
            int* newData = new int[newCap];

            for(int i = 0; i < size; i++){

                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }

    public:
        InsiemeOrdinato(): size(0), capacity(10){
            this->data = new int[this->capacity];
        }
        
        ~InsiemeOrdinato(){
            delete[] data;
        }

        InsiemeOrdinato(const InsiemeOrdinato& other): size(other.size), capacity(other.capacity){
            this->data = new int[capacity];

            for(int i = 0; i < size; i++){

                this->data[i] = other.data[i];
            }
        }

        InsiemeOrdinato& operator=(const InsiemeOrdinato& other){
            if(this == &other) return *this;

            this->capacity = other.capacity;
            this->size = other.size;

            delete[] data;

            this->data = new int[this->capacity];

            for(int i = 0; i < size; i++){

                this->data[i] = other.data[i];
            }

            return *this;
        }
        
        void insert(int val){
            if(size == capacity) resize();
            if(contains(val)) return;
            
            int index = 0;
            while(index < size && val < data[index]){
                index++;
            }
            
            for (int i = size; i > index; i--) {

                data[i] = data[i - 1];
            }

            data[index] = val;
            size++;
        }
        
        bool contains(int val) const{
            int l = 0, r = size - 1;

            while(l <= r){
                int mid = l + (r - l) / 2;

                if(data[mid] == val) return true;

                if(val < data[mid]){

                    r = mid - 1;

                }else{

                    l = mid + 1;
                }

            }

            return false;
        }

        InsiemeOrdinato operator+(const InsiemeOrdinato& other) const {
            InsiemeOrdinato e;

            for(int i = 0; i < this->size; i++){

                e.insert(this->data[i]);
            }

            for(int i = 0; i < other.size; i++){

                e.insert(other.data[i]);
            }

            return e;
        }
        
        InsiemeOrdinato operator-(const InsiemeOrdinato& other) const {
            InsiemeOrdinato e;

            for(int i = 0; i < size; i++){

                if(other.contains(data[i])) continue;

                e.insert(data[i]);
            }

            return e;
        }
};


//es3
enum Direzione { SIN, DES };
class AlberoB {
    private:
        int info;  
        AlberoB* p;          
        AlberoB* sx;          
        AlberoB* dx;                 

    public:
        
        AlberoB(int valore) : info(valore),  p(nullptr), sx(nullptr), dx(nullptr) {}

        ~AlberoB() {
            delete sx; 
            delete dx;
        }

        AlberoB* figlio(Direzione dir) {
            if (dir == SIN) {
                return this->sx;
            }
            return this->dx;
        }

        AlberoB* padre() {
            return this->p;
        }

        int radice() {
            return this->info;
        }
 
        bool foglia() {
            return (this->sx == nullptr && this->dx == nullptr);
        }

        static bool nullo(AlberoB* a) {
            return a == nullptr;
        }

        int calcolaDiametro(AlberoB* a, int& maxDiam){
            if(nullo(a)) return 0;

            int hSin = calcolaDiametro(a->figlio(SIN), maxDiam);
            int hDes = calcolaDiametro(a->figlio(DES), maxDiam);

            int d = 1 + hSin + hDes;

            maxDiam = max(maxDiam, d);

            return 1 + (max(hSin, hDes));
        }
};


//es4
class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

        int n() const {
            return numNodi;
        }
        int m() const {
            return numArchi;
        }

        void aggiungiArco(int i, int j) {
            if (i < 0 || j < 0 || i >= numNodi || j >= numNodi) throw out_of_range("Indice nodo non valido");
            if (!adj[i][j]) {
                adj[i][j] = true;
                numArchi++;
            }
        }

        void dfs(int p, vector<int>& clique, vector<bool>& visitati){
            visitati[p] = true;
            clique.push_back(p);

            bool is = true;
            for(int i = 0; i < n(); i++){

                if(adj[p][i] && !visitati[i]){

                    for(int v : clique){

                        if(!adj[i][v]) is = false;
                    }

                    if(is) dfs(p, clique, visitati);
                }
            }
        }  

        vector<int> Clique(const Grafo& g, int k){
            vector<int> clique;
            vector<bool> visitati(n(), false);
            
            for(int i = 0; i < n(); i++){

                dfs(i, clique, visitati);
            }

            return clique;
        }
};