#include <iostream>
#include <map>
#include <queue>
using namespace std;


//es1
class sistemaOrdini{
    private:
        map<string, pair<string, unsigned>> ordini;
    
    public:
        void aggiungiOrdine(string& cliente, string& codProd, unsigned& quantita){
            ordini[cliente] = make_pair(codProd, quantita);
        }
        unsigned totArtCliente(string& cliente){
            return ordini[cliente].second;
        }
        map<string, unsigned> riepilogoOrdini(){
            map<string, unsigned> riepilogo;
            for(auto& ordine : ordini){
                riepilogo[ordine.first.first] += ordine.second.second;
            }
            return riepilogo;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool camminoAlternato(nodo* root, int prec){
    if(root == nullptr) return true;

    if(root->val % 2 == 0){
        if(prec % 2 == 0) return false;
    }
    if(root->val % 2 != 0){
        if(prec % 2 != 0) return false;
    }

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return camminoAlternato(root->sinistro, root->val) || camminoAlternato(root->destro, root->val);
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
            grafo[v].push_back(u); 
        }

        int contaConnessioni(){
            int connessioni = 0;
            vector<bool>& visitato(n, false);
            queue<int> q;
            for(int i = 0; i < n; i++){

                if(visitato[i]) continue;
                q.push(i);
                visitato[i] = true;

                while(!q.empty()){
                    int u = q.front();
                    connessioni++;
                    q.pop();
                    for(int v : grafo[u]){
                        if(visitato[v]) continue;
                        visitato[v] = true;
                        q.push(v);
                    }
                }
            }  
            return connessioni;
        }
};