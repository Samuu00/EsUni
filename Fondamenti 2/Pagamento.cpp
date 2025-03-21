#include <iostream>
#include <vector>
using namespace std;

class Pagamento{
    public:
        virtual void elaboraPagamento(double importo, double soldiUtente) = 0;
        virtual ~Pagamento() {}
};

class CartaDiCredito : public virtual Pagamento{
    public:
        void elaboraPagamento(double importo, double soldiUtente) override {
            cout<<"Pagamento con carta avvenuto di importo: " << importo <<endl;
        }
};
class Contanti : public virtual Pagamento{
    public:
        void elaboraPagamento(double importo, double soldiUtente) override {
            double resto = 0.0;
            if (soldiUtente >= importo){
                if(soldiUtente - importo > 0){
                    resto = soldiUtente - importo;
                    cout<<"Pagamento in contanti avvenuto di importo: " << importo << " con resto di: " << resto <<endl;
                }
                else{
                    cout<<"Pagamento in contanti avvenuto di importo: " << importo <<endl;
                }
            }else{
                cout<<"Contante insufficente"<<endl;
            }
        }
};

void processaPagamenti(vector<Pagamento*>& metodiPagamento, vector<double> importi, double soldiUtente){
    if (metodiPagamento.size() != importi.size()) {
        cout << "Errore: il numero di metodi di pagamento non corrisponde al numero di importi.\n";
        return;
    }

    for (int i = 0; i < metodiPagamento.size(); i++) {
        cout << "Elaborazione pagamento #" << i + 1 << "...\n";
        metodiPagamento[i]->elaboraPagamento(importi[i], soldiUtente);
    }
}

int main(){
    int n;
    cout<<"Inserisci quanti pagamenti effettuare: ";
    cin>> n;
    vector<Pagamento*> metodiPagamento;
    vector<double> importi;
    for(int i = 0; i < n; i++){
        string t;
        cout<<"Inserisci come pagare le diverse transazioni(carta/contanti):"<<endl;
        cin>> t;
        if(t == "contanti"){
            metodiPagamento.push_back(new Contanti());
        }
        else if(t == "carta"){
            metodiPagamento.push_back(new CartaDiCredito());
        }
    }
    for(int i = 0; i < n; i++){
        double imp;
        cout<<"Inserisci importi: "<<endl;
        cin>> imp;
        importi.push_back(imp);
    }
    double su;
    cout<<"Inserisci denaro a tua disposizione: ";
    cin>> su;

    processaPagamenti(metodiPagamento, importi, su);

    for (auto pagamento : metodiPagamento) {
        delete pagamento;
    }

}
