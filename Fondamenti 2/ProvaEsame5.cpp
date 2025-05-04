#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


//es1
class Studente{
    private:
        string matricola;
        string nome;  
    public:
        Studente(string m, string n) : matricola(m), nome(n) {}
        string getMatricola() const {
            return matricola;
        };
        string getNome() const {
            return nome;
        };
};
class RegistroScolastrico{
    private:
        unordered_map<string, Studente> studenti;
    public: 
        void aggiungi(const Studente& s) {
            studenti[s.getMatricola()] = s;
        };
        bool presente(const string& matricola){
            return studenti.find(matricola) != studenti.end();
        }
        void stampa() const{
            for(auto it = studenti.begin(); it != studenti.end(); it++){
                cout << "Matricola: " << it->first << ", Nome: " << it->second.getNome() << endl;
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

bool isBST(nodo* root){
    if(root == nullptr) return true;
    if(root->sinistro != nullptr && root->sinistro->val >= root->val) return false;
    if(root->destro != nullptr && root->destro->val <= root->val) return false;
    return isBST(root->sinistro) && isBST(root->destro);
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
        int distanzaMinima(int u, int v, vector<bool>& visitato){
            queue<pair<int, int>> q;
            q.push({u, 0});
            visitato[u] = true;
            while(!q.empty()){
                auto [nodoCorrente, distanza] = q.front();
                q.pop();
                if(nodoCorrente == v) return distanza;
                for(int vicino : grafo[nodoCorrente]){
                    if(!visitato[vicino]){
                        visitato[vicino] = true;
                        q.push({vicino, distanza + 1});
                    }
                }
            }
        }
};