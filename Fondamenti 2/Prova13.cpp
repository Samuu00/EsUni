#include <iostream>
#include <list>
#include <queue>
using namespace std;

//es2
class Item{
    private:
        string nome;
        
    public:
        Item(string n): nome(n) {}

        string getNome(){ return nome; }

        virtual int getValore() const = 0;

        virtual int getPeso() const = 0;

        virtual ~Item() {}
};

class Pozione : public Item{
    private:
        int cura;

    public:
        Pozione(string n, int c): Item(n), cura(c){}

        int getValore() const override{ return cura * 2; }

        int getPeso() const override{ return 1; }
};

class Arma : public Item{
    private:
        int danno;
        int pesoArma;

    public:
        Arma(string n, int d, int pa): Item(n), danno(d), pesoArma(pa) {}

        int getValore() const override { return danno * 10; }

        int getPeso() const override { return pesoArma; }
};

class Inventario{
    private:
        int pesoMax;
        list<Item*> inventario;
    
    public:
        Inventario(int pm): pesoMax(pm){}

        ~Inventario(){
            auto it = inventario.begin();

            for(; it != inventario.end(); it++){

                delete *it;
            }
        }

        bool addItem(Item* item){
            auto it = inventario.begin();
            int totCorr = 0;

            for(; it != inventario.end(); it++){

                totCorr += it->getPeso();
            }

            if(totCorr + item->getPeso() > pesoMax) return false;

            inventario.insert(item);

            return true;
        }

        int getValoreTot() const{
            int tot = 0;
            auto it = inventario.begin();

            for(; it != inventario.end(); it++){

                tot += it->getValore();
            } 

            return tot;
        }

        Item* removePrecious(){
            if(inventario.empty()) return nullptr;

            auto it = inventario.begin();
            auto remove = inventario.begin();
            Item* toRemove = *it;

            for(; it != inventario.end(); it++){

                if(it->getValore() > Item->getValore()){
                    toRemove = *it;
                    remove = it;
                }
            }

            inventario.erase(remove);

            return toRemove;
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

        bool isCompleto(AlberoB* a){
            if(nullo(a)) return true;

            queue<AlberoB*> q;
            bool trovato = false;

            q.push(a);

            while(!q.empty()){

                auto curr = q.front(); q.pop();

                q.push(curr.figlio(SIN));
                q.push(curr.figlio(DES));

                if(nullo(curr)) trovato = true;

                if(trovato && !nullo(curr)) return false;

            }

           return true;
        }
};


//es4
bool dfs(string& s, vector<string>& diz){
    if(s.empty()) return true;

    for(const string& p : diz){

        if(s.rfind(p, 0) == 0){

            string suff = s.substr(p.length());
            
            if(dfs(suff, diz)) return true;
        }
    }

    return false;
}

bool workBreak(const string& s, const vector<string>& diz){
    string sCopy = s;

    if(dfs(sCopy, diz)) return true;

    return false;
}