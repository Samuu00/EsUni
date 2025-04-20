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

    if(val <= root->val){
        root->sinistro = inserisci(root->sinistro, val);
    } else {
        root->destro = inserisci(root->destro, val);
    }
    return root;
}

bool trovaValore(Nodo* root, int target){
    if(root == nullptr) return false;

    if(root->val == target) return true;

    if(target <= root->val){
        return trovaValore(root->sinistro, target);
    } else {
        return trovaValore(root->destro, target);
    }
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
    int n;
    cout << "Inserisci il numero di nodi: ";
    cin >> n;
    Nodo* albero = nullptr;
    for(int i = 0; i < n; i++){
        int val;
        cout << "Inserisci il valore del nodo " << i + 1 << ": ";
        cin >> val;
        albero = inserisci(albero, val);
    }
    cout << "Pre ordine: ";
    preOrdine(albero);
    cout << endl;
    int val;
    cout << "Inserisci il valore da cercare: ";
    cin >> val;
    if(trovaValore(albero, val)){
        cout << "Valore trovato!" << endl;
    } else {
        cout << "Valore non trovato!" << endl;
    }
    return 0;
}


