#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


//es1
class BranoMusicale{
    private:
        string titolo;
        string artista;
        unsigned durata;
        unsigned anno;
    
    public:
        BranoMusicale(const string tit, const string art, const unsigned dura, const unsigned an){
            titolo = tit;
            artista = art;
            durata = dura;
            anno = an;
        }

        string getTitolo() const {
            return titolo;
        }
        string getArtista() const {
            return artista;
        }
        unsigned getDurata() const {
            return durata;
        }
        unsigned getAnno() const {
            return anno;
        }
};
class NegozioDiMusica{
    private:
        map<string, vector<BranoMusicale>> negozio;
    
    public:
        void aggiungi(BranoMusicale& b){
            negozio[b.getArtista()].push_back(b);
        }
        vector<string> braniPerArtista(string& artista){
            if(negozio.find(artista) != negozio.end()){
                return negozio[artista];
            }
        }
        BranoMusicale piuCorto(){
            BranoMusicale piuCort;
            unsigned durata = INT_MAX;
            for(auto& [art, brani] : negozio){
                for(auto& b : brani){
                    if(b.getDurata() < durata){
                        piuCort = b;
                    }
                }
            }
            return piuCort;
        }
        vector<BranoMusicale> elencoCronologico(){
            vector<BranoMusicale> braniOrdinatiCronologicamente;
            for(auto& [art, brani] : negozio){
                for(auto& b : brani){
                    braniOrdinatiCronologicamente.push_back(b);
                }
            }
            sort(braniOrdinatiCronologicamente.begin(), braniOrdinatiCronologicament.end(), [](const BranoMusicale& a, const BranoMusicale& b){
                if(a.getAnno() != b.getAnno()){
                    return a.getAnno() < b.getAnno();
                }else{
                    return a.getDurata() < b.getDurata();
                }
            });
        }
};


//es2
struct nodo{
    string par;
    nodo* sinistro;
    nodo* destro;

    nodo(string p) : par(p), sinistro(nullptr), destro(nullptr) {}
};

void Parole(nodo* root, map<string, vector<string>>& parolePref, vector<string>& pref){
    if(root == nullptr) return;

    if(root->sinistro != nullptr && root->destro == nullptr){
        pref.push_back(root->par);
        parolePref[root->par].push_back(root->sinistro->par);
    }
    if(root->sinistro == nullptr && root->destro != nullptr){
        pref.push_back(root->par);
        parolePref[root->par].push_back(root->destro->par);
    }

    Parole(root->sinistro, parolePref, pref);
    Parole(root->destro, parolePref, pref);

}
bool verificaPref(nodo* root) {
    map<string, vector<string>> parolePref;
    vector<string> pref;

    Parole(root, parolePref, pref); 

    for (const string& parola : pref) {
        const vector<string>& figli = parolePref[parola];

        for (const string& f : figli) {
            if (f.rfind(parola, 0) != 0) {
                return false;
            }
        }
    }

    return true;
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
        }

    bool hasCycleK(int nodo, int partenza, int k, vector<bool>& visitato) {
        if (k == 0) {
            return nodo == partenza;  
        }

        visitato[nodo] = true;

        for (int vicino : grafo[nodo]) {
            if (!visitato[vicino] || vicino == partenza) {
                if (hasCycleK(vicino, partenza, k - 1, visitato)) return true;
            }
        }

        visitato[nodo] = false;
        return false;
    }

};