#include<iostream>
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

bool identici(nodo* a, nodo* b){
    if(a == nullptr && b == nullptr) return true;
    if(a == nullptr || b == nullptr) return false;
    if(a->val != b->val){
        return false;
    }else{
        return identici(a->sinistro, b->sinistro) && identici(a->destro, b->destro);
    }
    return false;
}

void preOrdine(nodo* nodo){
    if(nodo == nullptr) return;
    cout << nodo->val << " ";
    preOrdine(nodo->sinistro);
    preOrdine(nodo->destro);
}

void distruggiAlbero(nodo* root){
    if(root == nullptr) return;
    distruggiAlbero(root->sinistro);
    distruggiAlbero(root->destro);
    delete root;
}

int main(){
    nodo* root1 = nullptr;
    nodo* root2 = nullptr;
    int n1, n2;
    cout << "Inserisci il numero di nodi per il primo albero: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Inserisci i valori dei nodi " << i + 1 << ": ";
        int val;
        cin >> val;
        root1 = inserisci(root1, val);
    }
    
    cout << "Inserisci il numero di nodi per il secondo albero: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Inserisci i valori dei nodi " << i + 1 << ": ";
        int val;
        cin >> val;
        root2 = inserisci(root2, val);
    }
    
    cout << "Pre-ordine del primo albero: ";
    preOrdine(root1);
    cout << endl;

    cout << "Pre-ordine del secondo albero: ";
    preOrdine(root2);
    cout << endl;

    if(identici(root1, root2)){
        cout << "Gli alberi sono identici." << endl;
    }else{
        cout << "Gli alberi non sono identici." << endl;
    }

    distruggiAlbero(root1);
    distruggiAlbero(root2);

    return 0;
}