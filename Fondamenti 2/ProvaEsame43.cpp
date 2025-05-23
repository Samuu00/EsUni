#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;


//es1
class gestionePrestiti{
    private:
        map<string, vector<pair<string, unsigned>>> prestiti;
    
    public:
        void registraPrestito(string& utente, string& libro, unsigned giorni){
            prestiti[utente].push_back(make_pair(libro, giorni));
        }
        unsigned totGiorniPres(string& utente){
            unsigned tot = 0;
            for(auto& p : prestiti[utente]){
                tot += p.second;
            }
            return tot;
        }
        map<string, vector<pair<string, unsigned>>> libroUtente(){
            map<string, vector<pair<string, unsigned>>> ris;
            for(auto& p : prestiti){
                for(auto& q : p.second){
                    ris[q.first].push_back(make_pair(p.first, q.second));
                }
            }
            return ris;
        }
        map<string, double> mediaLibri(){
            map<string, vector<pair<string, unsigned>>> orgPerLibri = libroUtente();
            map<string, double> ris;
            double media = 0;
            for(auto& p : orgPerLibri){
                media = 0;
                for(auto& v: p.second){
                    media += v.second;
                }
                ris[p.first] = media / p.second.size();
            }
            return ris;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool cammCrescDispari(nodo* root, int prec, int somma){
    if(root == nullptr) return false;

    somma += root->val;
    if(root->val <= prec) return false;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return somma % 2 != 0;
    }

    return cammCrescDispari(root->sinistro, root->val, somma) || cammCrescDispari(root->destro, root->val, somma);
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
        bool esisteCamminoSenzaVietati(int p, int a, unordered_set<int>& vietati, int k){
            if(p == a){
                if(k == 0) return true;
            }
            for(int v : grafo[p]){
                if(vietati.count(v)) return false;
                if(esisteCamminoSenzaVietati(v, a, vietati, k - 1)) return true;
            }
            return false;
        }
};