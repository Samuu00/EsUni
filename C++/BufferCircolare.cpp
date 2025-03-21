#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class BufferCircolare {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    BufferCircolare() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

        void Aggiungi(int val){
            Node* nuovoNodo = new Node(val);
            if (!head) { 
                head = tail = nuovoNodo;
                tail->next = head; 
                current = head; 
            } else {
                tail->next = nuovoNodo; 
                tail = nuovoNodo;       
                tail->next = head;    
            }
        }
        void Rimuovi(int val) {
            if (!head) return;
        
            Node* temp = head;
            Node* prev = nullptr;
        
            if (head->data == val) {
                if (head == tail) { 
                    head = tail = current = nullptr;
                    return;
                }
                head = head->next;
                tail->next = head;
                if (current == temp) {
                    current = head;
                }
                delete temp;
                return;
            }
        
            do {
                prev = temp;
                temp = temp->next;
                if (temp->data == val) {
                    prev->next = temp->next;
                    if (temp == tail) {
                        tail = prev; 
                    }
                    if (current == temp) {
                        current = temp->next; 
                    }
                    delete temp;
                    return;
                }
            } while (temp != head);
        }
        
        
        int Corrente(){
            if(current){
                return current->data;
            }
            return -1;
        }
        void Avanza(){
            if(current){
                current = current->next;
            }
        }

};

int main(){
    BufferCircolare bc;
    bc.Aggiungi(8); bc.Aggiungi(4); bc.Aggiungi(2);
    for (int i = 0; i < 10; ++i) {
        cout << bc.Corrente()<<" ";
        bc.Avanza();
    }
    cout<<endl;
    bc.Rimuovi(4);
    for (int i = 0; i < 10; ++i) {
        cout << bc.Corrente()<<" ";
        bc.Avanza();
    }
    return 0;
}