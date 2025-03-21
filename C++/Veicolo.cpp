#include <iostream>
using namespace std;

class Veicolo{
    private:
        string marca, modello;
        int annoDiProd;
    
    public:
        Veicolo(){
            marca = "";
            modello = "";
            annoDiProd = 0;
        }
        Veicolo(Veicolo& v){
            marca = v.marca;
            modello = v.modello;
            annoDiProd = v.annoDiProd;
        }
        Veicolo(string ma, string mo, int ap){
            marca = ma;
            modello = mo;
            annoDiProd = ap;
        }

        void setMarca(string ma){ 
            marca = ma; 
        }
        void setModello(string mo){ 
            modello = mo; 
        }
        void setAnnoProd(int ap){ 
            annoDiProd = ap; 
        }

        string getMarca(){ 
            return marca; 
        }
        string getModello(){ 
            return modello; 
        }
        int getAnnoProd(){ 
            return annoDiProd; 
        }
};

class Auto : public Veicolo{
    private:
        int numeroPortiere;
    public:
        Auto() : Veicolo() { 
            numeroPortiere = 0; 
        }
        Auto(Auto& a) : Veicolo(a) { 
            numeroPortiere = a.numeroPortiere; 
        }
        Auto(string ma, string mo, int ap, int np) : Veicolo(ma, mo, ap) {
            numeroPortiere = np;
        }

        void setNumeroPortiere(int np){ 
            numeroPortiere = np; 
        }
        int getNumeroPortiere(){ 
            return numeroPortiere; 
        }

        void stampaAuto(){
            cout << "Auto[" << getMarca() << ", " << getModello() << ", " << getAnnoProd() << ", " << numeroPortiere << "]\n";
        }
};

class Moto : public Veicolo{
    private:
        string haSideCare;
    public:
        Moto() : Veicolo() { 
            haSideCare = ""; 
        }
        Moto(Moto& m) : Veicolo(m) { 
            haSideCare = m.haSideCare; }
        Moto(string ma, string mo, int ap, string hsc) : Veicolo(ma, mo, ap) {
            haSideCare = hsc;
        }

        void setHaSideCare(string hsc){ 
            haSideCare = hsc; 
        }
        string getHaSideCare(){ 
            return haSideCare; 
        }

        void stampaMoto(){
            cout << "Moto[" << getMarca() << ", " << getModello() << ", " << getAnnoProd() << ", " << haSideCare << "]\n";
        }
};

int main(){
    string veicolo;
    cout << "Inserisci -auto se vuoi inserire un'auto, altrimenti -moto se vuoi inserire una moto: ";
    cin >> veicolo;

    if(veicolo == "auto"){
        cout << "Inserisci quante auto vuoi aggiungere: ";
        int n;
        cin >> n;
        string ma, mo;
        int ap, np;
        Auto* autoArray = new Auto[n]; 
        for(int i = 0; i < n; i++){
            cin >> ma >> mo >> ap >> np;
            autoArray[i] = Auto(ma, mo, ap, np);
        }
        for(int i = 0; i < n; i++){
            autoArray[i].stampaAuto();
        } 
        delete[] autoArray;
    }
    else if (veicolo == "moto"){
        cout << "Inserisci quante moto vuoi aggiungere: ";
        int n;
        cin >> n;
        string ma, mo, hsc;
        int ap;
        Moto* motoArray = new Moto[n]; 
        for(int i = 0; i < n; i++){
            cin >> ma >> mo >> ap >> hsc;
            motoArray[i] = Moto(ma, mo, ap, hsc);
        }
        for(int i = 0; i < n; i++){
            motoArray[i].stampaMoto();
        } 
        delete[] motoArray;
    }
    return 0;
}