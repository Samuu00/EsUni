#include <vector>
using namespace std;

class GrafoPesato {
private:
    int nodi;
    vector<vector<int>> matricePesi;
    vector<int> depositi;

public:
    GrafoPesato(int n, vector<int> dep) : nodi(n) {
        matricePesi.resize(n, vector<int>(n, 0));
        depositi = dep;
    }

    int n() const {
        return nodi;
    }

    int m() const {
        int count = 0;
        for (int i = 0; i < nodi; i++) {
            for (int j = 0; j < nodi; j++) {
                if (matricePesi[i][j] > 0) count++;
            }
        }
        return count;
    }

    void aggiungiArco(int i, int j, int peso) {
        if (i >= 0 && i < nodi && j >= 0 && j < nodi && peso > 0) {
            matricePesi[i][j] = peso;
        }
    }

    int dep(int i) const {
        if (i >= 0 && i < nodi) {
            return depositi[i];
        }
        return 0;
    }

    bool esercizio3(){
        vector<int> nodi(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matricePesi[i][j] > 0){
                    if(dep(i) < dep(j)) return false;
                    nodi[j] += matricePesi[i][j];
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(nodi[i] != 0 && nodi[i] >= dep(i)){
                return false;
            }
        }
        return true;
    }
};
