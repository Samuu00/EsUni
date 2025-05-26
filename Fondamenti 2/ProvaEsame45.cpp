#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;


//es1
class registroEsami{
    private:
        map<string, vector<pair<string, unsigned>>> esami;
    
    public:
        void registraEsame(string& studente, string& esame, unsigned& voto){
            for(auto& e : esami[studente]){
                if(e.first == esame){
                    cout<< "lo studente ha gia sostenuto quell'esame";
                    return;
                }
            }
            esami[studente].push_back(make_pair(esame, voto));
        }

        double mediaVotiStud(string& studente){
            double media = 0.0;
            int cont = 0;
            for(auto& e : esami[studente]){
                if(e.second < 18){
                    cont++;
                }else{
                    media += e.second;
                }
            }
            if(esami[studente].size() - cont != 0){
                media /= (esami[studente].size() - cont);
            }else{
                media = 0.0;
            }
            return media;
        }
        
        map<string, unsigned> numEsameSup(){
            map<string, unsigned> sup;
            for(auto& e : esami){
                for(auto& p : e.second){
                    if(p.second >= 18){
                        sup[p.first]++;
                    }
                }
            }
            return sup;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool percorsoCifraPariDispari(nodo* root){
    if(root == nullptr) return false;

    string val = to_string(root->val);
    char prima = val[0];
    char ultima = val[val.size() - 1];

    if((prima - '0') % 2 != 0 || (ultima - '0') % 2 == 0) return false;

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return percorsoCifraPariDispari(root->sinistro) || percorsoCifraPariDispari(root->destro);
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

        bool camminoLimitatoConObb(int p, int a, int max, unsigned cont, const unordered_set<int>& obbl, const unordered_set<int>& block){
            if(p != a && block.count(p)) return false;
            if(obbl.count(p)) cont++;
            if(max >= 0 && p == a){
                if (cont == obbl.size()) return true;
            }
            if (max == 0) return false;
            for(int v : grafo[p]){
                if(camminoLimitatoConObb(v, a, max - 1, cont, obbl, block)) return true;
            }
            return false;
        }
};

