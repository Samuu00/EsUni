#include <iostream>
using namespace std;

class Motore{
    public:
        virtual void accendiMotore(){
            cout<<"Motore acceso della ";
        }
        virtual ~Motore() {}
};
class Ruote{
    public:
        virtual void giraRuote(){
            cout<<"Ruota girata della ";
        }
        virtual ~Ruote() {}
};

class Veicolo : public virtual Motore, public virtual Ruote{
    public:
        virtual ~Veicolo() {}
};

class Auto : public virtual Veicolo {
    public:
        void accendiMotore() override {
            Motore::accendiMotore(); 
            cout << "Macchina" << endl;
        }
        void giraRuote() override {
            Ruote::giraRuote(); 
            cout << "Macchina" << endl;
        }
};

class Moto : public virtual Veicolo {
    public:
        void accendiMotore() override {
            Motore::accendiMotore(); 
            cout << "Moto" << endl;
        }
        void giraRuote() override {
            Ruote::giraRuote(); 
            cout << "Moto" << endl;
        }
};

int main(){
    int n;
    cout<<"Inserisci quanti veicoli aggiungere: ";
    cin>> n;
    Veicolo* veicoli[n];
    for(int i = 0; i < n; i++){
        string v;
        cout<<"Inserisci -auto per inserire un'auto, altrimenti -moto per inserire una moto: ";
        cin>> v;
        if(v == "auto"){
            veicoli[i] = new Auto();
        }
        else if(v == "moto"){
            veicoli[i] = new Moto();
        }
    }
    for(int i = 0; i < n; i++){
        int m;
        cout<<"Inserisci 1 per accendere il motore dei veicoli, altrimenti 2 per girare le ruote dei veicoli: ";
        cin>> m;
        if(m == 1){
            veicoli[i]->accendiMotore();
        }
        else if(m == 2){
            veicoli[i]->giraRuote();
        }
    }
    for(int i = 0; i < n; i++){
        delete veicoli[i];
    }
    return 0;
}