#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
using namespace std;


void daDecimale(int n) {
    cout << "Decimale: " << n << endl;
    cout << "Binario: " << bitset<8>(n).to_string() << endl;
    cout << "Ottale: " << oct << n << endl;
    cout << "Esadecimale: " << hex << n << endl;
    cout << dec;
}


void daBinario(string bin) {
    int n = stoi(bin, nullptr, 2);
    cout << "Decimale: " << n << endl;
    cout << "Ottale: " << oct << n << endl;
    cout << "Esadecimale: " << hex << n << endl;
    cout << dec;
}


void daEsadecimale(string hexNum) {
    int n;
    stringstream ss;
    ss << hex << hexNum;
    ss >> n;
    cout << "Decimale: " << n << endl;
    cout << "Binario: " << bitset<8>(n).to_string() << endl;
    cout << "Ottale: " << oct << n << endl;
    cout << dec; 
}


void daOttale(string octNum) {
    int n = stoi(octNum, nullptr, 8);
    cout << "Decimale: " << n << endl;
    cout << "Binario: " << bitset<8>(n).to_string() << endl;
    cout << "Esadecimale: " << hex << n << endl;
    cout << dec; 
}

int main() {
    string sistema;
    string numero;

    while (true) {
        cin >> sistema;
        if (sistema == "exit") {
            break;
        }

        cin >> numero;

        if (sistema == "decimale") {
            daDecimale(stoi(numero));
        } else if (sistema == "binario") {
            daBinario(numero);
        } else if (sistema == "esadecimale") {
            daEsadecimale(numero);
        } else if (sistema == "ottale") {
            daOttale(numero);
        } else {
            cout << "Sistema non riconosciuto. Riprova." << endl;
        }

        cout << endl;
    }

    return 0;
}
