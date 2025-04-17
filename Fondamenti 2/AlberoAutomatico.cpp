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

void distruggiAlbero(Nodo* nodo){
    if(nodo == nullptr) return;
    distruggiAlbero(nodo->sinistro);
    distruggiAlbero(nodo->destro);
    delete nodo;
}

int main(){
    Nodo* albero = nullptr;
    int n;
    cout << "Inserisci il numero di nodi: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cout << "Inserisci il valore del nodo " << i + 1 << ": ";
        cin >> val;
        albero = inserisci(albero, val);
    }
    cout << "Pre ordine: ";
    preOrdine(albero);
    cout << endl;
    distruggiAlbero(albero);
    return 0;
}