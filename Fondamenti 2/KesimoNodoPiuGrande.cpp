#include <iostream>
using namespace std;

struct Nodo{
    int val;
    Nodo* sinistro;
    Nodo* destro;

    Nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

Nodo* inserisci(Nodo* root, int val){
    if (root == nullptr){
        return new Nodo(val);
    }

    if(val < root->val){
        root->sinistro = inserisci(root->sinistro, val);
    } else if (val > root->val){
        root->destro = inserisci(root->destro, val);
    }
    return root;
}

void preOrdine(Nodo* nodo){
    if(nodo == nullptr) return;
    cout << nodo->val << " ";
    preOrdine(nodo->sinistro);
    preOrdine(nodo->destro);
}

Nodo* KesimoNodoPiuGrande(Nodo* nodo, int& k){
    if (nodo == nullptr) return nullptr;
    
    Nodo* Knodo = KesimoNodoPiuGrande(nodo->destro, k);
    if (Knodo != nullptr) return Knodo;

    k--;
    if (k == 0) return nodo;

    return KesimoNodoPiuGrande(nodo->sinistro, k);
}

void distruggiAlbero(Nodo* root){
    if(root == nullptr) return;
    distruggiAlbero(root->sinistro);
    distruggiAlbero(root->destro);
    delete root;
}

int main() {
    Nodo* root = nullptr;
    int n, k, kk;
    cout << "Inserisci il numero di nodi: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Inserisci i valori dei nodi " << i + 1 << ": ";
        int val;
        cin >> val;
        root = inserisci(root, val);
    }
    cout << "Inserisci il valore di k: ";
    cin >> k;
    kk = k;
    Nodo* risultato = KesimoNodoPiuGrande(root, k);
    if (risultato != nullptr) {
        cout << "Il " << kk << " nodo piu grande e: " << risultato->val << endl;
    } else {
        cout << "Non esiste un nodo piu grande per il valore di k fornito." << endl;
    }

    distruggiAlbero(root);
    return 0;
}
