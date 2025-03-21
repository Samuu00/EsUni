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

class FakeList {
private:
    Node* head;
public:
    FakeList() {
        head = nullptr;
    }

    void insert(int el) {
        Node* newNode = new Node(el);
        newNode->next = head;
        head = newNode;
    }

    void getFakeSize() {
        Node* temp = head;
        int length = 0;
        while (temp != nullptr) {
            length += 1;
            temp = temp->next;
        }
        cout << length * 2 << endl;
    }

    void FakeSort(string s) {
        if (!head) return; 

        bool swapped;
        do {
            swapped = false;
            Node* ptr1 = head;
            while (ptr1 != nullptr && ptr1->next != nullptr) {
                if (s == "true" && ptr1->data > ptr1->next->data) { 
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                } else if (s == "false" && ptr1->data < ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
        } while (swapped); 
    }

    void fakeClear(string c) {
        if (c == "true") {
            cout << "Cancellazione avviata..." << endl;
            Node* temp = head;
            while (temp != nullptr) {
                cout << "Cancellando nodo: " << temp->data << endl; 
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
            head = nullptr; 
            cout << "Cancellazione completata!" << endl;
        } else {
            cout << "Cancellazione saltata perche c = false." << endl;
        }
    }

    void stampaLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "FINE" << endl;
    }
};

int main() {
    FakeList fl;
    int n;
    cout << "Inserisci numero di elementi: ";
    cin >> n;
    int el;
    for (int i = 0; i < n; i++) {
        cin >> el;
        fl.insert(el);
    }

    fl.getFakeSize();
    cout << "Ecco la linked list: " << endl;
    fl.stampaLinkedList();

    string c;
    cout << "Inserisci (true/false) per ordinare la linked list in modo crescente o decrescente: " << endl;
    cin >> c;

    fl.FakeSort(c);
    cout << "Linked list ordinata: " << endl;
    fl.stampaLinkedList();

    string s;
    cout << "Inserisci (true/false) per cancellare o no la linked list: " << endl;
    cin >> s;

    fl.fakeClear(s);
    cout << "Linked list ripulita: " << endl;
    fl.stampaLinkedList();
}

