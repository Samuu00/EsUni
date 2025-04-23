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

bool isBST(Nodo* nodo, Nodo* minNode, Nodo* maxNode){
    if (nodo == nullptr) return true;

    if ((minNode != nullptr && nodo->val <= minNode->val) ||  (maxNode != nullptr && nodo->val >= maxNode->val)) {
        return false;
    }

    return isBST(nodo->sinistro, minNode, nodo) && isBST(nodo->destro, nodo, maxNode);
}

int main(){
    int n;
    cout << "Inserisci il numero di nodi: ";
    cin >> n;

    Nodo* root = nullptr;
    for(int i = 0; i < n; i++){
        cout << "Inserisci il valore del nodo " << i + 1 << ": ";
        int val;
        cin >> val;
        root = inserisci(root, val);
    }

    cout << "Pre-ordine dell'albero: ";
    preOrdine(root);
    cout << endl;

    Nodo* min = nullptr;
    Nodo* max = nullptr;

    if(isBST(root, min, max)){
        cout << "L'albero e un BST." << endl;
    } else {
        cout << "L'albero non e un BST." << endl;
    }

    return 0;
}