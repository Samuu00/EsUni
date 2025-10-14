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

        bool cammino(AlberoB* a, vector<int>& cammino, int x){
            if(nullo(a)) return false;

            cammino.push_back(a.radice());

            if(a.foglia() && a.radice() == x) return true;

            if(cammino(a.figlio(SIN), cammino, x)) return true;
            if(cammino(a.figlio(DES), cammino, x)) return true;

            cammino.pop_back();
            return false;
        }

        vector<int> tornaCammino(AlberoB* a, int x){
            vector<int> path;
            if(cammino(a, path, x)) return path;
            return {-1};
        }
    
};
