#include <iostream>
#include <map>
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
        }
};


vector<string> kParolePiuFrequenti(const vector<string>& Parole, int k){
    map<string, int> paroleFrequenze;
    for(int i = 0; i < Parole.size(); i++){
        if(paroleFrequenze.find(Parole[i]) != paroleFrequenze.end()){
            paroleFrequenze[Parole[i]]++;
        }
    }
    for(int i = 0; i < paroleFrequenze.size(); i++){
        for(int j = i; j < paroleFrequenze.size(); i++){
            if(paroleFrequenze[i] < paroleFrequenze[j]){
                swap(paroleFrequenze[i], paroleFrequenze[j]);
            }
        }
    }
    vector<string> paroleK;
    for(int i = 0; i < k; i++){
        paroleK.push_back(paroleFrequenze[i]);
    }
    return paroleK;
}


struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool esistePercorcoSomma(nodo* root, int somma){
    if(root == nullptr) return false;

    if(root->sinistro == nullptr && root->destro == nullptr) return somma == 0;

    somma -= root->val;

    return esistePercorcoSomma(root->sinistro, somma) || esistePercorcoSomma(root->destro, somma);
}