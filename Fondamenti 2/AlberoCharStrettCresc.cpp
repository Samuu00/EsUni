#include <iostream>
using namespace std;

struct nodo{
    char val;
    nodo* sinistro;
    nodo* destro;

    nodo(char valore) : val(valore), sinistro(nullptr), destro(nullptr) {}
};

/*albero di char che letto inOrder è in ordine stretto crescente
// esempio: a b c d e f g 
// albero:
//         d
//        / \
//       b   f
//      / \   \
//     a   c   g
*/

bool strettCresc(nodo* root){
    if(root == nullptr) return true;
    if(root->sinistro != nullptr && root->sinistro->val >= root->val) return false;
    if(root->destro != nullptr && root->destro->val <= root->val) return false;
    return strettCresc(root->sinistro) && strettCresc(root->destro);
}

int main(){
    nodo* root = new nodo('d');
    root->sinistro = new nodo('b');
    root->destro = new nodo('f');
    root->sinistro->sinistro = new nodo('a');
    root->sinistro->destro = new nodo('c');
    root->destro->destro = new nodo('g');

    if(strettCresc(root)){
        cout << "L'albero e in ordine stretto crescente" << endl;
    }else{
        cout << "L'albero non e in ordine stretto crescente" << endl;
    }

    return 0;
}