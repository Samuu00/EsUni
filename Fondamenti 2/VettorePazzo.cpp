#include <iostream>
#include <vector>
using namespace std;

class VettorePazzo : public vector<unsigned> {
    private:
        unsigned numeroPazzo;
    
    public:
        VettorePazzo(unsigned n){
            numeroPazzo = n;
        }

        void aggiungi(unsigned num){
            if(num == numeroPazzo || num % numeroPazzo == 0) return;
            this->push_back(num);
        }

        bool operator==(VettorePazzo& other){
            return true;
        }

        unsigned operator[](unsigned index){
            return vector<unsigned>::operator[](index);
        }

        bool operator<(VettorePazzo& other){
            if(numeroPazzo < other.numeroPazzo) return true;
            return false;
        }
};

int main() {
    VettorePazzo v1(3);
    v1.aggiungi(5);   
    v1.aggiungi(6);  
    v1.aggiungi(7);   
    v1.aggiungi(3);   

    VettorePazzo v2(3);
    v2.aggiungi(5);
    v2.aggiungi(7);

    cout << "v1[0] = " << v1[0] << "\n"; 
    cout << "v1[1] = " << v1[1] << "\n"; 

    if (v1 == v2) cout << "v1 e v2 sono uguali\n";
    else cout << "v1 e v2 sono diversi\n";

    VettorePazzo v3(5);
    if (v1 < v3) cout << "v1 < v3\n";
    else cout << "v1 >= v3\n";

    return 0;
}