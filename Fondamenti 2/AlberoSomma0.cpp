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

bool controllaSePercorsoSomma0(nodo* root, int x, int somma){
    if(root == nullptr) return false;

    if((root->sinistro->val || root->destro->val) == x && somma == 0){
        return true;
    }
    return controllaSePercorsoSomma0(root->sinistro, x, somma) || controllaSePercorsoSomma0(root->destro, x, somma);
    
}

void distruggiAlbero(nodo* root){
    if(root == nullptr) return;
    distruggiAlbero(root->sinistro);
    distruggiAlbero(root->destro);
    delete root;
}

int main(){
    int n;
    cout << "Inserisci il numero di nodi: ";
    cin >> n;
    nodo* root = nullptr;
    for(int i = 0; i < n; i++){
        int val;
        cout << "Inserisci il valore del nodo: " << i + 1 << ": ";
        cin >> val;
        root = inserisci(root, val);
    }
    int x;
    cout << "Inserisci fino a dove vuoi controllare se esiste un percorso che somma a 0: ";
    cin >> x;
    if(controllaSePercorsoSomma0(root, x, 0)){
        cout << "Esiste un percorso fino a " << x << " che somma a 0" << endl;
    } else {
        cout << "Non esiste un percorso fino a " << x << " che somma a 0" << endl;
    }

    distruggiAlbero(root);
    return 0;
}
