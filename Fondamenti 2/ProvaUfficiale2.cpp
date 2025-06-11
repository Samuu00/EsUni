#include <iostream>
#include <vector>
#include <map>
using namespace std;

//es1
class codaParrucchiere {
    private:
        vector<pair<string, vector<string>>> coda;

    public:
        codaParrucchiere(vector<string>& listaParrucchiere) {
            for (string& nome : listaParrucchiere) {
                coda.push_back({nome, {}});
            }
        }

        int parrConMenoClienti() {
            int min = INT_MAX;
            int pos = -1;
            for (int i = 0; i < coda.size(); i++) {
                if (coda[i].second.size() < min) {
                    min = coda[i].second.size();
                    pos = i;
                }
            }
            return pos;
        }

        bool aggiungiPrenotazione(string& cliente, string& parrucchiere) {
            for (auto& parr : coda) {
                if (parr.first == parrucchiere) {
                    if (parr.second.size() >= 10) {
                        int pos = parrConMenoClienti();
                        coda[pos].second.push_back(cliente);
                    } else {
                        parr.second.push_back(cliente);
                    }
                    return true;
                }
            }
            return false;
        }

        bool rimuoviPrenotazione(string& cliente) {
            for (auto& parr : coda) {
                int cont = 0;
                for (auto it = parr.second.begin(); it != parr.second.end(); ++it) {
                    if (*it == cliente && cont > 3) {
                        parr.second.erase(it);
                        return true;
                    }
                    cont++;
                }
            }
            return false;
        }

        int tempoAttesa(string& cliente) {
            for (auto& parr : coda) {
                int tot = 0;
                for (string& c : parr.second) {
                    tot += 15;
                    if (c == cliente) return tot;
                }
            }
            return -1;
        }
};
class codaParrucchiereAccurata {
    private:
        vector<pair<string, vector<string>>> coda;
        map<string, unsigned> tempoAtt;

    public:
        codaParrucchiereAccurata(map<string, unsigned> tempi, vector<string>& listaParrucchiere) {
            tempoAtt = tempi;
            for (string& nome : listaParrucchiere) {
                coda.push_back({nome, {}});
            }
        }

        int parrConMenoClienti() {
            int min = INT_MAX;
            int pos = -1;
            for (int i = 0; i < coda.size(); i++) {
                if (coda[i].second.size() < min) {
                    min = coda[i].second.size();
                    pos = i;
                }
            }
            return pos;
        }

        bool aggiungiPrenotazione(string& cliente, string& parrucchiere) {
            for (auto& parr : coda) {
                if (parr.first == parrucchiere) {
                    if (parr.second.size() >= 10) {
                        int pos = parrConMenoClienti();
                        coda[pos].second.push_back(cliente);
                    } else {
                        parr.second.push_back(cliente);
                    }
                    return true;
                }
            }
            return false;
        }

        bool rimuoviPrenotazione(string& cliente) {
            for (auto& parr : coda) {
                int cont = 0;
                for (auto it = parr.second.begin(); it != parr.second.end(); ++it) {
                    if (*it == cliente && cont > 3) {
                        parr.second.erase(it);
                        return true;
                    }
                    cont++;
                }
            }
            return false;
        }

        int tempoAttesaAccurato(string& cliente) {
            for (auto& parr : coda) {
                int tot = 0;
                for (string& c : parr.second) {
                    tot += tempoAtt[parr.first];
                    if (c == cliente) return tot;
                }
            }
            return -1;
        }
};


//es2
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

        int camminoMinimo(int p, int a, vector<bool>& visitato, int camm){
            if(p == a) return camm;
            visitato[p] = true;
            int minim = INT_MAX;
            for(int v : grafo[p]){
                if(visitato[v]) continue;
                int nuovoMin = camminoMinimo(grafo, v, a, visitato, camm + 1);
                minim = min(minim, nuovoMin);
            }
            visitato[p] = false;
            return minim;
        }

        Grafo nuovoGrafo(pair<unsigned, unsigned> arco){
            Grafo nuovoGrafo(n);
            for(int i = 0; i < n; i++){
                for(int j : grafo[i]){
                    if(i == arco.first && j == arco.second){
                        nuovoGrafo.aggiungiArco(arco.second, arco.first);
                    }else{
                        nuovoGrafo.aggiungiArco(i, j);
                    }
                }
            }
            return nuovoGrafo;
        }

        bool f(int p, int a, pair<unsigned, unsigned> arco){
            Grafo newGrafo = nuovoGrafo(arco);
            vector<bool> visitato(n, false);
            int camm = 0;
            int minim = camminoMinimo(p, a, visitato, camm);
            visitato.assign(n, false);
            camm = 0;
            int newMinim = newGrafo.camminoMinimo(p, a, visitato, camm);

            return newMinim < minim;
        }
};
