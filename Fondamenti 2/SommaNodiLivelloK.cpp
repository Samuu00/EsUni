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

void decrescente(nodo* root){
    if(root == nullptr) return;
    decrescente(root->destro);
    cout << root->val << " ";
    decrescente(root->sinistro);
}

int sommaNodiLivelloK(nodo* root, int k){
    if(root == nullptr) return 0;
    if(k == 0) return root->val;
    return sommaNodiLivelloK(root->sinistro, k - 1) + sommaNodiLivelloK(root->destro, k - 1);
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
    
    cout << "Decrescente: ";
    decrescente(root);
    cout << endl;

    int k;
    cout << "Inserisci il livello k: ";
    cin >> k;

    int somma = sommaNodiLivelloK(root, k);
    cout << "Somma dei nodi al livello " << k << ": " << somma << endl;

    distruggiAlbero(root);
    return 0;
}