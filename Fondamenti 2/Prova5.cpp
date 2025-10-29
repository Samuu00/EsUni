#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

//es2
class Notifica{
    private:
        string mittente;
    
    public:
        Notifica(const string& m): mittente(m) {}

        string getMittente() const { return mittente; }

        virtual int getPriorita() const = 0;
        
        virtual string getContenuto() const = 0;

        virtual ~Notifica() {}
};

class Email : public Notifica{
    private:
        string oggetto;
    
    public:
        Email(const string& m, const string& ogg): Notifica(m), oggetto(ogg) {}

        int getPriorita() const override { return 1; }

        string getContenuto() const override { return oggetto; }
};

class SMS: public Notifica{
    private:
        string testo;
    
    public:
        SMS(const string& m, const string& t): Notifica(m), testo(t) {}

        int getPriorita() const override { return 5; }

        string getContenuto() const override { return testo; }
};

class Allarme: public Notifica{
    private:
        int codiceErr;
    
    public:
        Allarme(const string& m, const int& cod): Notifica(m), codiceErr(cod) {}

        int getPriorita() const override { return 10; }

        string getContenuto() const override { return "Allarme codice: " + to_string(codiceErr); }
};

class GestoreNotifiche{
    private:
        list<Notifica*> messaggi;
    
    public:
        GestoreNotifiche() {}

        void inviaNotifica(Notifica* n){
            auto it = messaggi.begin();

            while(it != messaggi.end() && it->getPriorita() < n->getPriorita()){
                it++;
            }

            messaggi.insert(it, n);
        }

        Notifica* processaPross(){
            if(messaggi.empty()) return nullptr;

            Notifica* n = messaggi.front();
            messaggi.pop_front();

            return n;
        }

        vector<Notifica*> getNotificheSottoPrior(int n){
            vector<Notifica*> notifiche;

            for(auto& it : messaggi){
                if(it->getPriorita() < n) notifiche.push_back(it);
            }
            
            return notifiche;
        }

        ~GestoreNotifiche() {
            for(auto& it : messaggi){
                delete it;
            }
        }
};


//es3
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

        int somma(AlberoB* a){
            if(nullo(a)) return 0;

            return a.radice() + somma(a.figlio(SIN)) + somma(a.figlio(DES));
        }
        
        bool isBilanciato(AlberoB* a, int k){
            if(nullo(a)) return true;

            int sommaS = somma(a.figlio(SIN));
            int sommaD = somma(a.figlio(DES));

            if(abs(sommaS - sommaD) > k) return false;

            return isBilanciato(a.figlio(SIN), k) && isBilanciato(a.figlio(DES), k);

        }
};