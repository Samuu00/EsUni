#include <iostream>
#include <random>
#include <vector>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> f(0, 1);

class Sesso{
    public:
        virtual void faiSesso() = 0;
        virtual ~Sesso(){}
};

class Mamma : public virtual Sesso{
    private:
        string genere;
    public:
        Mamma():Sesso(){
            genere = "Femmina";
        }
        Mamma(Mamma& m) : Sesso(m){
            genere = m.genere;
        }
        Mamma(string g) : Sesso(){
            genere = g;
        }

        string getGenere(){
            return genere;
        }
        int faiFiglio() {
            int figlio = f(gen);
            return figlio;
        }
        void faiSesso() override {
            int risultato = faiFiglio(); 
            if(risultato == 1){
                cout << getGenere() << " ha iniziato a fare sesso e avra sicuro un bambino" << endl;
            } else {
                cout << getGenere() << " ha iniziato a fare sesso ma non credo avra un figlio" << endl;
            }
        }
};
class Papa : public virtual Sesso{
    private:
        string genere;
    public:
        Papa() : Sesso(){
            genere = "Maschio";
        }
        Papa(Papa& p) : Sesso(p){
            genere = p.genere;
        }
        Papa(string g) : Sesso(){
            genere = g;
        }

        string getGenere(){
            return genere;
        }
        int faiFiglio() {
            int figlio = f(gen);
            return figlio;
        }
        void faiSesso() override {
            int risultato = faiFiglio(); 
            if(risultato == 1){
                cout << getGenere() << " ha iniziato a fare sesso e diventera padre" << endl;
            } else {
                cout << getGenere() << " ha iniziato a fare sesso ma non credo sara padre" << endl;
            }
        }
};

int main(){
    int n;
    cout<<"Inserisci un numero pari maggiore di 0 per avere le coppie di mamma e papa: ";
    cin>> n;
    if (n%2 != 0 or n == 0){
        cout<<"Hai inserito un numero dispari o uno zero, sei frocio"<<endl;
    }
    else{
        vector<Sesso*> genitori;
        for(int i = 0; i < n; i++){
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    genitori.push_back(new Mamma());
                } else {
                    genitori.push_back(new Papa());
                }
            }
            
        }
        for(int i = 0; i < n; i++){
            genitori[i]->faiSesso();
        }
        for(int i = 0; i < n; i++){
            delete genitori[i];
        }
    }
    return 0;
}