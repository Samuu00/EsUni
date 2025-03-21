#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList{
    public:
        Node* head;
        DoublyLinkedList(){
            head = nullptr;
        }

        void InsertAtHead(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode; 
            }
            head = newNode;
        }

        void printListForWard(){
            Node* temp = head;
            while(temp != nullptr){
                cout<< temp->data << "->";
                temp = temp->next;
            }
            cout<<"FINE"<<endl;
        }

        void mergeLinkedList(DoublyLinkedList& other) {
            if (!head) { 
                head = other.head;
                other.head = nullptr;
                return;
            }
            if (!other.head) { 
                return;
            }
        
            Node* temp1 = head;
            Node* temp2 = other.head;
            Node* mergedHead = nullptr;
            Node* mergedTail = nullptr;
        
            if (temp1->data > temp2->data) {
                mergedHead = temp1;
                temp1 = temp1->next;
            } else {
                mergedHead = temp2;
                temp2 = temp2->next;
            }
            mergedTail = mergedHead;
        
            while (temp1 && temp2) {
                if (temp1->data > temp2->data) {
                    mergedTail->next = temp1;
                    temp1->prev = mergedTail;
                    temp1 = temp1->next;
                } else {
                    mergedTail->next = temp2;
                    temp2->prev = mergedTail;
                    temp2 = temp2->next;
                }
                mergedTail = mergedTail->next;
            }
        
            if (temp1) {
                mergedTail->next = temp1;
                temp1->prev = mergedTail;
            }
            if (temp2) {
                mergedTail->next = temp2;
                temp2->prev = mergedTail;
            }
        
            head = mergedHead;
            other.head = nullptr;
        }
        
        
};

int main(){
    DoublyLinkedList list1, list2;
    int n;
    cout<<"Inserisci quanti elementi aggiungere nella linked list: ";
    cin>> n;
    cout<<"Inserisci valore da inserire nella linked list 1: "<<endl;
    for(int i = 0; i < n; i++){
        int l1;
        cin>>l1;
        list1.InsertAtHead(l1);
    }
    cout<<"Inserisci valore da inserire nella linked list 2: "<<endl;
    for(int i = 0; i < n; i++){
        int l2;
        cin>>l2;
        list2.InsertAtHead(l2);
    }
        list1.printListForWard();
        list2.printListForWard();
        list1.mergeLinkedList(list2);
        list1.printListForWard();
        return 0;
}

