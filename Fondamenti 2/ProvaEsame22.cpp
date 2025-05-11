#include <iostream>
#include <vector>
using namespace std;


//es1
template <typename t>
class CoppiaOrdinata{
    private:
        t primo;
        t secondo;
    public:
        CoppiaOrdinata(t& pr, t& sec){
            this->primo = pr;
            this->secondo = sec;
        }

        void inverti(){
            t temp = primo;
            primo = secondo;
            secondo = temp;
        }

        bool isOrdinata(){
            return primo < secondo;
        }

        bool operator+(const CoppiaOrdinata& altra){
            return (primo + altra.primo) == (secondo + altra.second);
        }
};


//es2
struct nodo{
    int val;
    nodo* next;

    nodo(int v) : val(v), next(nullptr) {}
};

nodo* filtraPari(nodo* head){
    if(head != nullptr && head->val % 2 != 0){
        nodo* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    nodo* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        if(temp->next->val % 2 != 0){
            nodo* toDelete = temp->next;
            temp = temp->next->next;
            delete toDelete;
        }else{
            temp = temp->next;
        }
    }
}


//es3
class Grafo{
    private:
        int n;
        vector<vector<int>> grafo;

    public:
        void aggiungiArco(int u, int v){
            grafo[u].push_back(v);
        }

        bool camminoLunghezzaK(int p, int a, vector<bool>& visitato, int k){
            if(p == a && k == 0) return true;
            visitato[p] = true;
            for(int v : grafo[p]){
                if(visitato[v]) continue;
                if(camminoLunghezzaK(v, a, visitato, k - 1)) return true;
            }
            visitato[p] = false;
            return false;
        }
};

