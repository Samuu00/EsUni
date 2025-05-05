#include <iostream>
#include <vector>
using namespace std;

//es1
struct Libro{
    string titolo;
    int copie;
};
class Libreria{
    private:
        int maxSize;
        int size;
        Libro* libreria;
    public:
        Libreria(){
            this->maxSize = 100;
            this->size = 0;
            this->libreria = new Libro[maxSize];
        }
        void aggiungi(string& titolo, int& copie){
            for(int i = 0; i < size; i++){
                if(libreria[i].titolo == titolo){
                    libreria[i].copie += copie;
                    break;
                }
            }
            libreria[size + 1].titolo = titolo;
            libreria[size + 1].copie = copie;
            size++;
        }
        void presta(string& titolo){
            bool trovato = false;
            for(int i = 0; i < size; i++){
                if(libreria[i].titolo == titolo){
                    libreria[i].copie -= 1;
                    trovato = true;
                }
            }
            if(!trovato) cout<< "Libro non in elenco" <<endl;
        }

        int copie(string& titolo){
            int copie = 0;
            for(int i = 0; i < size; i++){
                if(libreria[i].titolo == titolo){
                    int copie = libreria[i].copie;
                    return copie;
                }
            }
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v): val(v), sinistro(nullptr), destro(nullptr) {}
};

bool stessaStruttura(nodo* a, nodo* b){
    if(a == nullptr && b == nullptr) return true;
    if(a == nullptr || b == nullptr) return false;
    return stessaStruttura(a->sinistro, b->sinistro) && stessaStruttura(a->destro, b->destro);
}

