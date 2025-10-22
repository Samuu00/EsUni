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

        static bool nullo(AlberoB* a, float pred) {
            return a == nullptr;
        }

        float spremi(AlberoB* a, float pred){
            if(nullo(a)) return pred;

            float curr = a.radice() + pred;

            if(a.foglia()){
                a.radice() = curr;
                return 0.0;
            }

            a.radice() = 0;
            return spremi(a.figlio(SIN), curr / 2) + spremi(a.figlio(DES), curr / 2);

        }
}