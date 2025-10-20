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

        void tree(AlberoB* a, vector<char>& letter){
            if(a.nullo()) return;

            if(a.foglia()) letter.push_back(a.radice());

            tree(a.figlio(SIN), letter);
            tree(a.figlio(DES), letter);
        }

        bool strettCres(AlberoB* a){
            vector<char> letter;
            tree(a, letter);
            for(int i = 0; i < letter.size() - 1; i++){
                if(letter[i] >= letter[i + 1]) return false;
            }
            return true;
        }
};
