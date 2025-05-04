#include <iostream>
#include <vector>
#include <map>
using namespace std;

//es1
class Contatto{
    private:
        string nome, numero;
    public:
        Contatto(string n, string num) : nome(n), numero(num) {}
        string getNome() const {
            return nome;
        };
        string getNumero() const {
            return numero;
        };
};
class Rubrica{
    private:
        map<string, Contatto> contatti;
    public:
        void aggiungi(const Contatto& c){
            contatti[c.getNome()] = c;
        }
        void rimuovi(const string& nome){
            contatti.erase(nome);
        }
        Contatto cerca(const string& nome){
            if(contatti.find(nome) != contatti.end()){
                return contatti[nome];
            } else {
                cout<< "Contatto non trovato" <<endl;
                return Contatto("", "");
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

int contaNodiConUnaFoglia(nodo* root){
    if(root == nullptr) return 0;
    if(root->sinistro == nullptr || root->destro == nullptr){
        return 1;
    }
    return contaNodiConUnaFoglia(root->sinistro) + contaNodiConUnaFoglia(root->destro);
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
        bool esisteLunghezzak(int u, int& k, vector<bool>& visitato){
            if(k == 0) return true;
            visitato[u] = true;
            for(int vicino : grafo[u]){
                if(visitato[vicino]) continue;
                if(esisteLunghezzak(vicino, k-1)){
                    visitato[u] = false; 
                    return true;
                }
            }
            visitato[u] = false;
            return false;
        }
};