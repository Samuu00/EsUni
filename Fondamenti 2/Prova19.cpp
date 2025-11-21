#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

//es2
class Polinomio {
    private:
        double* coeffs; 
        int grado;      

        void resize(int nuovoGrado){
            double* newCoeffs = new double[nuovoGrado + 1];
            int oldGrado = grado;
            
            this->grado = nuovoGrado;

            for(int i = 0; i < oldGrado; i++){

                newCoeffs[i] = this->coeffs[i];
            }

            for (int i = grado + 1; i <= nuovoGrado; i++) {
                newCoeffs[i] = 0.0;
            }

            delete[] coeffs;
            coeffs = newCoeffs;
        }   

    public:
        Polinomio(): grado(0){
            this->coeffs = new double[this->grado + 1];
            coeffs[0] = 0.0;
        }
        
        ~Polinomio(){
            delete[] coeffs;
        }

        Polinomio(const Polinomio& other): grado(other.grado){
            this->coeffs = new double[other.grado + 1];

            for(int i = 0; i <= other.grado; i++){

                coeffs[i] = other.coeffs[i];
            }
        }

        Polinomio& operator=(const Polinomio& other){
            if(this == &other) return *this;

            int grado = other.grado;

            delete[] coeffs;

            this->coeffs = new double[grado + 1];

            for(int i = 0; i <= grado; i++){

                coeffs[i] = other.coeffs[i];
            }

            return *this;

        }
        
        void setCoeff(int g, double val){
            if(g > grado) resize(g);

            coeffs[g] = val;
        }
        
        double getCoeff(int g) const{
            if(g > grado) return 0;

            return coeffs[g];
        }
        
        double evaluate(double x) const{
            double res = 0.0;

            for(int i = 0; i <= grado; i++){

                if(coeffs[i] != 0.0) res += coeffs[i] * pow(x, i);
            }

            return res;
        }
        
        Polinomio operator+(const Polinomio& other) const{
            Polinomio p;

            int gr = max(this->grado, other.grado);
            p.resize(gr);

            for(int i = 0; i <= gr; i++){

                p.coeffs[i] = this->coeffs[i] + other.coeffs[i];
            }

            return p;
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

        void stampaAlbero(AlberoB* a){
            if(nullo(a)) return;

            queue<AlberoB*> q;
            q.push(a);
            
            while(!q.empty()){
                
                int liv = q.size();

                for(int i = 0; i < liv; i++){

                    AlberoB* curr = q.front(); q.pop();

                    cout<< curr->radice() << " ";

                    if(curr->figlio(SIN)) q.push(curr->figlio(SIN));
                    if(curr->figlio(DES)) q.push(curr->figlio(DES));
                }

                cout<< endl;
            }
        }
}; 


//es4
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(vector<vector<int>>& mappa, vector<vector<bool>>& mappaVisited, int r, int c, int& k, int& hp, int& count, bool& isFelice){
    int h = mappa[r][c];
    mappaVisited[r][c] = true;
    count++;

    for(int i = 0; i < 4; i++){

        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nc < 0 || nr >= mappa.size() || nc >= mappa[0].size()) continue;

        if(mappa[nr][nc] == h && !mappaVisited[nr][nc]){

            dfs(mappa, mappaVisited, nr, nc, k, h, count, isFelice);

        }else if(mappa[nr][nc] > h) isFelice = false;
    }
}

bool esisteIsolaFelice(const vector<vector<int>>& mappa, int& k){
    vector<vector<int>> mappaCopy = mappa;
    vector<vector<bool>> mappaVisited(mappa.size(), vector<bool>(mappa[0].size(), false));
    int count = 0;
    bool isFelice = true;

    for(int i = 0; i < mappa.size(); i++){
        for(int j = 0; j < mappa[0].size(); j++){

            if(!mappaVisited[i][j]){

                count = 0;
                isFelice = true;
                dfs(mappaCopy, mappaVisited, i, j, k, mappaCopy[i][j], count, isFelice);

                if(count >= k && isFelice) return true;
            }
        }
    }

    return false;
}