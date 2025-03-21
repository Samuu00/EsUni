#include <iostream>
using namespace std;

class Animale{
    public:

        virtual void verso(){
            cout<<"L'animale ha fatto il verso: ";
        }

        virtual ~Animale() {}
};

class Cane : public Animale{
    public:
        void verso() override{
            cout<<"Woof!"<<endl;
        }
};
class Gatto : public Animale{
    public:
        void verso() override{
            cout<<"Miau!"<<endl;
        }
};

int main(){
    int n;
    cout<<"Inserisci quanti animali aggiungere: ";
    cin>> n;
    Animale* animali[n];
    for(int i = 0; i < n; i++){
        string s;
        cout<<"Inserisci -cane per inserire un cane, altrimenti -gatto per inserire un gatto: ";
        cin>> s;
        if (s == "cane"){
            animali[i] = new Cane();
        }
        else if (s == "gatto"){
            animali[i] = new Gatto();
        }
    }
    for(int i = 0; i < n; i++){
        animali[i]->verso();
    }
    for(int i = 0; i < n; i++){
        delete animali[i];
    }
    return 0;
}