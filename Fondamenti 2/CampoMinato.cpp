#include <iostream>
#include <vector>
using namespace std;

void Campo(vector<vector<int>>& campo) {
    for(size_t i = 0; i < campo.size(); i++) {
        for (size_t j = 0; j < campo[i].size(); j++) {
            campo[i][j] = 0;
        }
    }
}

void piazzaBombe(vector<vector<int>>& campo, vector<pair<int, int>>& bombe){
    for (auto bomba : bombe) {
        int riga = bomba.first;
        int colonna = bomba.second;
        campo[riga][colonna] = 1;
    }
}

void stampaCampo(vector<vector<int>>& campo) {
    for (const auto& riga : campo) {
        for (int cella : riga) {
            cout << cella << " ";
        }
        cout << endl;
    }
}

int contaBombeAdiacenti(const vector<vector<int>>& campo, int riga, int colonna) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; 
            int newRow = riga + i;
            int newCol = colonna + j;
            if (newRow >= 0 && newRow < campo.size() && newCol >= 0 && newCol < campo[0].size()) {
                count += campo[newRow][newCol];
            }
        }
    }
    return count;
}


int main() {
    int rc, numBombe;
    cout << "Inserisci il numero di righe e colonne: ";
    cin >> rc;
    vector<vector<int>> campo(rc, vector<int>(rc, 0));
    cout << "Inserisci il numero di bombe: ";
    cin >> numBombe;
    vector<pair<int, int>> bombe(numBombe);
    for(int i = 0; i < numBombe; i++) {
        cout << "Inserisci la posizione della bomba " << i + 1 << ": ";
        cin >> bombe[i].first >> bombe[i].second;
    }
    Campo(campo);
    piazzaBombe(campo, bombe);
    cout << "Campo minato: " << endl;
    stampaCampo(campo);
    cout << "Campo minato con bombe adiacenti: " << endl;
    for (int i = 0; i < rc; i++) {
        for (int j = 0; j < rc; j++) {
            if (campo[i][j] == 1) {
                cout << "* ";
            } else {
                cout << contaBombeAdiacenti(campo, i, j) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}



