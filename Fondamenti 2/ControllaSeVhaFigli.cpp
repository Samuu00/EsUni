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

bool controllaSeVhafigli(nodo* root, int v){
    if(root == nullptr) return false;
    if(root->val == v){
        if(root->sinistro != nullptr && root->destro != nullptr) return true;
        else return false;
    }
    if(v < root->val){
        return controllaSeVhafigli(root->sinistro, v);
    } else {
        return controllaSeVhafigli(root->destro, v);
    }
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

    int v;
    cout << "Inserisci il valore da controllare: ";
    cin >> v;
    
    if(controllaSeVhafigli(root, v)){
        cout << "Il nodo con valore " << v << " ha due figli." << endl;
    } else {
        cout << "Il nodo con valore " << v << " non ha due figli." << endl;
    }

    distruggiAlbero(root);
    return 0;
}