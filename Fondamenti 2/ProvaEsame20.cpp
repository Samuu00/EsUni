#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//es1
class agendaImpegni{
    private:
        vector<pair<string, vector<string>>> agenda;
    public:
        agendaImpegni(){
            agenda.push_back(make_pair("Lunedi", vector<string>{}));
            agenda.push_back(make_pair("Martedi", vector<string>{}));
            agenda.push_back(make_pair("Mercoledi", vector<string>{}));
            agenda.push_back(make_pair("Giovedi", vector<string>{}));
            agenda.push_back(make_pair("Venerdi", vector<string>{}));
        }

        bool aggiungiImpegni(string& giorno, string& impegno){
            for(int i = 0; i < agenda.size(); i++){
                if(agenda[i].first == giorno){
                    if(agenda[i].second.size() < 5){
                        agenda[i].second.push_back(impegno);
                        return true;
                    }
                }
            }
            return false;
        }

        bool rimuovi(string& giorno, string& impegno){
            for(int i = 0; i < agenda.size(); i++){
                if(agenda[i].first == giorno){
                    for(int j = 0; j < agenda[i].second.size(); j++){
                        if(agenda[i].second[j] == impegno){
                            agenda[i].second.erase(agenda[i].second.begin() + j);
                        }
                    }
                }
            }
        }

        vector<string> impegniQuelGiorno(string& giorno){
            for(int i = 0; i < agenda.size(); i++){
                if(agenda[i].first == giorno){
                    return agenda[i].second;
                }
            }
        }

};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr){}
};

bool camminoK(nodo* root, int k, int somma){
    if(root == nullptr) return false;
    
    if(somma == k) return true;
    somma += root->val;

    return camminoK(root->sinistro, k, somma) || camminoK(root->destro, k, somma);
};


//es3
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;
    public:
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        bool possibileConsegna(vector<int>& pacchi, int k){
            queue<int> q;
            int viaggi = 0;
            q.push(0);
            while(!q.empty()){
                int u = q.front();
                for(int v : grafo[u]){
                    viaggi++;
                    pacchi[v]--;
                    if(pacchi[v] == 0){
                        q.pop();
                        q.push(v);
                    }
                    if(viaggi > k) return false;
                }
            }
            return true;
        }
};
