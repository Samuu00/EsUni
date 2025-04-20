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

Nodo* trovaMinimo(Nodo* nodo){
    while(nodo && nodo->sinistro != nullptr){
        nodo = nodo->sinistro;
    }
    return nodo;
}

Nodo* eliminaNodo(Nodo* root, int target){
    if(root == nullptr) return root;

    if (target < root->val) {
        root->sinistro = eliminaNodo(root->sinistro, target);
    } else if (target > root->val) {
        root->destro = eliminaNodo(root->destro, target);
    } else {
        if(root->sinistro == nullptr){
            Nodo* temp = root->destro;
            delete root;
            return temp;
        } else if (root->destro == nullptr){
            Nodo* temp = root->sinistro;
            delete root;
            return temp;
        }

        Nodo* temp = trovaMinimo(root->destro);
        root->val = temp->val;
        root->destro = eliminaNodo(root->destro, temp->val);
    }
    return root;
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

    int target;
    cout << "Inserisci il valore da eliminare: ";
    cin >> target;
    albero = eliminaNodo(albero, target);

    cout << "Pre ordine dopo eliminazione: ";
    preOrdine(albero);
    cout << endl;

    distruggiAlbero(albero);
    return 0;
}