#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


//es1
class Farmaco{
    private:
        string nome;
        string principioAtt;
        int ggDallaScadenza;
    
    public:
        string getNome(){
            return nome;
        }
        string getPrincAtt(){
            return principioAtt;
        }
        int getGgScadenza(){
            return ggDallaScadenza;
        }
};
class magazzinoFarmaci{
    private:
        map<string, vector<Farmaco>> magazzino;
    public:
        void aggiungiFarmaco(Farmaco& f){
            magazzino[f.getPrincAtt()].push_back(f);
        }
        Farmaco restituisciFarmaco(string& princAtt){
            int minIndex = 0;
            int minGG = 100;
            Farmaco f;
            for(int i = 0; i < magazzino[princAtt].size(); i++){
                if(magazzino[princAtt][i].getGgScadenza() < minGG){
                    minGG = magazzino[princAtt][i].getGgScadenza();
                    minIndex = i;
                }
            }
            f = magazzino[princAtt][minIndex];
            magazzino[princAtt].erase(magazzino[princAtt].begin() + minIndex);
            return f;
        }

        vector<pair<string, int>> contaPerOgniPrinc(){
            vector<pair<string, int>> conti;
            for(auto& it : magazzino){
                conti.push_back(make_pair(it.first, it.second.size()));
            }
            return conti;
        }
};


//es2 
vector<int> numeriKpiuFrequenti(const vector<int>& dati, int k){
    map<int, int> freq;
    for(int i : dati){
        freq[i]++;
    }

    vector<pair<int, int>> kFreq(freq.begin() + freq.end());
    sort(kFreq.begin(), kFreq.end() [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });

    vector<int> kFreqFinal;
    for(int i = 0; i < k; i++){
        kFreqFinal.push_back(kFreq[i].first);
    }
    return kFreqFinal;
}


//es3
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

int percorsoSommaMassima(nodo* root){
    if(root == nullptr) return 0;

    if(root->sinistro == nullptr && root->destro == nullptr) return root->val;

    int sommaSinistra = percorsoSommaMassima(root->sinistro);
    int sommaDestra = percorsoSommaMassima(root->destro);

    return root->val + max(sommaSinistra, sommaDestra);
}
