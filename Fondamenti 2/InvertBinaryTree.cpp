#include <iostream>
#include <vector>
using namespace std;

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

        void invertBinaryTree(AlberoB* a){
            if(a.nullo()) return;

            swap(a.figlio(SIN), a.figlio(DES));

            invertBinaryTree(a.figlio(SIN));
            invertBinaryTree(a.figlio(DES));
        }
};
