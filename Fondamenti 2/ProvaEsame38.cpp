#include <iostream>
#include <vector>
#include <map>
using namespace std;


//es1
class anagrafeStudente {
    private:
        map<string, vector<pair<string, unsigned>>> anagrafe;

    public:
        void registraEsame(const string& matr, const string& esame, unsigned voto) {
            anagrafe[matr].push_back({esame, voto});
        }

        map<string, vector<pair<string, unsigned>>> OrganizzaPerCorso() {
            map<string, vector<pair<string, unsigned>>> anagrafePerCorso;

            for (const auto& studente : anagrafe) {
                const string& matricola = studente.first;
                const auto& esami = studente.second;
                for (const auto& esame : esami) {
                    anagrafePerCorso[esame.first].push_back({matricola, esame.second});
                }
            }
            return anagrafePerCorso;
        }

        double mediaStud(const string& mat) {
            const auto& esami = anagrafe[mat];
            double somma = 0.0;
            for (const auto& s : esami) {
                somma += s.second;
            }
            return somma / esami.size();
        }

        map<string, double> mediaStudPerCorso() {
            map<string, vector<pair<string, unsigned>>> anagrafePerCorso = OrganizzaPerCorso();
            map<string, double> mediaPerCorso;

            for (const auto& corso : anagrafePerCorso) {
                double somma = 0.0;
                for (const auto& studente : corso.second) {
                    somma += studente.second;
                }
                mediaPerCorso[corso.first] = somma / corso.second.size();
            }

            return mediaPerCorso;
        }
};


//es2
struct nodo {
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

bool esistePercorsoDiffK(nodo* root, int prec, int k){
    if(root == nullptr) return false;

    if(abs(root->val - prec) > k) return false;

    if(root->sinistro == nullptr && root->destro == nullptr) return true;

    return esistePercorsoDiffK(root->sinistro, root->val, k) || esistePercorsoDiffK(root->destro, root->val, k);
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

        bool esisteCamminoConObbl(int p, int a, unordered_set<int>& obbl, vector<bool>& visitato, int cont){
            if(obbl.count(p)) cont++;
            if(p == a && cont == obbl.size()) return true;
            visitato[p] = true;
            for(int v : grafo[p]){
                if(visitato[v]) continue;
                if(esisteCamminoConObbl(v, a, obbl, visitato)) return true;
            }
            visitato[p] = false;
            if(obbl.count(p)) cont--;
            return false;
        }
};
