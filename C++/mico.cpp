#include <iostream>
#include <cstring>
using namespace std;

class Mico {
private:
    char nome[50];
    char cognome[50];

public:
    Mico() {
        cout << "Costruttore senza parametri" << endl;
    }

    Mico(const Mico& m) {
        strcpy(nome, m.nome);
        strcpy(cognome, m.cognome);
        cout << "Costruttore per copia" << endl;
    }

    Mico(const char* n, const char* c) {
        strcpy(nome, n);
        strcpy(cognome, c);
        cout << "Costruttore con parametri del nome e cognome di Mico" << endl;
    }

    const char* getNome() const {
        return nome;
    }

    void setNome(const char* n) {
        strcpy(nome, n);
    }

    const char* getCognome() const {
        return cognome;
    }

    void setCognome(const char* c) {
        strcpy(cognome, c);
    }
};

int main() {
    int m = 1;
    Mico* mico = new Mico[m];

    for (int i = 0; i < m; i++) {
        char n[50], c[50];
        cout << "Inserisci nome e cognome per la classe Mico" << endl;
        cin >> n >> c;
        mico[i] = Mico(n, c);
    }

    for (int i = 0; i < m; i++) {
        cout << "Nome: " << mico[i].getNome() << ", Cognome: " << mico[i].getCognome() << endl;
    }

    delete[] mico;
    return 0;
}
