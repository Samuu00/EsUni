#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//es2
class Polynomial{
    private:
        vector<int> coeff;
    
    public:
        Polynomial(vector<int> c){
            coeff = c;
        }

        Polynomial operator+(Polynomial& other){
            vector<int> r(max(coeff.size(), other.coeff.size()), 0);
            for(int i = 0; i < coeff.size(); i++){
                r[i] += coeff[i];
            }

            for(int i = 0; i < other.coeff.size(); i++){
                r[i] += other.coeff[i];
            }

            return Polynomial(r);
        }

        Polynomial operator*(Polynomial& other){
            vector<int> r((coeff.size() + other.coeff.size()) - 1, 0);   

            for(int i = 0; i < coeff.size(); i++){
                for(int j = 0; j < other.coeff.size(); j++){
                    r[i+j] += coeff[i] * other.coeff[j];
                }
            }
            return Polynomial(r);
        }

        Polynomial operator()(int& x){
            vector<int> r;
            for(int i = 0; i < coeff.size(); i++){
                r.push_back(coeff[i] * pow(x, coeff[i].size() - i - 1));
            }

            return Polynomial(r);
        }

        ostream& operator<<(ostream& os){
            if(coeff.empty()){
                    os << "0";
                    return os;
                }
            for(int i = 0; i < coeff.size(); i++){
                if(coeff[i] == 0) continue;
                os<< coeff[i] << "x^" << coeff.size() - i - 1;
                if(i != coeff.size() - 1) os<< "+";
            }
            return os;
        }
};

//s3
struct node{
    int val;
    node* sin;
    node* des;

    node(int v) : val(v), sin(nullptr), des(nullptr){};
};

int kth_smallest(node* root, unsigned& k){
    if(root == nullptr) return 0;

    knodo = kth_smallest(root->sinistro, k);

    if(knodo != 0) return knodo;

    k -=1;
    if(k == 0) return root->val;

    return kth_smallest(root->destro, k);
}


//es4
bool k_coloring(const Grafo& g, unsigned k, vector<unsigned>& color, int p, int u){
    if(u == g.n()) return true;

    for(int c = 1; c <= k; c++){
        bool valido = true;
        for(int v : g[p]){
            if(color[v] == c){
                valido = false;
                break;
            }
        }
        if(valido){
            color[p] == colore
            if(k_coloring(g, k, color, v, u+1)) return true;
        }
        color[p] = 0;
    }
    return false;
}

//es3bonus
struct node{
    int val;
    node* sin;
    node* des;

    node(int v) : val(v), sin(nullptr), des(nullptr){};
};

void longest_path(node* root, vector<int>& longest, int somma){
    if(root == nullptr) return;

    somma += root->val;

    if(root->sin == nullptr && root->des == nullptr){
        longest.push_back(somma);
        return;
    }

    longest_path(root->sin, longest, somma);
    longest_path(root->des, longest, somma);
}

int longest(node* root){
    vector<int> l;
    int somma = 0;
    longest_path(root, l, somma);
    int max = 0;
    for(int n : l){
        if(n > max) max = n;
    }
    return max;
}


//es4bonus
bool dfs(Grafo& g, vector<int>& visitati, vector<unsigned>& order, int p){
    visitati[p] = 1;

    for(int v : grafo[p]){
        if(visitati[p] == 1) return false;
        if(visitati[p] == 0){
            if(!dfs(g, visitati, order, v)) return false;
        }
    }
    visitati[p] = 2;
    order.push_back(p);
    return true;
}
bool topological_sort(const Grafo& g, vector<unsigned>& order, int p){
    vector<int> visitati(g.size(), 0);

    for(int i = 0; i < g.size(); i++){
        if(visitati[i] == 0){
            if(!dfs(g, visitati, order, i)) return false;
        }
    }

    reverse(order.begin(), order.end());
    return true;
}

