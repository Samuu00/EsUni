#include <iostream>
using namespace std;

class ContoBancario{
    private:
        int numeroConto;
        double saldo;
    public:
        ContoBancario(){
            numeroConto = 0;
            saldo = 0.0;
        }
        ContoBancario(ContoBancario& cb){
            numeroConto = cb.numeroConto;
            saldo = cb.saldo;
        }
        ContoBancario(int nc, double s){
            numeroConto = nc;
            saldo = s;
        }

        void setNumeroConto(int nc){
            numeroConto = nc;
        }
        void setSaldo(int s){
            saldo = s;
        }
        
        int getNumeroConto(){
            return numeroConto;
        }
        int getSaldo(){
            return saldo;
        }
        
        void deposita(int denaro){
            saldo += denaro;
            cout<<"Hai depositato: "<< denaro;
        }
        void preleva(int prelievo){
            if (saldo <= prelievo){
                cout<<"Denaro insufficente";
            }
            else{
                saldo -= prelievo;
            }
        }
        void stampaSaldo(){
            cout<<", "<<"Saldo attuale: " << saldo;
        }
};

int main(){
    ContoBancario* conto = new ContoBancario[1];
    int nc;
    double s;
    cout<<"Inserisci numero conto e saldo per entrare: "<<endl;
    cin>> nc >> s;
    conto[0] = ContoBancario(nc, s);
    string op;
    cout<<"Inserisci -deposito se vuoi depositare, altrimenti -prelievo per prelevare: ";
    cin>> op;
    if(op == "deposito"){
        cout<<"Inserisci quanto vuoi depositare: ";
        double dep;
        cin>> dep;
        conto[0].deposita(dep);
        conto[0].stampaSaldo();
    }else if(op == "prelievo"){
        cout<<"Inserisci quanto vuoi prelevare: ";
        double prel;
        cin>> prel;
        conto[0].preleva(prel);
        conto[0].stampaSaldo();
    }
    return 0;
}

