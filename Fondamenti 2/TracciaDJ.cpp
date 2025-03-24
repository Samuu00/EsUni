#include <iostream>
#include <vector>
using namespace std;

struct Traccia{
    string titolo;
    int durata;
    string genere;

    Traccia(string t, int d, string g){
        titolo = t;
        durata = d;
        genere = g;
    }
};

vector<Traccia> SelezionaCanzoni(vector<Traccia>& v, int k){
    int lenght = v.size();
    vector<Traccia> dj;
    int durata = 0;
    for(size_t i = 0; i < lenght; i++){
        dj.push_back(v[i]);
        durata += v[i].durata;
        if(durata == k){
            return dj;
        }
    }
    cout << "Non e stato possibile selezionare nessuna canzone" << endl;
    return {};
}

int main(){
    vector<Traccia> v;
    cout << "Quante canzoni vuoi inserire?: " << endl;
    int n;
    cin >> n;
    for(size_t i = 0; i < n; i++){
        cout << "Inserisci il titolo della canzone, la durata e il genere: " << endl;
        string titolo;
        int durata;
        string genere;
        cin >> titolo >> durata >> genere;
        v.push_back(Traccia(titolo, durata, genere));
    }
    cout << "Quanti minuti vuoi ascoltare?: " << endl;
    int k;
    cin >> k;
    vector<Traccia> dj = SelezionaCanzoni(v, k);
    cout << "La tua playlist e: " << endl;
    for(size_t i = 0; i < dj.size(); i++){
        cout << "[ Titolo: " << dj[i].titolo << " || " << "Durata: " << dj[i].durata << " minuti || " << "Genere: " << dj[i].genere << " ]" << endl;
    }
    return 0;
}




