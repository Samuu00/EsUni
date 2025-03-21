#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }

        void InsertAtHead(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        void printList(){
            Node* temp = head;
            while(temp != nullptr){
                cout<< temp->data << "->";
                temp = temp->next;
            }
            cout<<"FINE"<<endl;
        }
        void deleteNode(int val){
            if (head == nullptr) return;

            if (head->data == val) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data != val) {
                temp = temp->next;
            }
            if (temp->next != nullptr) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
        }  
        int getLength() {
            int length = 0;
            Node* temp = head;
            while (temp) {
                length++;
                temp = temp->next;
            }
            return length;
        }
    
        int getNthFromEnd(int N) {
            int length = getLength();
            if (N > length){ 
                return -1; 
            }
            
            int targetPos = length - N;
            Node* temp = head;
            while (targetPos--) {
                temp = temp->next;
            }
            return temp->data;
        } 
        void rimuoviDuplicato(){
            Node* temp = head;
            while (temp != nullptr && temp->next != nullptr){
                if(temp->data == temp->next->data){
                    Node* nodoDuplicato = temp->next;
                    cout<<"Nodo con valore duplicato: " << temp->data << " eliminato"<<endl;
                    temp->next = temp->next->next;
                    delete nodoDuplicato;
                } else{
                    temp = temp->next;
                }
                
            }
        }

        
};

int main(){
    LinkedList list;
    int n;
    cout<<"Inserisci quanti elementi aggiungere nella linked list: ";
    cin>> n;
    for(int i = 0; i < n; i++){
        int v;
        cout<<"Inserisci valore da inserire nella linked list: ";
        cin>>v;
        list.InsertAtHead(v);
    }
    list.printList();
    int N;
    cout<<"Inserisci quale valore tra quelli inseriti vuoi trovare: ";
    cin>> N;
    int result = list.getNthFromEnd(N);
    if (result != -1){
        cout << "Il " << N << "-esimo nodo dalla fine e: " << result << endl;
    }else{
        cout << "Errore: N è troppo grande!" << endl;
    }
    
    list.rimuoviDuplicato();
    list.printList();

    return 0;
}

    