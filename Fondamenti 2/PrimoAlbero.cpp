#include <iostream>
using namespace std;

struct Nodo{
    int valore;
    Nodo* sinistro;
    Nodo* destro;

    Nodo(int val) : valore(val), sinistro(nullptr), destro(nullptr) {}
};

Nodo* creNodo(int valore){
    Nodo* nuovoNodo = new Nodo(valore);
    nuovoNodo->valore = valore;
    nuovoNodo->sinistro = nullptr;
    nuovoNodo->destro = nullptr;
    return nuovoNodo;
}

void inOrdine(Nodo* nodo){
    if(nodo == nullptr) return;
    inOrdine(nodo->sinistro);
    cout << nodo->valore << " ";
    inOrdine(nodo->destro);
}
void preOrdine(Nodo* nodo){
    if(nodo == nullptr) return;
    cout << nodo->valore << " ";
    preOrdine(nodo->sinistro);
    preOrdine(nodo->destro);
}
void postOrdine(Nodo* nodo){
    if(nodo == nullptr) return;
    postOrdine(nodo->sinistro);
    postOrdine(nodo->destro);
    cout << nodo->valore << " ";
}

void distruggiAlbero(Nodo* nodo){
    if(nodo == nullptr) return;
    distruggiAlbero(nodo->sinistro);
    distruggiAlbero(nodo->destro);
    delete nodo;
}

int main(){
    Nodo* albero = creNodo(5);
    albero->sinistro = creNodo(3);
    albero->destro = creNodo(8);
    albero->sinistro->sinistro = creNodo(1);
    albero->sinistro->destro = creNodo(4);
    albero->destro->sinistro = creNodo(7);
    albero->destro->destro = creNodo(9);

    cout << "In ordine: ";
    inOrdine(albero);
    cout << endl;
    cout << "Pre ordine: ";
    preOrdine(albero);
    cout << endl;
    cout << "Post ordine: ";
    postOrdine(albero);
    cout << endl;

    return 0;

}