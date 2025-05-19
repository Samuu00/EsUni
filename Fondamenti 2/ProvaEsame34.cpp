#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


//es1
class messaggio{
    private:
        string autore;
        string contenuto;
        unsigned timeStamp;
    
    public:
        messaggio(const string& aut, const string& conten, const unsigned& timStmp){
            autore = aut;
            contenuto = conten;
            timeStamp = timStmp;
        }

        string getAutore() const{
            return autore;
        }
        string getConten() const{
            return contenuto;
        }
        unsigned getTimStmp() const{
            return timeStamp;
        }
};
class archivioMessaggi{
    private:
        vector<messaggio> archivio;
    
    public:

        void aggiungiMessaggio(const messaggio& m){
            archivio.push_back(m);
        }
        vector<string> cronologiaUtente(string& autore){
            vector<string> cronUtente;
            vector<messaggi> archivioProvv(archivio.begin(), archivio.end());
            sort(archivioProvv.begin(), archivioProvv.end(), [](const messaggio& a, const messaggio& b){
                return a.getTimStmp() > b.getTimStmp();
            });
            for(auto& s : archivioProvv){
                if(s.getAutore() == autore){
                    cronUtente.push_back(s.getConten());
                }
            }
        }
        vector<string> piuRecenti(unsigned k){
            vector<string> piuRecenti;
            vector<messaggi> archivioProvv(archivio.begin(), archivio.end());
            sort(archivioProvv.begin(), archivioProvv.end(), [](const messaggio& a, const messaggio& b){
                return a.getTimStmp() < b.getTimStmp();
            });
            for(size_t i = 0; i < k; i++){
                piuRecenti.push_back(archivioProvv[i].getConten());
            }
            return piuRecenti;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void verificaFoglieOrdinate(nodo* root, vector<int>& foglie){
    if(root == nullptr) return;

    if(root->sinistro == nullptr && root->destro == nullptr){
        foglie.push_back(root->val);
    }else{
        verificaFoglieOrdinate(root->sinistro, foglie);
        verificaFoglieOrdinate(root->destro, foglie);
    }
}

bool isSorted(nodo* root){
    vector<int> foglie;
    verificaFoglieOrdinate(root, foglie);
    return is_sorted(foglie.begin(), foglie.end());
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

        bool camminoKPassi(int p, int a, int& k){
            if(p == a && k == 0) return true;
            for(int v : grafo[p]){
                if(camminoKPassi(v, a, k-1)) return true;
            }
            return false;
        }
};