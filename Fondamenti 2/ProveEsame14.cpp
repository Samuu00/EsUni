#include <iostream>
using namespace std;


//es1
class CodaPrioritaria{
    private:
        int maxSize;
        int size;
        int* buffer;
    public:
        CodaPrioritaria(){
            this->maxSize = 100;
            this->size = 0;
            this->buffer = new int[this->maxSize];
        }
        void inserisci(int x){
            int agg = 0;
            for(int i = 0; i < size; i++){
                if(x > buffer[i]){
                    agg = i;
                    break;
                }
            }
            for(int j = agg; j < size - 1; j++){
                buffer[j] = buffer[j + 1];
            }
            buffer[agg] = x;
            size++;
        }
        int estrai(){
            int daRimuovere = buffer[0];
            for(int i = size; i > 0; i--){
                buffer[i] = buffer[i - 1];
            }
            size--;
            return daRimuovere;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;

    nodo(int v): val(v), sinistro(nullptr), destro(nullptr) {}
};

bool foglieUguali(nodo* root, int& val){
    if(root == nullptr) return true;
    if(root->sinistro == nullptr && root->destro == nullptr){
        if(val == -1){
            val = root->val;
        }else{
            if(val != root->val) return false;
        }
        return true;
    }
    return foglieUguali(root->sinistro, val) && foglieUguali(root->destro, val);
}