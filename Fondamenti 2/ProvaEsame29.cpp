#include <iostream>
#include <map>
#include <vector>
#include <sort>
using namespace std;


//es1
class Libro{
    private:
        string titolo;
        string autore;
        int annoPubb;
        string ISBN;
    
    public:
        Libro(string tit, string aut, int annoPu, string isbn){
            this->titolo = tit;
            this->autore = aut;
            this->annoPubb = annoPu;
            this->ISBN = isbn;
        }

        string getTitolo(){
            return titolo;
        }
        string getAutore(){
            return autore;
        }
        int getAnnoPubb(){
            return annoPubb;
        }
        string getISBN(){
            return ISBN;
        }
};
class Biblioteca{
    private:
        map<string, vector<Libro>> biblioteca;
    
    public:

        void aggiungiLibro(Libro& l){
            biblioteca[l.getAutore()].push_back(l);
        }
        bool esiste(string& isbn){
            for(auto& [autore, libri] : biblioteca){
                for(auto& l : libri){
                    if(l.getISBN() == isbn) return true;
                }
            }
            return false;
        }

        vector<string> nomiAnno(int& anno){
            for(auto& [autore, libri] : biblioteca){
                for(auto& l : libri){
                    if(l.getAnnoPubb() == anno) nomiAnno.push_back(l.getTitolo());
                }
            }
            return nomiAnno;
        }

        int contaLibriAutore(string& autore){
            int cont = 0;
            for(auto& [autore, libri]){
                cont += libri.size();
            }
            return cont;
        }
};


//es2
vector<string> filtraPerPrefisso(const vector<string>& parole, const string& pref){
    vector<string> risultato;
    for(auto& s : parole){
        if(s.size() >= pref.size() && s.substr(pref.size()) == pref){
            risultato.push_back(s);
        }
    }
    sort(risultato.begin(), risultato.end());
    return risultato;
}

vector<string> filtraPerSuffisso(const vector<string>& parole, const string& suff){
    vector<string> risultato;
    for(auto& s : parole){
        if(s.size() >= suff.size() && s.substr(s.size() - suff.size()) == suff){
            risultato.push_back(s);
        }
    }
    sort(risultato.begin(), risultato.end());
    return risultato;
}


//es3
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

int sommaFoglie(nodo* root){
    if(root == nullptr) return 0;

    if(root->sinistro == nullptr && root->destro == nullptr){
        return root->val;
    }
    return sommaFoglie(root->sinistro) + sommaFoglie(root->destro);
}
