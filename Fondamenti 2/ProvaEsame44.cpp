#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


//es1
class registroPrenotazioni{
    private:
        map<string, vector<pair<string, unsigned>>> prenotazioni;
    
    public:
        void prenota(string& utente, string& servizio, unsigned& slot){
            for(auto& p : prenotazioni){
                for(auto& s : p.second){
                    if(p.first == servizio && s.first == utente){
                        cout<< "Il cliente ha già prenotato questo servizio";
                        return;
                    }
                }
            }
            prenotazioni[servizio].push_back(make_pair(utente, slot));
        }
        unsigned slotTot(string& utente){
            unsigned tot = 0;
            for(auto& s : prenotazioni){
                for(auto& p : s.second){
                    if(p.first == utente) tot += p.second;
                }
            }
            return tot;
        }
        map<string, unsigned> totPerServ(){
            map<string, unsigned> tot;
            double slot = 0;
            for(auto& s : prenotazioni){
                for(auto& p : s.second){
                    slot += p.second;
                }
                tot[s.first] = slot;
            }
            return tot;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool percorsoCifrePari(nodo* root){
    if(root == nullptr) return false;

    string str = to_string(root->val);
    for(char& s : str){
        if((s - '0') % 2 != 0) return false;
    }

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return percorsoCifrePari(root->sinistro) || percorsoCifrePari(root->destro);
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

        bool camminoConSequenza(int u, vector<bool>& visitato, const vector<int>& sequenza, int index){
            if(index == sequenza.size()) return true;
            if(index < sequenza.size() && u == sequenza[index]) index++;
            for(int v : grafo[u]){
                if(camminoConSequenza(v, visitato, sequenza, index)) return true;
            }
            return false;
        }
};