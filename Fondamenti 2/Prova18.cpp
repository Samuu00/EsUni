#include <iostream>
#include <vector>
using namespace std;

//es2
class Abbonamento{
    private:
        string nomeServizio;
        double costoMensile;
    
    public:
        Abbonamento(const string& nS, double& cM): nomeServizio(nS), costoMensile(cM) {}

        string getNomeServ() const { return nomeServizio; }
        double getCostoMensile() const { return costoMensile; }

        virtual double calcolaAnnuale() const = 0;
        virtual string getDettagli() const = 0;

        virtual ~Abbonamento() {}
};

class StreamingVideo : public Abbonamento{
    private:
        int schermiContemp;
    
    public:
        StreamingVideo(const string& nS, double& cM, int sC): Abbonamento("Streaming", cM), schermiContemp(sC) {}
        
        double calcolaAnnuale() const override { return getCostoMensile() * 12; }
        string getDettagli() const override { return "Video: [" + getNomeServ() + "], Schermi: " + to_string(schermiContemp); }
};

class CloudStorage : public Abbonamento{
    private:
        int spazioGB;

    public:
        CloudStorage(const string& nS, double& cM, int sGB): Abbonamento("Cloud", cM), spazioGB(sGB) {}

        double calcolaAnnuale() const override {
            double ann = getCostoMensile() * 12;

            if(spazioGB > 1000){
                ann *= 0.9;
                return ann;
            }

            return ann;
        }
        string getDettagli() const override { return "Cloud: [" + getNomeServ() + "], GB: [" + to_string(spazioGB) + "]"; }
};

class PortafoglioAbbonamenti{
    private:
        vector<Abbonamento*> abbonamenti;
    
    public:
        PortafoglioAbbonamenti(){}

        ~PortafoglioAbbonamenti(){
            for(auto& it : abbonamenti){
                delete it;
            }
        }   
        
        void aggiungiAbbonamento(Abbonamento* a){
            abbonamenti.push_back(a);
        }

        double stimaSpesaTot(){
            double tot = 0;
            for(auto& it : abbonamenti){

                tot += it->calcolaAnnuale();
            }

            return tot;
        }

        vector<Abbonamento*> filtraPerBudget(double maxBudget) const {
            vector<Abbonamento*> filter;

            for(auto& it : abbonamenti){

                if(it->getCostoMensile() <= maxBudget) filter.push_back(it);
            }

            return filter;
        }
};


//es3
enum Direzione { SIN, DES };
class AlberoB {
    private:
        int info;  
        AlberoB* p;          
        AlberoB* sx;          
        AlberoB* dx;                 

    public:
        
        AlberoB(int valore) : info(valore),  p(nullptr), sx(nullptr), dx(nullptr) {}

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

        int radice() {
            return this->info;
        }

        bool foglia() {
            return (this->sx == nullptr && this->dx == nullptr);
        }

        static bool nullo(AlberoB* a) {
            return a == nullptr;
        }

        void conta(AlberoB* a, int& numNodi, int liv){
            if(nullo(a)) return;

            if(liv % 2 == 0) numNodi++;


            conta(a->figlio(SIN), numNodi, liv + 1);
            conta(a->figlio(DES), numNodi, liv + 1);
        }

        int contaLivelloPari(AlberoB* a){
            int numNodi = 0;
            int liv = 0;

            conta(a, numNodi, liv);

            return numNodi;
        }
};  


//es4
class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<int>> adj;

    public:
        Grafo(int n) : numNodi(n), numArchi(0), adj(n, vector<int>(n, -1)) {}

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

        bool esisteCamminoConCarica(int start, int end, int cI, vector<bool>& visitati){
            visitati[start] = true;

            if(start == end){

                return cI >= 0;
            }

            if(cI <= 0) return false;

            for(int i = 0; i < n(); i++){

                if(adj[start][i] > -1 && !visitati[i]){

                    int peso = adj[start][i];

                    if(cI >= peso){

                        if(esisteCamminoConCarica(i, end, cI - peso, visitati)) return true;
                    }
                }
            }
            
            return false;
        }
};

