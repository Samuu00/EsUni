#include <iostream>
using namespace std;

struct Nodo{
    int val;
    Nodo* sinistro;
    Nodo* destro;

    Nodo(int valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

Nodo* inserisci(Nodo* root, int val){
    if(root == nullptr){
        return new Nodo(val);
    }

    if(val < root->val){
        root->sinistro = inserisci(root->sinistro, val);
    } else if (val > root->val){
        root->destro = inserisci(root->destro, val);
    }
    return root;
}

int sommaNodiFoglia(Nodo* root){
    if(root == nullptr) return 0;
    if(root->sinistro == nullptr && root->destro == nullptr) return root->val;
    return sommaNodiFoglia(root->sinistro) + sommaNodiFoglia(root->destro);
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

    int somma = sommaNodiFoglia(root);
    cout << "Somma dei nodi foglia: " << somma << endl;
    distruggiAlbero(root);

    return 0;
}