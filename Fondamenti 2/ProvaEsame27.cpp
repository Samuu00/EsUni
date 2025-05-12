#include <iostream>
#include <map>
#include <sort>
using namespace std;



//es1
class Prodotto{
    private:
        string nome;
        string categoria;
        double prezzo;
        bool disponibile;
    
    public:
        Prodotto(string n, string c, double p, bool d){
            nome = n;
            categoria = c;
            prezzo = p;
            disponibile = d;
        }

        string getNome(){ 
            return nome;
        }
        string getCategoria(){
            return categoria;
        }
        double getPrezzo(){
            return prezzo;
        }
        bool getDisponibile(){
            return disponibile;
        }
};
class Magazzino{
    private:
        map<string, vector<Prodotto>> magazzino;
    public:

        void aggiungiProdotto(Prodotto& p){
            magazzino[p.getCategoria()].push_back(p);
        }

        Prodotto estraiEconomico(string& categoria){
            Prodotto e;
            int minIndex = 0;
            int minPrezzo = 0;
            for(int i = 0; i < magazzino[categoria].size(); i++){
                if(magazzino[categoria][i].getPrezzo() < minPrezzo){
                    minPrezzo = magazzino[categoria][i].getPrezzo();
                    minIndex = i;
                }
            }
            e = magazzino[categoria][minIndex];
            magazzino[categoria].erase(magazzino[categoria].begin() + minIndex);
            return e;
        }
};

struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool esistePercorcoSomma(nodo* root, int somma){
    if(root == nullptr) return false;

    somma -= root->val;

    if(root->sinistro == nullptr && root->destro == nullptr) return somma == 0;

    return esistePercorcoSomma(root->sinistro, somma) || esistePercorcoSomma(root->destro, somma);
}


vector<string> kParolePiuFrequenti(const vector<string>& Parole, int k){
    map<string, int> paroleFrequenze;
    for(string parola : Parole){
        paroleFrequenze[parola]++;
    }
    
    vector<pair<string, int>> freqVec(paroleFrequenze.begin() + paroleFrequenze.end());
    sort(freqVec.begin() + freqVec.end(), [](pair<string, int>& a, pair<string, int>& b)){
        return a.second > b.second;
    }

    vector<string> paroleK;
    for(int i = 0; i < k; i++){
        paroleK.push_back(freqVec[i]. first);
    }
    return paroleK;
}
