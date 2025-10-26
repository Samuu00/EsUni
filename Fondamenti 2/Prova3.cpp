#include <iostream>
#include <map>
#include <vector>
using namespace std;

//es2
class Dispositivo{
    private:
        string nome;
        int id;
    
    public:
        Dispositivo(string n, int i): nome(n), id(i) {}

        string getNome(){ return nome; }
        int getID(){ return id; }

        virtual string getStato() const = 0;

        virtual ~Dispositivo() {}
};

class Lampadina : public Dispositivo{
    private:
        bool accesa;
        int luminosita;
    
    public:
        Lampadina(string n, int i, bool a, int l): Dispositivo(n, i), accesa(a), luminosita(l) {}

        string getStato() override {
            if(accesa) return format("Accesa, luminosita: {}", luminosita);
            return "Spenta";
        }
};

class Termostato : public Dispositivo{
    private:
        double tempTarget;
        bool riscAtt;

    public:
        Termostato(string n, int i, double t, bool r):Dispositivo(n, i), tempTarget(t), riscAtt(r) {}

        string getStato() override {
            if(riscAtt) return format("Riscaldamento attivo, (Target: {})", tempTarget);
            return format("Inattivo, (Target: {})", tempTarget);
        }
};

class Stanza{
    private:
        string nomeStanza;
        map<int, Dispositivo*> stanza;
    
    public:
        Stanza(string nome): nomeStanza(nome) {}


        bool aggDisp(Dispositivo* d){
            auto it = stanza.find(d->getID());

            if(it != stanza.end()) return false;

            stanza[d->getID()] = d;
            return true;
        }

        Dispositivo* findIt(int id){
            auto it = stanza.find(id);

            if(it != end) return it->second;

            return nullptr;
        }

        vector<string> getReportStato(){
            vector<string> report;

            for(auto& it : stanza){
                report.push_back(it.second->getStato());
            }
            return report;
        }

        ~Stanza(){
            for(auto& it : stanza){
                delete it->second;
            }
        }

};


//es3
enum Direzione { SIN, DES };
class AlberoB {
    private:
        char info;  
        AlberoB* p;          
        AlberoB* sx;          
        AlberoB* dx;                 

    public:
        
        AlberoB(char valore) : info(valore),  p(nullptr), sx(nullptr), dx(nullptr) {}

        ~AlberoB() {
            delete sx; 
            delete dx;
        }

        AlberoB* figlio(Direzione dir) {
            if (dir == SIN) {
                return this->sx;
            }
            return this->dx;
        }

        AlberoB* padre() {
            return this->p;
        }

        char radice() {
            return this->info;
        }

        bool foglia() {
            return (this->sx == nullptr && this->dx == nullptr);
        }

        static bool nullo(AlberoB* a) {
            return a == nullptr;
        }

        bool isCamminoValido(AlberoB* a, string s, int i){
            if(nullo(a)) return false;

            if(i == s.length()) return true;

            char curr = s[i];

            if(curr == 'L') return isCamminoValido(a->figlio(SIN), s, i + 1);
            if(curr == 'R') return isCamminoValido(a->figlio(DES), s, i + 1);

            return false;
        }
};


//es4
class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<int>> adj;

    public:
        Grafo(int n, vector<int> p) : numNodi(n), numArchi(0), adj(n, vector<int>(n, false)) {}

        int n() const {
            return numNodi;
        }
        int m() const {
            return numArchi;
        }

        void aggiungiArco(int i, int j, int p) {
            if (i < 0 || j < 0 || i >= numNodi || j >= numNodi) throw out_of_range("Indice nodo non valido");
            if (!adj[i][j]) {
                adj[i][j] = p;
                numArchi++;
            }
        }

        int trovaItinMax(int p, int a, const vector<int>& pu, vector<bool>& visitati, int tempo, int maxTempo, int punteggio){
            visitati[p] = true;

            if(tempo > maxTempo) return 0;

            if(p == a) return punteggio;

            int maxPunt = 0;

            for(int i = 0; i < n(); i++){
                if(adj[p][i] > 0 && !visitati[i]){
                    int ntempo = tempo + adj[p][i];
                    int nPunt = pu[i] + punteggio;
                    int punt = trovaItinMax(i, a, pu, visitati, ntempo, maxTempo, nPunt);
                    maxPunt = max(maxPunt, punt);
                }
            }

            visitati[p] = false;
            return maxPunt;
        }
};