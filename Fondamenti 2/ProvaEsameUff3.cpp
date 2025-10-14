#include <iostream>
using namespace std;

//es2
class ArrayDin{
    private:
        int size;
        int maxSize;
        int* arr;
    
    public:
        ArrayDin(int s){
            this->size = 0;
            maxSize = s;
            this->arr = new int[maxSize];
        }  

        ~ArrayDin(){
            delete[] arr;
        }

        void resize(unsigned new_size){
            int* newArr = new int[new_size];
            for(int i = 0; i < size; i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

        void set(unsigned i, int val){
            if(i < size){
                arr[i] = val;
                size++;
            }else{
                return;
            }
        }

        int get(unsigned i){
            if(i < size){
                return arr[i];
            }else{
                return 0;
            }
        }

        void print(){
            for(int i = 0; i < size; i++){
                cout<< arr[i] << " ";
            }
        }

        unsigned getSize(){ return size; }
};

//es2Bonus
class Amico{
    private:
        string nome;
        vector<pair<string, string>> prestiti;
        vector<pair<string, string>> debitore;
 
    public:
        string getNome(){ return nome; }
        vector<pair<string, string>> getPrestiti() { return prestiti; }
        vector<pair<string, string>> getDebitore() { return debitore; }

        bool operator==(Amico& other){
            return nome == other.nome;
        }
};
class PrestitoLibri{
    private:
        vector<Amico> amici;
    
    public:
        void aggiungiAmico(Amico& a){
            amici.push_back(a);
        }

        void registraPrestito(Amico& a, Amico& b, string libro){
            for(int i = 0; i < amici.size(); i++){
                if(amici[i] == a){
                    a.getPrestiti().push_back({b.getNome(), libro});
                }
                if(amici[i] == b){
                    b.getDebitore().push_back({a.getNome(), libro});
                }
            }
        }

        bool verificaPrestito(Amico& a, Amico& b, string libro){
            for(int i = 0; i < amici.size(); i++){
                if(amici[i] == a){
                    for(pair<Amico, string> v : amici[i].getPrestiti()){
                        if(v.second == libro) return true;
                    }
                }
            }
            return false;
        }

        vector<string> inPrest(Amico& a){
            vector<string> libri;
            for(int i = 0; i < amici.size(); i++){
                if(amici[i] == a){
                    for(pair<Amico, string> v : amici[i].getPrestiti()){
                        libri.push_back(v.second);
                    }
                }
            }
            return libri;
        }

        vector<string> debit(Amico& a){
            vector<string> libri;
            for(int i = 0; i < amici.size(); i++){
                if(amici[i] == a){
                    for(pair<Amico, string> v : amici[i].getDebitore()){
                        libri.push_back(v.second);
                    }
                }
            }
            return libri;
        }
};


//es3
struct node {
    int val;
    node* sinistro;
    node* destro;
    node(int v) : val(v), sinistro(nullptr), destro(nullptr) {}
};

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

Info largestBST(node* root, int& maxSize) {
    if (!root) {
        return {true, 0, INT_MAX, INT_MIN}; 
    }

    Info left = largestBST(root->sinistro, maxSize);
    Info right = largestBST(root->destro, maxSize);

    Info curr;
    curr.size = left.size + right.size + 1;
    curr.minVal = min(root->val, left.minVal);
    curr.maxVal = max(root->val, right.maxVal);

    if (left.isBST && right.isBST &&
        root->val > left.maxVal && root->val < right.minVal) {
        curr.isBST = true;
        maxSize = max(maxSize, curr.size);
    } else {
        curr.isBST = false;
    }

    return curr;
}

int largest_bst_subtree(node* root) {
    int maxSize = 0;
    largestBST(root, maxSize);
    return maxSize;
}


