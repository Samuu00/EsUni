#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//es1
struct Libro{
    string titolo;
    int copie;
};
class Libreria{
    private:
        int maxSize;
        int size;
        Libro* libreria;
    public:
        Libreria(){
            this->maxSize = 100;
            this->size = 0;
            this->libreria = new Libro[maxSize];
        }
        void aggiungi(string& titolo, int& copie){
            if(size == 0){
                libreria[0].titolo = titolo;
                libreria[0].copie = copie;
                size++;
                return;
            }
            for(int i = 0; i < size; i++){
                if(libreria[i].titolo == titolo){
                    libreria[i].copie += copie;
                    return;
                }
            }
            libreria[size + 1].titolo = titolo;
            libreria[size + 1].copie = copie;
            size++;
        }
        void presta(string& titolo){
            bool trovato = false;
            for(int i = 0; i < size; i++){
                if(libreria[i].titolo == titolo){
                    libreria[i].copie -= 1;
                    trovato = true;
                }
            }
            if(!trovato) cout<< "Libro non in elenco" <<endl;
        }

        int copie(string& titolo){
            int copiee = 0;
            for(int i = 0; i < size; i++){
                if(libreria[i].titolo == titolo){
                    copiee = libreria[i].copie;
                    return copiee;
                }
            }
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v): val(v), sinistro(nullptr), destro(nullptr) {}
};

bool stessaStruttura(nodo* a, nodo* b){
    if(a == nullptr && b == nullptr) return true;
    if(a == nullptr || b == nullptr) return false;
    return stessaStruttura(a->sinistro, b->sinistro) && stessaStruttura(a->destro, b->destro);
}


//es3
class Grafo {
    private:
        int n;
        vector<vector<int>> grafo;
    
    public:
        Grafo(int n) {
            this->n = n;
            grafo.resize(n);
        }
    
        void aggiungiArco(int u, int v) {
            grafo[u].push_back(v);
        }
    
        Grafo invertiGrafo() {
            Grafo gInvertito(n);
            for (int i = 0; i < n; i++) {
                for (int vicino : grafo[i]) {
                    gInvertito.aggiungiArco(vicino, i);
                }
            }
            return gInvertito;
        }
    
        int PercorsoDaSaT(int s, int t) {
            vector<bool> visitato(n, false);
            queue<int> q;
            vector<int> distanza(n, 0);
            q.push(s);
            visitato[s] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int vicino : grafo[u]) {
                    if (visitato[vicino]) continue;
                    visitato[vicino] = true;
                    q.push(vicino);
                    distanza[vicino] = distanza[u] + 1;
                    if (vicino == t) return distanza[vicino];
                }
            }
            return -1;
        }
    
        void findPaths(int u, vector<bool>& visited, vector<int>& path, vector<vector<int>>& allPaths) {
            visited[u] = true;
            path.push_back(u);
    
            bool hasNext = false;
            for (int v : grafo[u]) {
                if (!visited[v]) {
                    hasNext = true;
                    findPaths(v, visited, path, allPaths);
                }
            }
    
            if (!hasNext) {
                allPaths.push_back(path);
            }
    
            path.pop_back();
            visited[u] = false;
        }
    };
    
int main() {
    int n = 5;
    Grafo g(n);
    g.aggiungiArco(0, 1);
    g.aggiungiArco(0, 2);
    g.aggiungiArco(1, 3);
    g.aggiungiArco(2, 3);
    g.aggiungiArco(3, 4);
      
    int distanzaG = g.PercorsoDaSaT(0, 3);   
    Grafo gi = g.invertiGrafo();    
    int distanzaGI = gi.PercorsoDaSaT(0, 3);
       
    if (distanzaG > distanzaGI) {
        cout << "Percorso piu breve nel grafo invertito." << endl;
    } else if (distanzaG < distanzaGI) {
        cout << "Percorso piu breve nel grafo normale." << endl;
    } else {
        cout << "I percorsi sono uguali." << endl;
    }

    vector<bool> visitato(n, false);
    vector<int> path;
    vector<vector<int>> allPaths;
    g.findPaths(0, visitato, path, allPaths);
    for(int i = 0; i < allPaths.size(); i++){
        cout<< "Percorso: ";
        for(int j : allPaths[i]){
            cout << j << " ";
        }
        cout<<endl;
    }
}

