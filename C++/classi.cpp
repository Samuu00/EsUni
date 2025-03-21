#include <iostream>
#include <limits>
using namespace std;

class Cerchio {
private:
    double raggio;
public:
    Cerchio() {
        cout << "Costruttore senza parametri di Cerchio" << endl;
    }
    Cerchio(const Cerchio& c) : raggio(c.raggio) {
        cout << "Sono nel costruttore per copia" << endl;
    }
    Cerchio(double r) : raggio(r) {
        cout << "Costruttore con un parametro di Cerchio" << endl;
    }
    double getRaggio() const {
        return raggio;
    }
    void setRaggio(double r) {
        raggio = r;
    }
    double getArea() const {
        return 3.14 * raggio * raggio;
    }
    bool operator==(const Cerchio& c) const {
        return raggio == c.raggio;
    }
};

class Cilindro {
private:
    Cerchio base;
    double altezza;
public:
    Cilindro() {
        cout << "Costruttore senza parametri di Cilindro" << endl;
    }
    Cilindro(double r, double h) : base(r), altezza(h) {
        cout << "Costruttore con due parametri di Cilindro" << endl;
    }
    Cilindro(const Cilindro& c) : base(c.base), altezza(c.altezza) {
        cout << "Costruttore per copia di Cilindro" << endl;
    }
    ~Cilindro() {
        cout << "Sono nel distruttore di Cilindro" << endl;
    }
    bool operator==(const Cilindro& c) const {
        return base == c.base && altezza == c.altezza;
    }
    void setAltezza(double h) {
        altezza = h;
    }
    double getAltezza() const {
        return altezza;
    }
    double getVolume() const {
        return altezza * base.getArea();
    }
    double getAreaBase() const {
        return base.getArea();
    }
    void stampa() const {
        cout << "Cilindro con area di base " << base.getArea() << " e altezza " << altezza << endl;
    }
};

int main() {
    int N;
    cout << "Inserisci il numero di cilindri: ";
    cin >> N;

    Cilindro* cilindri = new Cilindro[N];
    for (int i = 0; i < N; ++i) {
        double r, h;
        cout << "Inserisci raggio e altezza per il cilindro " << i + 1 << ": ";
        cin >> r >> h;
        cilindri[i] = Cilindro(r, h);
    }

    // 1. Trova la posizione nell'array del cilindro con l'area di base massima
    int posizioneMaxArea = 0;
    for (int i = 1; i < N; ++i) {
        if (cilindri[i].getAreaBase() > cilindri[posizioneMaxArea].getAreaBase()) {
            posizioneMaxArea = i;
        }
    }
    cout << "La posizione del cilindro con l'area di base massima è: " << posizioneMaxArea << endl;

    // 2. Trova il volume minimo
    double volumeMin = cilindri[0].getVolume();
    for (int i = 1; i < N; ++i) {
        if (cilindri[i].getVolume() < volumeMin) {
            volumeMin = cilindri[i].getVolume();
        }
    }
    cout << "Il volume minimo è: " << volumeMin << endl;

    // 3. Controlla se esistono due cilindri uguali
    bool esistonoUguali = false;
    for (int i = 0; i < N && !esistonoUguali; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (cilindri[i] == cilindri[j]) {
                esistonoUguali = true;
                break;
            }
        }
    }
    cout << (esistonoUguali ? "VERO" : "FALSO") << " - Esistono due cilindri uguali" << endl;

    // 4. Trova l'area di base minima tra cilindri con altezza > h
    double hInput;
    cout << "Inserisci un valore di altezza h: ";
    cin >> hInput;

    double areaBaseMin = numeric_limits<double>::max();
    for (int i = 0; i < N; ++i) {
        if (cilindri[i].getAltezza() > hInput && cilindri[i].getAreaBase() < areaBaseMin) {
            areaBaseMin = cilindri[i].getAreaBase();
        }
    }

    if (areaBaseMin == numeric_limits<double>::max()) {
        cout << "Non ci sono cilindri con altezza maggiore di " << hInput << endl;
    } else {
        cout << "L'area di base minima tra i cilindri con altezza maggiore di " << hInput << " è: " << areaBaseMin << endl;
    }

    // Dealloca l'array dinamico
    delete[] cilindri;

    return 0;
}
