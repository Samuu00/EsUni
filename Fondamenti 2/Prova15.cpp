#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

//es2
class Animale{
    private:
        string nome;
        string specie;
    
    public:
        Animale(const string& n, const string& s): nome(n), specie(s){}

        string getNome() const { return nome; }
        string getSpecie() const { return specie; }

        virtual string emettiVerso() const = 0;
        virtual int getReazioneCibo() const = 0;

        virtual ~Animale() {}
};  

class Leone : public Animale{
    public:
        Leone(const string& n): Animale(n, "Leone"){}

        string emettiVerso() const override { return "roar"; }

        int getReazioneCibo() const override { return 10000; }
};

class Scimmia : public Animale{
    private:
        int agilita;

    public:
        Scimmia(const string& n, int& a): Animale(n, "Scimmia"), agilita(a){}

        string emettiVerso() const override { return "ooh-ooh"; }
        int getReazioneCibo() const override { 1000 + (agilita * 5); }
};

class Zoo{
    private:
        map<string, Animale*> zoo;
        
    public: 
        Zoo(){}

        ~Zoo(){
            for(auto& it : zoo){
                delete it.second;
            }
        }

        bool aggiungiAnimale(Animale* a){
            auto it = zoo.find(a->getNome());

            if(it != zoo.end()) return false;

            zoo[a->getNome()] = a;
            return true;
        }

        void appello() const {
            for(auto& it : zoo){
                cout<< "[" << it.second->getNome() << "]: "<< it.second->emettiVerso() << endl;
            }
        }

        int calcolaCiboTot() const {
            int tot = 0;
            for(auto& it : zoo){
                tot += it.second->getReazioneCibo();
            }

            return tot;
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

        int bfs(int p, int a){
            queue<int> q;
            vector<int> percorso(n(), 0);
            vector<bool> visitati(n(), false);

            q.push(p);
            visitati[p] = true;

            while(!q.empty()){

                int curr = q.front(); q.pop();

                if(a == curr) return percorso[curr];

                for(int i = 0; i < n(); i++){

                    if(adj[curr][i] && !visitati[i] && curr != i){

                        visitati[i] = true;
                        q.push(i);
                        percorso[i] = percorso[curr] + 1;

                    }
                }
            }

            return -1;
        }

        int percorsoMinimoConCheckpoint(int u, int v, int c){
            int sommaPercorso = 0;

            sommaPercorso += bfs(u, c);

            if(sommaPercorso >= 0) sommaPercorso += bfs(c, v);

            return (sommaPercorso >= 0) ? sommaPercorso : -1;
        }
};