#include <iostream>
using namespace std;

template <typename T>
struct nodo {
    T val;
    nodo* sinistro;
    nodo* destro;

    nodo(T valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

/* albero inserito con una espressione aritmetica
// esempio: 3 + 4 * 5
// albero:
//         +
//        / \s
//       3   *
//          / \
//         4   5
*/

string codificaEspressioneInAlbero(nodo<string>* root){
    if(root == nullptr) return "";
    string sinistro = codificaEspressioneInAlbero(root->sinistro);
    string destro = codificaEspressioneInAlbero(root->destro);
    
    if(sinistro.empty() && destro.empty()){
        return root->val;
    } else {
        return "(" + sinistro + " " + root->val + " " + destro + ")";
    }
}

int main(){
    nodo<string>* root = new nodo<string>("+");
    root->sinistro = new nodo<string>("3");
    root->destro = new nodo<string>("*");
    root->destro->sinistro = new nodo<string>("4");
    root->destro->destro = new nodo<string>("5");

    string espressione = codificaEspressioneInAlbero(root);
    cout << "Espressione codificata: " << espressione << endl;


    delete root->destro->sinistro;
    delete root->destro->destro;
    delete root->destro;
    delete root->sinistro;
    delete root;

    return 0;
}

