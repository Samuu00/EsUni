#include <iostream>
using namespace std;

struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

nodo* inserisci(nodo* root, int val){
    if(root == nullptr){
        return new nodo(val);
    }
    if(val <= root->val){
        root->sinistro = inserisci(root->sinistro, val);
    } else {
        root->destro = inserisci(root->destro, val);
    }
    return root;
}

void preOrdine(nodo* nodo){
    if(nodo == nullptr) return;
    cout << nodo->val << " ";
    preOrdine(nodo->sinistro);
    preOrdine(nodo->destro);
}

int sommaNodi(nodo* root){
    if(root == nullptr) return 0;
    return root->val + sommaNodi(root->sinistro) + sommaNodi(root->destro);
}

int sommaNodiPari(nodo* root){
    if(root == nullptr) return 0;
    if(root->val % 2 == 0){
        return root->val + sommaNodiPari(root->sinistro) + sommaNodiPari(root->destro);
    } 
    return sommaNodiPari(root->sinistro) + sommaNodiPari(root->destro);
}

int sommaNodiDispari(nodo* root){
    if(root == nullptr) return 0;
    if(root->val % 2 != 0){
        return root->val + sommaNodiDispari(root->sinistro) + sommaNodiDispari(root->destro);
    } 
    return sommaNodiDispari(root->sinistro) + sommaNodiDispari(root->destro);
}

void distruggiAlbero(nodo* root){
    if(root == nullptr) return;
    distruggiAlbero(root->sinistro);
    distruggiAlbero(root->destro);
    delete root;
}

int main(){
    nodo* root = nullptr;
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

    int somma = sommaNodi(root);
    cout << "Somma dei nodi: " << somma << endl;

    int sommaPari = sommaNodiPari(root);
    cout << "Somma dei nodi pari: " << sommaPari << endl;

    int sommaDispari = sommaNodiDispari(root);
    cout << "Somma dei nodi dispari: " << sommaDispari << endl;

    distruggiAlbero(root);
    return 0;
}