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

void preOrdine(Nodo* root){
    if(root == nullptr) return;
    cout << root->val << " ";
    preOrdine(root->sinistro);
    preOrdine(root->destro);
}

int ProfonditaAlbero(Nodo* root){
    if(root == nullptr) return 0;
    int sinistro = ProfonditaAlbero(root->sinistro);
    int destro = ProfonditaAlbero(root->destro);
    return max(sinistro, destro) + 1;
}

Nodo* nodoPiuProfondo(Nodo* root){
    if(root == nullptr) return nullptr;
    if(root->sinistro == nullptr && root->destro == nullptr) return root;

    Nodo* sinistro = nodoPiuProfondo(root->sinistro);
    Nodo* destro = nodoPiuProfondo(root->destro);
    
    if(sinistro > destro){
        return sinistro;
    } else {
        return destro;
    }
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
    cout << "Pre-ordine dell'albero: ";
    preOrdine(albero);
    cout << endl;
    cout << "Profondita dell'albero: " << ProfonditaAlbero(albero) << endl;
    Nodo* nodoProfondo = nodoPiuProfondo(albero);
    cout << "Nodo piu profondo: " << nodoProfondo->val << endl;
    distruggiAlbero(albero);
    return 0;
}