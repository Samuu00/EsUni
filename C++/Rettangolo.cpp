#include <iostream>
using namespace std;

class Rettangolo{
    private:
        double altezza, larghezza;
    public:
        Rettangolo(){
            altezza = 1.0;
            larghezza = 1.0;
        }
        Rettangolo(Rettangolo& r){
            altezza = r.altezza;
            larghezza = r.larghezza;
        }
        Rettangolo(double alt, double largh){
            altezza = alt;
            larghezza = largh;
        }

        void setAltezza(double alt){
            altezza = alt;
        }
        void setLarghezza(double largh){
            larghezza = largh;
        }

        double getAltezza(){
            return altezza;
        }
        double getLarghezza(){
            return larghezza;
        }
        double getArea(){
            return altezza*larghezza;
        }
        double getPerimetro(){
            return (2*altezza) + (2*larghezza);
        }
};

int main(){
    Rettangolo* rettangolo = new Rettangolo[1];
    double alt, largh;
    cout<<"Inserisci altezza e larghezza: "<<endl;
    cin>> alt >> largh;
    rettangolo[0] = Rettangolo(alt, largh);
    cout<< "Area del rettangolo: " << rettangolo[0].getArea() << ", " << "Perimetro del rettangolo: " << rettangolo[0].getPerimetro();
}