#include <iostream>
using namespace std;

class Auto {
    private:
        string modello, marca;
        int annoProd;
        double velocita;

    public:
        Auto() {
            modello = "";
            marca = "";
            annoProd = 0;
            velocita = 0;
        }
        Auto(Auto& a) {
            modello = a.modello;
            marca = a.marca;
            annoProd = a.annoProd;
            velocita = a.velocita;
        }
        Auto(string mo, string ma, int ap, double v = 0) {
            modello = mo;
            marca = ma;
            annoProd = ap;
            velocita = v;
        }


        void setModello(string mo) { 
            modello = mo; 
        }
        void setMarca(string ma) { 
            marca = ma; 
        }
        void setAnnoProd(int ap) { 
            annoProd = ap; 
        }

        
        string getModello() { 
            return modello; }
        string getMarca() { 
            return marca; 
        }
        int getAnnoProd() { 
            return annoProd; 
        }
        double getVelocita() { 
            return velocita; 
        }


        void accelera(double incremento) {
            velocita += incremento;
        }
        void frena(double decremento) {
            if (velocita - decremento > 0) {
                velocita -= decremento;
            } else {
                velocita = 0;
            }
        }
        void stampaStato() {
            cout << "Auto: [Modello: " << modello << ", Marca: " << marca << ", Anno di produzione: " 
            << annoProd << ", Velocita attuale: " << velocita << " Km/h]" <<endl;
        }
};

int main() {
    int a;
    cout << "Inserisci numero di macchine: ";
    cin >> a;

    Auto* autoArray = new Auto[a];

    for (int i = 0; i < a; i++) {
        string mo, ma;
        int ap;
        cout << "Inserisci marca, modello e anno di produzione della macchina: "<<endl;
        cin >> ma >> mo >> ap;
        autoArray[i] = Auto(mo, ma, ap);
    }

    int n;
    cout << "Inserisci quale auto scegliere (indice da 0 a " << a - 1 << "): ";
    cin >> n;

    if (n < 0 || n >= a) {
        cout << "Indice non valido!" << endl;
    } else {
        int b;
        cout << "Inserisci 1 per accelerare e 2 per frenare: ";
        cin >> b;

        if (b == 1) {
            double incremento;
            cout << "Inserisci valore di accelerazione (Km/h): ";
            cin >> incremento;
            autoArray[n].accelera(incremento);
            cout << "Hai scelto di accelerare la macchina " << autoArray[n].getModello() << " di: " << incremento << " Km/h" << endl;
        } else if (b == 2) {
            double decremento;
            cout << "Inserisci valore di decelerazione (Km/h): ";
            cin >> decremento;
            autoArray[n].frena(decremento);
            cout << "Hai scelto di frenare la macchina " << autoArray[n].getModello() << " di: " << decremento << " Km/h" << endl;
        } else {
            cout << "Scelta non valida!" << endl;
        }

        for (int i = 0; i < a; i++) {
            autoArray[i].stampaStato();
        }
    }
    delete[] autoArray;

    return 0;
}
