#include <iostream>
using namespace std;

class Prodotto {
    private:
        string nome;
        int quantita;
        double prezzo;
    public:
        Prodotto() {
            nome = "";
            quantita = 0;
            prezzo = 0;
        }
        Prodotto(const string n, int q, const double p) {
            nome = n;
            quantita = q;
            prezzo = p;
        }
        Prodotto(const Prodotto& p) {
            nome = p.nome;
            quantita = p.quantita;
            prezzo = p.prezzo;
        };
        string get_nome() const {
            return nome;
        };
        int get_quantita() {
            return quantita;
        }
        double get_prezzo() const {
            return prezzo;
        };
        void modifica_quantita(int delta) {
            quantita += delta;
        }
};

struct Node {
    Prodotto data;
    Node* next;

    Node(Prodotto p) {
        data = p;
        next = nullptr;
    }
};

class ListaDellaSpesa {
    private:
        Node* head;
    public:
        ListaDellaSpesa() {
            head = nullptr;
        }
        void inserisciProdotto(Prodotto& p) {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->data.get_nome() == p.get_nome()) {
                    temp->data.modifica_quantita(1);
                    return;
                }
                temp = temp->next;
            }
            Node* newProd = new Node(p);
            if (!head) {
                head = newProd;
            } else {
                temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newProd;
            }
        }

        void rimuoviProdotto(string n) {
            Node* temp = head;
            Node* prev = nullptr;

            while (temp != nullptr) {
                if (temp->data.get_nome() == n) {
                    if (temp->data.get_quantita() > 1) {
                        temp->data.modifica_quantita(-1);
                        return;
                    }
                    if (prev == nullptr) {
                        head = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        double totale() const {
            Node* temp = head;
            double totale = 0;
            while (temp != nullptr) {
                totale += temp->data.get_prezzo() * temp->data.get_quantita();
                temp = temp->next;
            }
            return totale;
        }

        void stampaTotale() const {
            cout << "Totale carrello: " << totale() << "euro" << endl;
        }

        ~ListaDellaSpesa() {
            Node* temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main() {
    ListaDellaSpesa carrello;
    int numProdotti;

    cout << "Quanti prodotti vuoi aggiungere? ";
    cin >> numProdotti;

    for (int i = 0; i < numProdotti; i++) {
        string nome;
        int quantita;
        double prezzo;

        cout << "Inserisci nome prodotto: ";
        cin >> nome;
        cout << "Inserisci quantita: ";
        cin >> quantita;
        cout << "Inserisci prezzo: ";
        cin >> prezzo;

        Prodotto p(nome, quantita, prezzo);
        carrello.inserisciProdotto(p);
    }

    carrello.stampaTotale();

    int numRimuovi;
    cout << "Quanti prodotti vuoi rimuovere? ";
    cin >> numRimuovi;

    for (int i = 0; i < numRimuovi; i++) {
        string nome;
        cout << "Inserisci il nome del prodotto da rimuovere: ";
        cin >> nome;
        carrello.rimuoviProdotto(nome);
    }

    carrello.stampaTotale();

    return 0;
}
