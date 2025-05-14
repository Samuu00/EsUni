#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;


//es1
struct Cliente{
    string nome;
    int priorita;
};
class codaClienti{
    protected:
        vector<Cliente> coda;

    public:
        void aggiungi(Cliente& c){
            coda.push_back(c);
        }
        Cliente prossimo(){
            Cliente pross;
            int maxPri = coda[0].priorita;
            int maxIndex = 0;
            for(int i = 0; i < coda.size(); i++){
                if(coda[i].priorita > maxPri){
                    maxPri = coda[i].priorita;
                    maxIndex = i;
                }
            }
            pross = coda[maxIndex];
            coda.erase(coda.begin() + maxIndex);
            return pross;
        }

        bool vuota(){
            return coda.empty();
        }
};


//es2
vector<string> paroleComuni(const vector<string>& a, const vector<string>& b){
    set<string> paroleCom;
    unordered_set<string> bSet(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        if(bSet.find(a[i]) != bSet.end()){
            paroleCom.insert(a[i]);
        }
    }
    return vector<string>(paroleCom.begin(), paroleCom.end());
}


//es3
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr){}
};

bool esistePercorsoSomma(nodo* root, int somma){
    if(root == nullptr) return false;

    somma -= root->val;
    if(root->sinistro == nullptr && root->destro == nullptr) return somma == 0;

    return esistePercorsoSomma(root->sinistro, somma) || esistePercorsoSomma(root->destro, somma);
}


//es4
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

        bool esisteCamminoSemplice(int u, int v, vector<bool>& visitato){
            if(u == v) return true;
            visitato[u] = true;
            for(int i : grafo[u]){
                if(visitato[i]) continue;
                if(esisteCamminoSemplice(i, v, visitato)) return true;
            }
            return false;
        }
};