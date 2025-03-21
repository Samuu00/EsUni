#include <iostream>
using namespace std;    

class Forma{
    public:
        virtual double calcolaArea() = 0;
        virtual void stampa() = 0;
        virtual ~Forma() {}
};

class Rettangolo : public virtual Forma{
    private:
        double base, altezza;
    public:
        Rettangolo(){
            base = 0.0;
            altezza = 0.0;
        }
        Rettangolo(Rettangolo& r){
            base = r.base;
            altezza = r.altezza;
        }
        Rettangolo(double b, double h){
            base = b;
            altezza = h;
        }

        void setBase(double b){
            base = b;
        }
        void setAltezza(double a){
            altezza = a;
        }

        double getBase(){
            return base;
        }
        double getAltezza(){
            return altezza;
        }

        double calcolaArea() override {
            return base*altezza;
        }
        void stampa() override {
            cout<<"Area del rettangolo: " << calcolaArea()<<endl;
        }
};
class Cerchio : public virtual Forma{
    private:
        double raggio;
    public:
        Cerchio(){
            raggio = 0.0;
        }
        Cerchio(Cerchio& c){
            raggio = c.raggio;
        }
        Cerchio(double r){
            raggio = r;
        }

        void setRaggio(double r){
            raggio = r;
        }
        double getRaggio(){
            return raggio;
        }

        double calcolaArea() override {
            return 3.14 * raggio * raggio;
        }
        void stampa() override {
            cout<<"Area del cerchio: " << calcolaArea()<<endl;
        }
};

int main(){
    int n;
    cout<<"Inserisci quante forme vuoi aggiungere: ";
    cin>> n;
    Forma* forme[n];
    for(int i = 0; i < n; i++){
        cout<<"Inserisci quale forma inserire (rettangolo/cerchio): ";
        string f;
        cin >> f;
        if(f == "rettangolo"){
            double b, h;
            cout<<"Inserisci misura di base e altezza: "<<endl;
            cin>> b >> h;
            forme[i] = new Rettangolo(b, h);
        }
        else if(f == "cerchio"){
            double r;
            cout<<"Inserisci misura del raggio: ";
            cin>> r;
            forme[i] = new Cerchio(r);
        }
    }
    for(int i = 0; i < n; i++){
        forme[i]->calcolaArea();
    }
    for(int i = 0; i < n; i++){
        forme[i]->stampa();
    }
    for(int i = 0; i < n; i++){
        delete forme[i];
    }
    return 0;
}