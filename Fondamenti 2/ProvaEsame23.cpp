#include <iostream>
using namespace std;

//Bonus
struct nodo{
    int val;
    nodo* next;

    nodo(int v) : val(v), next(nullptr) {}
};

nodo* invertiLista(nodo* head){
    nodo* prev = nullptr;
    nodo* current = head;
    nodo* next = nullptr;
    while(current != nullptr){

        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;
}


//es2
struct nodoAlb{
    int val;
    nodoAlb* sinistro;
    nodoAlb* destro;

    nodoAlb(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

int sommaFoglie(nodoAlb* root, int& somma){
    if(root == nullptr) return 0;

    if(root->sinistro == nullptr && root->destro == nullptr){
        somma += root->val;
    }
    return sommaFoglie(root->sinistro, somma) + sommaFoglie(root->destro, somma);
}