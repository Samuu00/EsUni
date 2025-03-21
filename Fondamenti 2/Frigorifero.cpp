#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Alimento {
    private:
        string nome;
        string tipo;
        unsigned kcal;
        bool sano;
    
    public:
        Alimento(string n, string t, unsigned k, bool s) : nome(n), tipo(t), kcal(k), sano(s) {}
    
        string getNome() const { return nome; }
        string getTipo() const { return tipo; }
        unsigned getKcal() const { return kcal; }
        bool getSano() const { return sano; }
};

class Frigorifero {
    protected:
        vector<vector<Alimento>> ripiani; 
    public:
        void stampaContenuto() const {
            for (size_t i = 0; i < ripiani.size(); i++) {
                for (const auto& alimento : ripiani[i]) { 
                    cout << alimento.getTipo() << ": " << alimento.getNome() << endl;
                }
            }
        }
        void virtual aggiungiAlimento(const Alimento& a) = 0;
        Alimento virtual estraiAlimento(const string& rip) = 0;
        virtual ~Frigorifero() {}
    };
class FrigoriferoSalutista : public virtual Frigorifero{
    private:
        int trovaRipiano(const string& tipo) {
            for (size_t i = 0; i < ripiani.size(); i++) {
                if (!ripiani[i].empty() && ripiani[i][0].getTipo() == tipo) {
                    return i;
                }
            }
            ripiani.push_back(vector<Alimento>());
            return ripiani.size() - 1;
        }
    public:
        void aggiungiAlimento(const Alimento& a) override {
            string tipo = a.getTipo();
            int ripianoindex = trovaRipiano(tipo);
            ripiani[ripianoindex].push_back(a);
        }
        Alimento estraiAlimento(const string& tipo) override {
            string tipoCercato = tipo; 
            cout << "Cerco l'alimento di tipo: " << tipoCercato << endl;
        
            for (int i = 0; i < ripiani.size(); i++) {
                for (int j = 0; j < ripiani[i].size(); j++) {
                    string tipoSalvato = ripiani[i][j].getTipo(); 
                    cout << "Controllo: " << tipoSalvato << endl;
                    
                    if (tipoSalvato == tipoCercato) {
                        cout << "Trovato! Rimuovo: " << ripiani[i][j].getNome() << endl;
                        Alimento estratto = ripiani[i][j];
                        ripiani[i].erase(ripiani[i].begin() + j);
                        return estratto;
                    }
                }
            }
            cout << "Alimento non trovato!" << endl;
            return Alimento("", "", 0, false);
        }
        
};

int main() {
    FrigoriferoSalutista frigo;
    int n;
    
    cout << "Inserisci quanti alimenti aggiungere: ";
    cin >> n;

    string nome, tipo;
    unsigned kcal;
    bool sano;
    
    for (int i = 0; i < n; i++) {
        cout << "Inserisci nome, tipo, kcal, sano (1 o 0): "<<endl;
        cin >> nome >> tipo >> kcal >> sano;
        cin.ignore(); 
        frigo.aggiungiAlimento(Alimento(nome, tipo, kcal, sano));
    }

    frigo.stampaContenuto();

    string rip;
    cout << "Inserisci il tipo dell'alimento da estrarre: ";
    cin>> rip;

    frigo.estraiAlimento(rip);
    frigo.stampaContenuto();

    return 0;
}

                            
