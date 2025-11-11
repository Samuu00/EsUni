#include <iostream>
#include <string>
#include <stack>
#include <set>
using namespace std;

//es2
class EditorTesto {
    private:
        string testoAttuale;
        stack<string> undoStack; 
        stack<string> redoStack; 

    public:
        EditorTesto() : testoAttuale("") {}

        string getText() const{
            return testoAttuale;
        }
        
        void scrivi(const string& nuovoTesto){
            undoStack.push(testoAttuale);
            testoAttuale += nuovoTesto;

            while(!redoStack.empty()){
                redoStack.pop();
            }
        }
        
        void undo(){
            if(undoStack.empty()) return;

            redoStack.push(testoAttuale);
            testoAttuale = undoStack.top(); undoStack.pop();
        }
        
        void redo(){
            if(redoStack.empty()) return;

            undoStack.push(testoAttuale);
            testoAttuale = redoStack.top(); redoStack.pop();
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
                numArchi++;
            }
        }

        bool DetectCycle(int n, vector<bool>& visitati, vector<bool>& inStack){
            visitati[n] = true;
            inStack[n] = true;

            for(int i = 0; i < n(); i++){
                if(adj[n][i]){

                    if(!visitati[i]){

                        if(DetectCycle(i, visitati, inStack)) return true;

                    }else{

                        if(inStack[i]) return true;
                    }
                }
            }
            inStack[n] = false;
            return false;
        }

        bool hasCycle(){
            vector<bool> visitati(n(), false);
            vector<bool> inStack(n(), false);

            for(int i = 0; i < n(); i++){

                if(DetectCycle(i, visitati, inStack)) return true;
            }

            return false;
        }
            
};

//es4
bool findParola(vector<vector<char>>& grid, const string& parola, int dr[], int dc[], int r, int c, int indiceParola){
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return false;

    if(grid[r][c] != parola[indiceParola]) return false;

    if(indiceParola == parola.length() - 1) return true;

    char curr = grid[r][c];
    grid[r][c] = '#';

    bool trov = false;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(findParola(grid, parola, dr, dc, nr, nc, indiceParola + 1)){
            trov = true;
            break;
        }
    }

    grid[r][c] = curr;
    return trov;
}

bool esisteParola(const vector<vector<char>>& grid, const string& parola){
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    vector<vector<char>>& gridCopy = grid;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){

            if(grid[i][j] == parola[0]){

                if(findParola(gridCopy, parola, dr, dc, i, j, 0)) return true;
            }
        }
    }
    return false;
}