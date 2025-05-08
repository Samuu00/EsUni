#include <iostream>
#include <queue>
using namespace std;


//es1
struct Record{
    string parola;
    int conteggio;
};
class contaParola{
    private:
        int maxSize;
        int size;
        Record* parole;
    public:
        contaParola(){
            this->maxSize = 100;
            this->size = 0;
            this->parole = new Record[maxSize];
        }
        void aggiungi(string& par){
            if(size == 0){
                parole[0].parola = par;
                size++;
                return;
            }
            for(auto p : parole){
                if(p.parola == par){
                    p.conteggio++;
                    return;
                }
            }
            parole[size + 1].parola = par;
            parole[size + 1].conteggio = 1;
            size++;
        }
        string piuFrequente(){
            int max = parole[0];
            int index = 0;
            for(int i = 0; i < size; i++){
                if(parole[i].conteggio > max){
                    max = parole[i].conteggio;
                    index = i;
                }
            }
            return parole[index].parola;      
        }
        int frequenza(string& par){
            int freq = 0;
            for(auto p : parole){
                if(p.parola == par){
                    freq = p.conteggio;
                }
            }
            return freq;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool isBST(nodo* root, int minVal, int maxVal){
    if(root == nullptr) return true;
    if((root->sinistro != nullptr && root->sinistro->val >= root->val) && root->sinistro->val < minVal) return false;
    if((root->destro != nullptr && root->destro->val <= root->val) && root->destro->val > maxVal) return false;
    return isBST(root->sinistro, minVal, maxVal) && isBST(root->destro, minVal, maxVal);
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
        bool camminoConVincoli(int s, int t, vector<pair<int, int>> vincoli){
            queue<int> q;
            vector<bool> visitato(n, false);
            q.push(s);
            visitato[s] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t){
                    for(pair<int, int> vinc : vincoli){
                        if(visitato[vinc.first] && visitato[vinc.second]) return false;
                        return true;
                    }
                }

                for(int v : grafo[u]){
                    if(visitato[v]) continue;
                    visitato[v] = true;
                    q.push(v);
                }
            }
            return false;
        }
};