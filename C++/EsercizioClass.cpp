#include <iostream>
#include <vector>
using namespace std;

class Esercizio{
    private:
        string descrizione, ides;
        int difficolta;
    public:
        Esercizio(){
            descrizione = "";
            ides = "";
            difficolta = 0;
        }
        Esercizio(const Esercizio& e){
            descrizione = e.descrizione;
            ides = e.ides;
            difficolta = e.difficolta;
        }
        Esercizio(string des, string id, int diff){
            descrizione = des;
            ides = id;
            difficolta = diff;
        }

        string getDescrizione() const{
            return descrizione;
        }
        string getID() const{
            return ides;
        }
        int getDifficolta() const {
            return difficolta;
        }
        
};

class BancaDatiEs : public Esercizio {
    protected:
        vector<Esercizio> esercizi;
    public:
        bool aggiungiEsercizio(const Esercizio& e) {
            for (size_t i = 0; i < esercizi.size(); i++) {
                if (esercizi[i].getID() == e.getID()) {
                    cout << "Esercizio con ID gia presente" << endl;
                    return false;
                }
            }
            esercizi.push_back(e);
            cout << "Esercizio con ID: " << e.getID() << " aggiunto con successo" << endl;
            return true;
        }
    
        vector<Esercizio> CreaEsame(int n, int diff_m) {
            vector<Esercizio> esame;
            int totdiff = 0;
            for (int i = 0; i < n; i++) {
                if (totdiff + esercizi[i].getDifficolta() > diff_m) {
                    return {};
                }
                esame.push_back(esercizi[i]);
                totdiff += esercizi[i].getDifficolta();
            }
            return esame;
        }
    
        void stampa(const vector<Esercizio>& e) const {
            for (size_t i = 0; i < e.size(); i++) {
                cout << "Esercizio: " << i + 1 << "- " << e[i].getID() << ", " << e[i].getDescrizione() << ", " << e[i].getDifficolta() << endl;
            }
        }
    
        void stampa() const {
            for (size_t i = 0; i < esercizi.size(); i++) {
                cout << "Esercizio: " << i + 1 << "- " << esercizi[i].getID() << ", " << esercizi[i].getDescrizione() << ", " << esercizi[i].getDifficolta() << endl;
            }
        }
    };
    
    int main() {
        BancaDatiEs esercizi;
        int n;
        cout << "Inserisci quanti es vuoi aggiungere nella banca dati: ";
        cin >> n;
        string desc, id;
        int diff;
        for (int i = 0; i < n; i++) {
            cin >> desc >> id >> diff;
            cin.ignore();
            esercizi.aggiungiEsercizio(Esercizio(desc, id, diff));
        }
        cout << "Elenco di esercizi della banca dati: " << endl;
        esercizi.stampa(); 
        
        int nes, diffmax;
        cout << "Inserisci numero e diff massima degli esercizi dell'esame: " << endl;
        cin >> nes >> diffmax;
        cin.ignore();
        
        cout << "Esame: " << endl;
        esercizi.stampa(esercizi.CreaEsame(nes, diffmax));
    
        return 0;
    }