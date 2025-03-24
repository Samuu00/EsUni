#include <iostream>
#include <vector>
using namespace std;

class GestoreValori{
    protected:
        vector<pair<char, vector<int>>> coppie;
    public:
        GestoreValori(){
            coppie.clear();
        }
        GestoreValori(const GestoreValori& g){
            coppie = g.coppie;
        }
        void inserisciCoppia(char c, int n){
            for(size_t i = 0; i < coppie.size(); i++){
                if(coppie[i].first == c){
                    coppie[i].second.push_back(n);
                    return;
                }
            }
            vector<int> v;
            v.push_back(n);
            coppie.push_back(make_pair(c, v));
        }
        int numCoppie(){
            return coppie.size();
        }

        virtual int getRisultato(){
            return -1;
        }
        virtual ~GestoreValori() {}
};

class GestoreValoriA : public GestoreValori{
    public:
        int getRisultato() override{
            int somma = 0;
            for(size_t i = 0; i < coppie.size(); i++){
                for(size_t j = 0; j < coppie[i].second.size(); j++){
                    somma += coppie[i].second[j];
            }
        }
        return somma;
    }
};

class GestoreValoriB : public GestoreValori{
    public:
        int getRisultato() override{
            int somma = 0;
            int media = 0;
            int cont = 0;
            for(size_t i = 0; i < coppie.size(); i++){
                for(size_t j = 0; j < coppie[i].second.size(); j++){
                    somma += coppie[i].second[j];
                    cont++;
                }
            }
            media = somma / cont;
            return media;
        }
};

int main(){
    GestoreValoriA gv1;
    GestoreValoriB gv2;
    int n;
    cout << "Inserisci il numero di coppie: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        char c;
        int num;
        cout << "Inserisci il carattere e il numero: ";
        cin >> c >> num;
        gv1.inserisciCoppia(c, num);
        gv2.inserisciCoppia(c, num);
    }

    cout << "Risultato di GestoreValoriA: " << gv1.getRisultato() << endl;
    cout << "Risultato di GestoreValoriB: " << gv2.getRisultato() << endl;
}
