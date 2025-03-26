#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SocialNetwork {
public:
    int utenti;
    vector<vector<int>> amici;

    SocialNetwork(int n) {
        utenti = n;
        amici.resize(n);
    }

    void aggiungiAmicizia(int u, int v) {
        amici[u].push_back(v);
        amici[v].push_back(u); 
    }

    void suggerisciAmici(int utente) {
        queue<int> q;
        vector<bool> visitato(utenti, false);

        q.push(utente);
        visitato[utente] = true;

        cout << "Suggerimenti di amicizia per " << utente << ":\n";

        while (!q.empty()) {
            int nodo = q.front();
            q.pop();

            for (int vicino : amici[nodo]) {
                if (!visitato[vicino]) {
                    cout << "- Potresti conoscere l'utente " << vicino << endl;
                    visitato[vicino] = true;
                    q.push(vicino);
                }
            }
        }
    }
    void stampaGrafo(){
        for(int i = 0; i < utenti; i++){
            cout << "Nodo " << i << ": ";
            for(int vicino : amici[i]){
                cout << vicino << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    int n;
    cout << "Quanti nodi vuoi inserire?: " << endl;
    cin >> n;
    SocialNetwork sn(n);
    int m;
    cout << "Quanti archi vuoi inserire?: " << endl;
    cin >> m;
    for(int i = 0; i < m; i++){
        int n, m;
        cout << "Inserisci il vertice di partenza e il vertice di arrivo: " << endl;
        cin >> n >> m;
        sn.aggiungiAmicizia(n, m);
    }
    int utente;
    cout << "Inserisci l'utente da suggerire: " << endl;
    cin >> utente;
    sn.stampaGrafo();
    sn.suggerisciAmici(utente);
    return 0;
}
