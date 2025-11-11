#include <iostream>
#include <map>
using namespace std;


//es2
class SparseVector {
    private:
        map<int, int> data;
        int dim;         

    public:
        SparseVector(int d) : dim(d) {}
        
        ~SparseVector() {}

        void set(int idx, int val){
            auto it = data.find(idx);
            
            if(it != data.end() && val == 0){
                data.erase(idx);
                return;
            } 

            data[idx] = val;
        }
        
        int get(int idx) const{
            auto it = data.find(idx);

            if(it != data.end()){
                return it->second;
            }
            return 0;
        }

        int prodottoScalare(const SparseVector& other) const {
            int prodScal = 0;

            for(const auto& it : this->data){
                int idx = it.first;
                int val = it.second;

                int val_other = other.get(idx);

                prodScal += (val * val_other);
            }

            return prodScal;
        }
};

//es3
enum Direzione { SIN, DES };
class AlberoB {
    private:
        int info;  
        AlberoB* p;          
        AlberoB* sx;          
        AlberoB* dx;                 

    public:
        
        AlberoB(int valore) : info(valore),  p(nullptr), sx(nullptr), dx(nullptr) {}

        ~AlberoB() {
            delete sx; 
            delete dx;
        }

        AlberoB* figlio(Direzione dir) {
            if (dir == SIN) {
                return this->sx;
            }
            return this->dx;
        }

        AlberoB* padre() {
            return this->p;
        }

        int radice() {
            return this->info;
        }

        bool foglia() {
            return (this->sx == nullptr && this->dx == nullptr);
        }

        static bool nullo(AlberoB* a) {
            return a == nullptr;
        }

        bool helperBST(AlberoB* a, int minVal, int maxVal){
            if(nullo(a)) return true;

            if(a.radice() <= minVal || a.radice() >= maxVal) return false;

            return helperBST(a.figlio(SIN), minVal, a.radice()) && helperBST(a.figlio(DES), a.radice(), maxVal);
        }

        bool is_BST(AlberoB* a){ 
            return helperBST(a, INT_MIN, INT_MAX);
        }
}