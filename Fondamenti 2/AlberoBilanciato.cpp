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

int altezza(Nodo* root){
    if(root == nullptr) return 0;
    return 1 + max(altezza(root->sinistro), altezza(root->destro));
}

bool Bilanciato(Nodo* root){
    if(root == nullptr) return true;

    int hSinistro = altezza(root->sinistro);
    int hDestro = altezza(root->destro);
    if(abs(hSinistro - hDestro) > 1) return false;
    return true;
}

void preOrdine(Nodo* nodo){
    if(nodo == nullptr) return;
    cout << nodo->val << " ";
    preOrdine(nodo->sinistro);
    preOrdine(nodo->destro);
}

void distruggiAlbero(Nodo* root){
    if(root == nullptr) return;
    distruggiAlbero(root->sinistro);
    distruggiAlbero(root->destro);
    delete root;
}

int main(){
    Nodo* root = nullptr;
    int n;
    cout << "Inserisci il numero di nodi: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Inserisci i valori dei nodi " << i + 1 << ": ";
        int val;
        cin >> val;
        root = inserisci(root, val);
    }
    
    cout << "Pre-ordine: ";
    preOrdine(root);
    cout << endl;

    if(Bilanciato(root)){
        cout << "L'albero e bilanciato." << endl;
    } else {
        cout << "L'albero non e bilanciato." << endl;
    }

    distruggiAlbero(root);
    return 0;
}