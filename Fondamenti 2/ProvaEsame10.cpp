#include <iostream>
#include <vector>
using namespace std;


//es1
class codaPrioritaria{
    private:
        vector<pair<int, int>> coda;
    public:
        void aggiungi(int n, int p){
            coda.push_back(make_pair(n, p));
        }
        int estrai(){
            int daEstrarre = 0;
            for(int i = 0; i < coda.size(); i++){
                if(coda[i].second > coda[daEstrarre].second()){
                    daEstrarre = coda[i].first;
                }
            }
            coda.erase(coda.begin() + daEstrarre);
            return daEstrarre;
        }

        bool vuota(){
            if(coda.empty()) return true;
            return false;
        }
};


//es2
struct nodo{
    int val;
    nodo* sinistro;
    nodo* destro;
    nodo(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

void isBST(nodo* root){
    if(root == nullptr) return true;
    if(root->sinistro != nullptr && root->sinistro->val >= root->val) return false;
    if(root->destro != nullptr && root->destro->val <= root->val) return false;
    return isBST(root->sinistro) && isBST(root->destro);
}

