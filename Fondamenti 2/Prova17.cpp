#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
using namespace std;

//es2
struct Node {
    int value;
    int count; 
    Node* next;

    Node(int v, int c, Node* n): value(v), count(c), next(n){}
};

class MultiSet {
    private:
        Node* head;

    public:
        MultiSet(): head(nullptr) {}

        ~MultiSet(){
            Node* temp = head;
            Node* prev = nullptr;

            while(temp != nullptr){

                prev = temp;
                temp = temp->next;
                delete prev; 

            }
        }
        
        void insert(int val){
            if (head == nullptr || val < head->value) {

                head = new Node(val, 1, head);
                return;
            }

            if (head->value == val) {

                head->count++;
                return;
            }

            Node* current = head;
            while (current->next != nullptr && current->next->value < val) {

                current = current->next;
            }

            if (current->next != nullptr && current->next->value == val) {

                current->next->count++;

            } else {
                
                current->next = new Node(val, 1, current->next);
            }
        }

        bool remove(int val){
            if(head == nullptr) throw runtime_error("Lista vuota");

            if(head->value == val){
                
                head->count--;

                if(head->count == 0){

                    Node* toDelete = head;
                    head = head->next;
                    delete toDelete;
                }

                return true;
            }

            Node* temp = head;
            Node* prev = nullptr;
            while(temp != nullptr){

                if(temp->value == val){

                    temp->count--;
                    
                    if(temp->count == 0){

                        Node* toDelete = temp;
                        prev->next = temp->next;
                        delete toDelete;
                        return true;
                    }

                    return true;
                }

                prev = temp;
                temp = temp->next;
            }

            return false;
        }
        
        int count(int val) const {
            Node* temp = head;
            while(temp != nullptr){

                if(temp->value == val) return temp->count;

                temp = temp->next; 
            }

            return -1;
        }

        int size() const {
            int size = 0;
            Node* temp = head;
            while(temp != nullptr){

                size += 1 * temp->count;
                temp = temp->next;
            }

            return size;
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

        bool isSimmetrico(AlberoB* a, AlberoB* b){
            if(nullo(a) && nullo(b)) return true;
            if(nullo(a) || nullo(b)) return false;

            if(a->radice() != b->radice()) return false;

            return isSimmetrico(a->figlio(SIN), b->figlio(DES)) && isSimmetrico(a->figlio(DES), b->figlio(SIN));
        }
};


//es4
class Grafo {
    private:
        int numNodi;
        int numArchi;
        vector<vector<bool>> adj;

    public:
        Grafo(int n) : numNodi(n), numArchi(0), adj(n, vector<bool>(n, false)) {}

        int n() const {
            return numNodi;
        }
        int m() const {
            return numArchi;
        }

        void aggiungiArco(int i, int j) {
            if (i < 0 || j < 0 || i >= numNodi || j >= numNodi) throw out_of_range("Indice nodo non valido");
            if (!adj[i][j]) {
                adj[i][j] = true;
                adj[j][i] = true;
                numArchi++;
            }
        }

        bool isBipartito(){
            queue<int> q;
            vector<int> colori(n(), -1);
            
            for(int i = 0; i < n(); i++){

                if(colori[i] != -1) continue;

                q.push(i);
                colori[i] = 0;
                while(!q.empty()){

                    int curr = q.front(); q.pop();

                    for(int j = 0; j < n(); j++){

                        if(adj[curr][j] && curr != j){

                            if(colori[curr] == colori[j]) return false;

                            if(colori[j] == -1){

                                if(colori[curr] == 0) colori[j] = 1;
                                if(colori[curr] == 1) colori[j] = 0;

                                q.push(j);
                            }

                        }

                    }
                }
            }

            return true;
        }
};

//es4

