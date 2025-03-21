#include <iostream>
using namespace std;

class Spedizione{
    private:
        int codice;
        float valore;
        float peso;
    public:
        Spedizione(){
            codice = 0;
            valore = 0;
            peso = 0;
        }
        Spedizione(const Spedizione& s){
            codice = s.codice;
            valore = s.valore;
            peso = s.peso;
        }
        Spedizione(const int c, const float v, const float p){
            codice = c;
            valore = v;
            peso = p;
        }
        int getCodice() const{
            return codice;
        };
        float getValore() const{
            return valore;
        };
        float getPeso() const{
            return peso;
        };
};

struct Node{
    Spedizione data;
    Node* next;

    Node(Spedizione s){
        data = s;
        next = nullptr;
    }
};

class CodaSpedizioni {
private:
    Node* head;
    Node* current;
public:
    CodaSpedizioni() : head(nullptr), current(nullptr) {}

    void aggiungiSpedizioni(Spedizione s) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.getCodice() == s.getCodice()) {
                cout << "Codice gia esistente, riprova" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* newSped = new Node(s);
        if (!head) {
            head = newSped;
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newSped;
        }
    }

    void RimuoviSpedizioni(int c) {
        Node* temp = head;
        if (head != nullptr && head->data.getCodice() == c) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data.getCodice() == c) {
                Node* daRimuovere = temp->next;
                temp->next = temp->next->next;
                delete daRimuovere;
                return;
            }
            temp = temp->next;
        }
        cout << "Spedizione non trovata" << endl;
    }

    Spedizione next() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            return current->data;
        }
    }

    unsigned int size() const {
        Node* temp = head;
        unsigned int cont = 0;
        while (temp != nullptr) {
            cont++;
            temp = temp->next;
        }
        return cont;
    }

    void reset() {
        current = head; 
    }

    void stampa(){
        Node* temp = head;
        while (temp != nullptr){
            cout << "Codice: " << temp->data.getCodice() << ", Valore: " << temp->data.getValore() << ", Peso: " << temp->data.getPeso() << endl;
            temp = temp->next;
        }
        return;
    }
};

int main() {
    CodaSpedizioni spedizioni;
    int n;
    cout << "Inserisci quante spedizioni vuoi allocare: ";
    cin >> n;

    int c;
    float v, p;
    for (int i = 0; i < n; i++) {
        cout << "Inserisci codice, valore, peso: ";
        cin >> c >> v >> p;
        spedizioni.aggiungiSpedizioni(Spedizione(c, v, p));
    }

    int cr;
    cout << "Inserisci codice spedizione che vuoi rimuovere: ";
    cin >> cr;
    spedizioni.RimuoviSpedizioni(cr);

    spedizioni.reset();
    cout << "Lista delle spedizioni:" << endl;
    spedizioni.stampa();

    cout << "Numero di spedizioni: " << spedizioni.size() << endl;

    return 0;
}