#include <iostream>
#include <queue>
using namespace std;


//es1
struct Studente{
    string nome;
    int voto;
};

class RegistroStudente{
    private:
        int maxSize;
        int size;
        Studente* studenti;
    public:
        RegistroStudente(){
            this->maxSize = 100;
            this->size = 0;
            this->studenti = new Studente[this->maxSize];
        }

        void aggiungiStudente(string& nome, int& voto){
            if(size == 0){
                studenti[0].nome = nome;
                studenti[0].voto = voto;
                size++;
                return;
            }
            for(int i = 0; i < size; i++){
                if(studenti[i].nome == nome){
                    cout << "Studente gia presente";
                    return;
                }
            }
            studenti[size].nome = nome;
            studenti[size].voto = voto;
            size++;
        }
        void aggiornaVoto(string& nome, int newVoto){
            for(int i = 0; i < size; i++){
                if(studenti[i].nome == nome){
                    studenti[i].voto = newVoto;
                    return;
                }
            }
        }
        int voto(string& nome){
            int voto = 0;
            for(int i = 0; i < size; i++){
                if(studenti[i].nome == nome){
                    voto = studenti[i].voto;
                }
            }
            return voto;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

int contaSoloUnFiglio(nodo* root){
    if(root == nullptr) return 0;

    int contaSin = contaSoloUnFiglio(root->sinistro);
    int contaDest = contaSoloUnFiglio(root->destro);

    if((root->sinistro != nullptr && root->destro == nullptr) || (root->destro != nullptr && root->sinistro == nullptr)){
        return 1 + contaSin + contaDest;
    }else{
        return contaSin + contaDest;
    }
    return contaSoloUnFiglio(root->sinistro) + contaSoloUnFiglio(root->destro); 
}

int Altezza(nodo* root){
    if(root == nullptr) return 0;

    int hSinistro = Altezza(root->sinistro);
    int hDestro = Altezza(root->destro);
    return 1 + max(hSinistro, hDestro);
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
    bool coprenti(int u, int v, vector<pair<int, int>> coprenti){
        vector<bool> visitato(n, false);
        queue<int> q;
        q.push(u);
        visitato[u] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == v){
                for(pair<int, int> c : coprenti){
                    if(visitato[c.first] && visitato[c.second]) return true;
                    return false;
                }
            }
            for(int v : grafo[u]){
                if(visitato[u]) continue;
                visitato[v] = true;
                q.push(v);
            }
        }
    }
};
