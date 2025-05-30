#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
using namespace std;


//es1
struct operazione{
    string nome_utente;
    unsigned cod_ope;
    double temp_esec;
};
class storicoOperazioni{
    private:
        int maxSize;
        int size;
        operazione* storico;
    
    public:
        storicoOperazioni(){
            this->maxSize = 100;
            this->size = 0;
            this->storico = new operazione[this->maxSize];
        }
        ~storicoOperazioni(){
            delete[] storico;
        }

        void registraOperazione(string& nome_utente, unsigned& cod_ope, double& temp_esec){
            if(size == maxSize) throw runtime_error("Storico pieno");

            storico[size].nome_utente = nome_utente;
            storico[size].cod_ope = cod_ope;
            storico[size].temp_esec = temp_esec;
            size++;
        }

        double TempoTotUtente(string& utente){
            double tempoTot = 0.0;
            for(int i = 0; i < size; i++){
                if(storico[i].nome_utente == utente) tempoTot += storico[i].temp_esec;
            }
            return tempoTot;
        }

        map<unsigned, double> tempoMedOpe(){
            map<unsigned, double> tempoMed;
            map<unsigned, int> freq;
            for(int i = 0; i < size; i++){
                freq[storico[i].cod_ope]++;
                tempoMed[storico[i].cod_ope] += storico[i].temp_esec;
            }
            for(auto& it : tempoMed){
                tempoMed[it.first] = tempoMed[it.first] / freq[it.first];
            }
            return tempoMed;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool percorsoSommaMinima(nodo* root, int somma, int profMax, int livello){
    if(root == nullptr) return false;

    somma -= root->val;
    
    if(root->sinistro == nullptr && root->destro == nullptr){
        return somma >= 0 && livello <= profMax;
    }

    return percorsoSommaMinima(root->sinistro, somma, profMax, livello + 1) || percorsoSommaMinima(root->destro, somma, profMax, livello + 1);
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

        bool camminoAlternato(int p, int a, vector<bool>& visitato){
            if(p == a) return true;
            visitato[p] = true;
            for(int i : grafo[p]){
                for(int j : grafo[i]){
                    if(visitato[j]) continue;
                    if(camminoAlternato(j, a, visitato)) return true;
                }
            }
            visitato[p] = false;
            return false;
        }
};
