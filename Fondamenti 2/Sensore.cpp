#include <iostream>
#include <random>
#include <vector>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> t(-10, 40); 
uniform_int_distribution<> p(950, 1050); 

class Sensore {
public:
    virtual void leggiValore() = 0;
    virtual string getTipo() = 0;
    virtual double getValore() = 0;
    virtual ~Sensore() {}
};

class SensoreTemperatura : public Sensore {
private:
    string tipo;
    double temperatura;
public:
    SensoreTemperatura() {
        tipo = "Temperatura";
        temperatura = 0.0;
    }
    void leggiValore() override {
        temperatura = t(gen);
    }
    string getTipo() override {
        return tipo;
    }
    double getValore() override{
        return temperatura;
    }
};

class SensorePressione : public Sensore {
private:
    string tipo;
    double pressione;
public:
    SensorePressione() {
        tipo = "Pressione";
        pressione = 0.0;
    }
    void leggiValore() override {
        pressione = p(gen);
    }
    string getTipo() override {
        return tipo;
    }
    double getValore() override {
        return pressione;
    }
};

void visualizzaDati(vector<Sensore*> sensori) {
    for (auto sensore : sensori) {
        sensore->leggiValore();
        cout << sensore->getTipo() << ": " << sensore->getValore() << endl;
    }
}

int main() {
    int n;
    cout << "Inserisci quanti sensori vuoi creare: ";
    cin >> n;
    vector<Sensore*> sensori;
    
    for (int i = 0; i < n; i++) {
        string tp;
        cout << "Inserisci (temp/press) per un sensore di temperatura o pressione: ";
        cin >> tp;
        
        if (tp == "temp") {
            sensori.push_back(new SensoreTemperatura());
        } else if (tp == "press") {
            sensori.push_back(new SensorePressione());
        }
    }
    
    visualizzaDati(sensori);
    
    for (auto sensore : sensori) {
        delete sensore;
    }
    
    return 0;
}
