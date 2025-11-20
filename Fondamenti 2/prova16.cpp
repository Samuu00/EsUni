#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

//es2
struct Node {
    int value;
    Node* next;

    Node(int v, Node* n): value(v), next(n){}
};

class Queue {
    private:
        Node* head; 
        Node* tail; 
        int size; 

    public:
        Queue(): head(nullptr), tail(nullptr), size(0) {}
        
        ~Queue(){
            Node* temp = head;
            Node* prev = nullptr;
            while(temp != nullptr){

                prev = temp;
                temp = temp->next;
                delete prev;
            }
        }
        
        void push(int valore){
            if(size == 0){

                Node* newNode = new Node(valore, nullptr);
                head = newNode;
                tail = newNode;
                size++;
                return;
            }

            Node* newNode = new Node(valore, nullptr);
            tail->next = newNode;
            tail = newNode;
            size++;
        }
        
        int pop(){
            if(empty()) throw runtime_error("coda vuota");

            int toReturn = head->value;

            Node* remove = head;
            head = head->next;

            delete remove;
            size--;

            if(empty()) tail = nullptr;

            return toReturn;

        }

        int front() const{
            if(empty()) throw runtime_error("coda vuota");

            int toReturn = head->value;

            return toReturn;
        }
        
        bool empty() const{
            return (size == 0) ? true : false;
        }
};

        
//es3
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

        void dfs(int p, vector<bool>& visitati){
            visitati[p] = true;

            for(int i = 0; i < n(); i++){

                if(adj[p][i] && !visitati[i] && p != i){

                    dfs(i, visitati);
                }
            }
        }

        int contaConnesse(){
            int conn = 0;
            vector<bool> visitati(n(), false);
            for(int i = 0; i < n(); i++){
                
               if(!visitati[i]){
                    dfs(i, visitati);
                    conn++;
               }
                
            }

            return conn;
        }
};