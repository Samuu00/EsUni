#include <string>
#include <vector>
using namespace std;


//es2
struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, string v, Node* n): key(k), value(v), next(nullptr) {}
};

class HashMap {
    private:
        Node** data;  
        int capacita; 
        int size;    

        int hashFunction(int key) const {
            return key % capacita;
        }
        
        void resize(){
            if(size == capacita){

                int oldSize = this->capacita;
                Node** oldData = data;

                int newSize = this->capacita * 2;
                this->capacita = newSize;

                Node** newData = new Node*[newSize];
                data = newData;
                this->size = 0;
                for(int i = 0; i < newSize; i++){

                    newData[i] = nullptr;
                }

                for(int j = 0; j < oldSize; j++){

                    Node* temp = data[j];
                    while(temp != nullptr){

                        put(temp->key, temp->value);
                    }
                }

                delete[] oldData;
            }
        }

    public:
        HashMap(): size(0), capacita(10){
            this->data = new Node*[this->capacita];
            for(int i = 0; i < capacita; i++){

                data[i] = nullptr;
            }
        }
        
        ~HashMap(){
            for(int i = 0; i < capacita; i++){

                Node* temp = data[i];
                while(temp != nullptr){

                    Node* prev = temp;
                    temp = temp->next;
                    delete prev;
                }
            }

            delete[] data;
        }
        
        void put(int key, const string& value){
            if(size == capacita) resize();

            int hashKey = hashFunction(key);

            Node* temp = data[hashKey];
            while(temp != nullptr){

                if(temp->key == key){

                    temp->value = value; 
                    return;
                }

                temp = temp->next;
            }

            Node* newNode = new Node(key, value, data[hashKey]);
            data[hashKey] = newNode;
            size++;
        }
        
        string get(int key) const{
            int hashKey = hashFunction(key);

            Node* temp = data[hashKey];
            while(temp != nullptr){

                if(temp->key == key) return temp->value;
                temp = temp->next;
            }

            return "";
        }
        
        bool remove(int key){
            int hashKey = hashFunction(key);

            Node* temp = data[hashKey];
            Node* prev = nullptr;

            while(temp != nullptr){

                if(temp->key == key){

                    if(prev == nullptr){

                        data[hashKey] = temp->next;

                    }else{

                        prev->next = temp->next;
                    }

                    delete temp;
                    size--;
                    return true;

                } 

                prev = temp;
                temp = temp->next;

            }
            
            return false;
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

        AlberoB* potaFoglie(AlberoB* a){
            if(nullo(a)) return nullptr;

            a->sx = potaFoglie(a->figlio(SIN));
            a->dx = potaFoglie(a->figlio(DES));

            if(a->foglia()){
                delete a;
                return nullptr;
            }

            return a;
        }
};


//es4
struct Giocatore{
    int costo;
    int valore;

    Giocatore(int c, int v): costo(c), valore(v) {}
};

int dfs(int& k, int& budget, int numGioc, int cost, const vector<Giocatore>& giocatori, int indexGioc, int valore){

    if(numGioc == k){

        if(cost <= budget){

            return 0;

        }else{

            return -1;

        }
    }

    if(indexGioc == giocatori.size()) return -1;

    int non_prendendo = dfs(k, budget, numGioc + 1, cost, giocatori, indexGioc + 1, valore);

    int prendendo = -1;
    int newCosto = cost + giocatori[indexGioc].costo;

    if(newCosto <= budget){
        
        int rprend = dfs(k, budget, numGioc + 1, newCosto, giocatori, indexGioc + 1, valore);

        if(rprend != -1) prendendo = giocatori[indexGioc].valore + rprend;
    } 

    return max(prendendo, non_prendendo);

}

int maxValoreSquadra(int k, int budget, const vector<Giocatore>& giocatori){
    int maxCost = dfs(k, budget, 0, 0, giocatori, 0, 0);

    if(maxCost < 0) return 0;
    return maxCost;
}