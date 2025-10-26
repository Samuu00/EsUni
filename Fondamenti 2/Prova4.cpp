#include <iostream>
#include <map>
using namespace std;

//es2
class NodoFileSystem{
    private:
        string nome;

    public:
        NodoFileSystem(string& n): nome(n) {}

        string getNome() { return nome; }

        virtual int dimensione() const = 0;

        virtual ~NodoFileSystem() {}
};

class File : public NodoFileSystem{
    private:
        string contenuto;
    
    public:
        File(string& n, string cont): NodoFileSystem(n), contenuto(cont){}

        int dimensione() const override{
            return contenuto.length();
        }
};

class Directory : public NodoFileSystem{
    private:
        map<string, NodoFileSystem*> figli;
    
    public:
        Directory(string& n): NodoFileSystem(n) {}
    
        int dimensione() const override{
            int size = 0;
            for(auto& it : figli){

                NodoFileSystem* curr = it.second;

                size += curr->dimensione();
            }
            return size;
        }

    bool aggNodo(NodoFileSystem* n){
        auto it = figli.find(n->getNome());

        if(it != figli.end()) return false;

        figli[n->getNome()] = n;
        return true;
    }

    NodoFileSystem* findNodo(const string& nome){
        auto it = figli.find(nome);

        if(it != figli.end()) return it->second;

        return nullptr;
    }

    ~Directory() {
        for(auto& it : figli){
            delete it.second;
        }
    }
};


//es3
class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n, vector<int> p) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

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

        void dfs(int p, vector<bool>& visitati){
            visitati[p] = true;

            for(int i = 0; i < n; i++){
                if(adj[p][i] && !visitati[i]){
                    dfs(i, visitati);
                }
            }
        }

        vector<int> trovaInfl(){
            vector<int> entranti(n(), 0);
            vector<int> infl;

            for(int i = 0; i < n(); i++){
                for(int j = 0; j < n(); j++){
                    if(adj[i][j]) entranti[j]++;
                }
            }

            for(int x = 0; x < n(); x++){

                if(entranti[x] == 0){
                    vector<bool> visitati(n(), false);
                    dfs(x, visitati);

                    bool yes = true;
                    for(int k = 0; k < n(); k++){
                        if(!visitati[k]){
                            yes = false;
                            break;
                        }
                    }

                    if(yes) infl.push_back(x);
                }

            }
            return infl;
        }
};