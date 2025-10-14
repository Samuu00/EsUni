#include <iostream>
#include <vector>
#include <set>
using namespace std;


//es2
class Prenotazione{
    private:
        string nome;
        int nStanza;
        string dataArr;
        string dataPart;

    public:
        Prenotazione(string n, int s, string dA, string dP){
            nome = n;
            nStanza = s;
            dA = dataArr;
            dP = dataPart;
        }

        string getNome() { return nome; }
        int getStanza() { return nStanza; }
        string getDataArr() {return dataArr; }
        string getDataPart() {return dataPart; }
};
class Hotel{
    private:
        vector<Prenotazione> prenotazioni;
    
    public:
        void aggPrenotazione(Prenotazione& p){
            prenotazioni.push_back(p);
        }

        bool searchForDate(int stanza, string date){
            for(auto& v : prenotazioni){
                if(v.getStanza() == stanza && v.getDataArr() == date){
                    cout<< "Prenotazione in data: " << date << "esistente";
                    return false;
                }
            }
            return true;
        }

        vector<Prenotazione> prenList(string cliente){
            vector<Prenotazione> pren;
            for(auto& p : prenotazioni){
                if(p.getNome() == cliente) pren.push_back(p);
            }
            return pren;
        }

        vector<Prenotazione> prenDate(string date){
            vector<Prenotazione> pren;
            for(auto& p : prenotazioni){
                if(p.getDataArr() == date) pren.push_back(p);
            }
            return pren;
        }
};


//es3
struct node{
    int val;
    node* sinistro;
    node* destro;

    node(int v): val(v), sinistro(nullptr), destro(nullptr) {}
};

int sum_at_depth(node* root, int d){
    if(root == nullptr) return 0;

    if(d == 0) return root->val;

    return sum_at_depth(root->sinistro, d-1) + sum_at_depth(root->destro, d-1);
}


//es4
vector<int> find_influencers(const Grafo& g) {
    int n = g.n();
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (g(v, u)) indegree[u]++;
        }
    }

    int maxFollow = *max_element(indegree.begin(), indegree.end());

    vector<int> influencers;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == maxFollow) influencers.push_back(i);
    }

    return influencers;
}


vector<pair<int, int>> sovrapponibili(Grafo& g) {
    set<int> visitati;
    vector<int> numArchiEntrata(g.n(), 0);
    vector<int> numArchiUscita(g.n(), 0);
    vector<pair<int, int>> coppie;

   
    for(int i = 0; i < g.n(); i++) {
        for(int j = 0; j < g.n(); j++) {
            if(g.a(i, j)) {
                numArchiUscita[i]++;
                numArchiEntrata[j]++;
            }
            visitati.insert(j);
        }
    }

    for(int i = 0; i < g.n(); i++) {
        for(int j = i+1; j < g.n(); j++) { 
            if(numArchiEntrata[i] == numArchiEntrata[j] && numArchiUscita[i] == numArchiUscita[j]) {
                bool uguali = true;

                for(int v : visitati) {
                    if(g.a(v, i) != g.a(v, j)) {
                        uguali = false;
                        break;
                    }
                }
                if(uguali) {
                    for(int k : visitati) {
                        if(g.a(i, k) != g.a(j, k)) {
                            uguali = false;
                            break;
                        }
                    }
                }
                if(uguali) coppie.push_back({i, j});
            }
        }
    }
    return coppie;
}


