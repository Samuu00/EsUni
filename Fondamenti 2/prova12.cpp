#include <string>
#include <vector>
using namespace std;

//es2
class StringVector {
    private:
        string* data;   
        int size;       
        int capacita;   
        
        void resize(){
            int newSize = this->capacita * 2;
            this->capacita = newSize;

            string* newData = new string[newSize];

            for(int i = 0; i < size; i++){

                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }

    public:
        StringVector(): size(0), capacita(10){
            this->data = new string[this->capacita];
        }
        
        ~StringVector(){
            delete[] data;
        }
        
        StringVector(const StringVector& other): size(other.size), capacita(other.capacita){
            this->data = new string[this->capacita];

            for(int i = 0; i < size; i++){
                this->data[i] = other.data[i];
            }
        }

        void push_back(const string& valore){
            if(size == capacita) resize();

            data[size] = valore;
            size++;
        }
        
        StringVector& operator=(const StringVector& other){
            if(this == &other) return this;

            size = other.size;
            capacita = other.capacita;

            delete data[];

            this->data = new string[capacita];

            for(int i = 0; i < size; i++){
                data[i] = other.data[i]
            }

            return this;
        }
        
        StringVector operator+(const StringVector& other) const{
            StringVector  s;
            for(int i = 0; i < size; i++){
                s.push_back(data[i]);
            }

            for(int j = 0; j < other.size; j++){
                s.push_back(other.data[j]);
            }

            return s;
        }
        
        const string& operator[](int index) const{
            if(index < 0 || index >= size) throw out_of_range("fuori limite");

            return data[index];
        }
        
        string& operator[](int index){
            if(index < 0 || index >= size) throw out_of_range("fuori limite");

            return data[index];
        }
};


//es3
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
                adj[j][i] = true;
                numArchi++;
            }
        }

        void dfs(int p, int x, vector<bool>& visitati){
            visitati[p] = true;

            for(int i = 0; i < n(); i++){
                if(adj[p][i] && !visitati[i] && p != i){
                    if(i == x) continue;
                    dfs(i, x, visitati);
                }
            }
        }

        vector<int> trovaPuntiArticolazione(){
            vector<int> punti;

            for(int i = 0; i < n(); i++){
                
                for(int j = 0; j < n(); j++){
                    if(i == j) continue;
                    if(adj[i][j]){
                        int start = j;
                        break;
                    }
                }

                vector<bool> visitati(n(), false);
                dfs(start, i, visitati);

                int nodir = 0;
                for(bool f : visitati){
                    if(f) nodir++;
                }

                if(nodir < n() - 1) punti.push_back(i);
            }

            return punti;
        }
};


//es4
int dr[] = { 2,  2,  1,  1, -1, -1, -2, -2 };
int dc[] = { 1, -1,  2, -2,  2, -2,  1, -1 };

bool dfs(vector<vector<int>>& grid, int r, int c, int n){
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return false;

    if(grid[r][c] != 0) return false;

    grid[r][c] = n;

    if(n == (grid.size() * grid[0].size())) return true;

    for(int i = 0; i < 8; i++){

        int nr = r + dr[i];
        int nc = c + dc[i];

        if(dfs(grid, nr, nc, n + 1)) return true;
    }

    grid[r][c] = 0;
    return false;
}

bool trovaCamminoCavallo(int n, int startR, int startC){
    vector<vector<int>> board(n, vector<int>(n, 0));

    int p = 1;
    if(dfs(board, startR, startC, p)) return true;

    return false;
}