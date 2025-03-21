#include <iostream>
using namespace std;  

class Libro{
    private:
        string titolo;
    public:
        Libro(){
            titolo = "";
        }
        Libro(Libro& l){
            titolo = l.titolo;
        }
        Libro(string t){
            titolo = t;
        }

        void setTitolo(string t){
            titolo = t;
        }
        string getTitolo(){
            return titolo;
        }

        string virtual getTipo() = 0;
        virtual ~Libro() {}
};

class Romanzo : public virtual Libro{
    private:
        string tipo;
    public:
        Romanzo() : Libro() {
            tipo = "";
        }
        Romanzo(Romanzo& r) : Libro(r) {
            tipo = r.tipo;
        }
        Romanzo(string t, string tp) : Libro(t) {
            tipo = tp;
        }

        string getTipo() override {
            cout<<"Hai inserito un romanzo"<<endl;
        }
};
class Saggio : public virtual Libro{
    private:
        string tipo;
    public:
        Saggio() : Libro(){
            tipo = "";
        }
        Saggio(Saggio& s) : Libro(s){
            tipo = s.tipo;
        }
        Saggio(string t, string tp) : Libro(t){
            tipo = tp;
        }

        string getTipo() override {
            cout<<"Hai inserito un saggio"<<endl;
        }
};

int main(){
    int n;
    cout<<"Inserisci quanti libri vuoi aggiungere: ";
    cin>> n;
    Libro* libri[n];
    for(int i = 0; i < n; i++){
        string tipo;
        cout<<"Inserisci tipo del libro (romanzo/saggio): ";
        cin>> tipo;
        if(tipo == "romanzo"){
            libri[i] = new Romanzo();
        }
        else if(tipo == "saggio"){
            libri[i] = new Saggio();
        }
    }
    for(int i = 0; i < n; i++){
        libri[i]->getTipo();
    }
    for(int i = 0; i < n; i++){
        delete libri[i];
    }
    return 0;
}