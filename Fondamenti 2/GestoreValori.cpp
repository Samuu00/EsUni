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
    vector<GestoreValori*> v;
    v = {new GestoreValoriA(), new GestoreValoriB()};
    int n;
    cout << "Inserisci il numero di coppie: ";
    cin >> n;

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < n; j++){
            char c;
            int num;
            cout << "Inserisci il carattere e il numero: ";
            cin >> c >> num;
            v[i]->inserisciCoppia(c, num);
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout << "Risultato di GestoreValori" << i+1 << ": " << v[i]->getRisultato() << endl;
    }
    for(int i = 0; i < v.size(); i++){
        delete v[i];
    }
}
